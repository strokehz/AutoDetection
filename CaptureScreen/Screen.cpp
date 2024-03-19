#include "Screen.hpp"

namespace Screen
{
	std::unique_ptr<FeaturesScreen> features_screen;

	[[nodiscard]] Resolution FeaturesScreen::resolution_screen() noexcept
	{
		return Resolution{ state.resolution_state };
	}

	[[nodiscard]] ScreenState FeaturesScreen::states() noexcept
	{
		return state;
	}
}