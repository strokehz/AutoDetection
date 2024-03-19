#include "CaptureScreen/Screen.h"

int main()
{
	Screen::features_screen = std::make_unique<Screen::FeaturesScreen>();

	return 1;
}