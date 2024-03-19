#ifndef RESOLUTION_H_
#define RESOLUTION_H_

#include "States/ResolutionStates.hpp"

#include <utility>

namespace Screen
{
	class Resolution
	{
	public:
		Resolution(ResolutionState& state_);

		std::pair<int, int> run();

		bool has_resolution_changed() noexcept;

		[[nodiscard]] short get_count_monitor() noexcept;
		[[nodiscard]] short get_width() noexcept;
		[[nodiscard]] short get_height() noexcept;
	private:
		ResolutionState& state;
	};
}

#endif // !RESOLUTION_H_
