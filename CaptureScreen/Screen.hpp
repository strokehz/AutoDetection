#ifndef SCREEN_H_
#define SCREEN_H_

#include "Resolution/Resolution.hpp"

#include "States/ScreenStates.hpp"

#include <memory>

namespace Screen
{
	class FeaturesScreen
	{
	public:
		[[nodiscard]] Resolution resolution_screen() noexcept;

		[[nodiscard]] ScreenState states() noexcept;
	private:
		ScreenState state;
	};

	extern std::unique_ptr<FeaturesScreen> features_screen;
}

#endif // !SCREEN_H_
