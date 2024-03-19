#ifndef SCREEN_H_
#define SCREEN_H_

#include "Resolution/Resolution.h"

#include "States/ScreenStates.h"

#include <memory>

namespace Screen
{
	class FeaturesScreen
	{
	public:
		[[nodiscard]] Resolution resolution_screen() const noexcept;
	private:
		ScreenState& state;
	};

	extern std::unique_ptr<FeaturesScreen> features_screen;
}

#endif // !SCREEN_H_
