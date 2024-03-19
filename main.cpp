#include "CaptureScreen/Screen.hpp"

#include <Windows.h>
#include <iostream>

int main()
{
	Screen::features_screen = std::make_unique<Screen::FeaturesScreen>();

	auto get_screen = Screen::features_screen->resolution_screen();



	Sleep(-1);
}