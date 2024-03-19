#include "Screen.h"

namespace Screen
{
	std::unique_ptr<FeaturesScreen> features_screen;

	[[nodiscard]] Resolution FeaturesScreen::resolution_screen() const noexcept
	{
		return Resolution{ state.resolution_state };
	}
}