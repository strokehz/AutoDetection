#include "Resolution.hpp"

#include <Windows.h>

namespace Screen
{
	Resolution::Resolution(ResolutionState& state_) : state(state_)
	{
		state.count_monitor = GetSystemMetrics(SM_CMONITORS);
	}

	std::pair<int, int> Resolution::run() // обновлять когда срабатывает автодетект
	{
		if (!state.enabled)
			return { 0,0 };

		HMONITOR handle = MonitorFromWindow(GetActiveWindow(), MONITOR_DEFAULTTOPRIMARY);
		if (!handle)
			return { -1, -1 };

		MONITORINFOEX monitor_information;
		ZeroMemory(&monitor_information, sizeof(monitor_information));
		monitor_information.cbSize = sizeof(monitor_information);

		if (!GetMonitorInfo(handle, &monitor_information))
		{
			DeleteObject(handle);
			return { 0,0 };
		}

		DEVMODEA monitor_settings;
		ZeroMemory(&monitor_settings, sizeof(monitor_settings));
		monitor_settings.dmSize = sizeof(monitor_settings);
		monitor_settings.dmDriverExtra = 0;

		if (!EnumDisplaySettings(monitor_information.szDevice, ENUM_CURRENT_SETTINGS, &monitor_settings))
		{
			DeleteObject(handle);
			ZeroMemory(&monitor_information, sizeof(monitor_information));
			return { 0,0 };
		}

		if (this->state.x < 1 || this->state.y < 1)
		{
			this->state.x = monitor_settings.dmPelsWidth;
			this->state.y = monitor_settings.dmPelsHeight;
		}

		ZeroMemory(&monitor_information, sizeof(monitor_information));
		DeleteObject(handle);

		return std::make_pair(monitor_settings.dmPelsWidth, monitor_settings.dmPelsHeight);
	}

	bool Resolution::has_resolution_changed() noexcept
	{
		auto xy = run();

		if (xy.first != this->state.x || xy.second != this->state.y) {
			this->state.x = xy.first;
			this->state.y = xy.second;
			return true;
		}

		return false;
	}

	[[nodiscard]] short Resolution::get_width() noexcept
	{
		return this->state.x;
	}

	[[nodiscard]] short Resolution::get_height() noexcept
	{
		return this->state.y;
	}

	[[nodiscard]] short Resolution::get_count_monitor() noexcept
	{
		return this->state.count_monitor;
	}
}