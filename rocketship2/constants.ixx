#include <iostream>

export module constants;

namespace constants {
	using std::string;

	export constexpr int MAX_X = 1500;
	export constexpr int MAX_Y = 900;
	export constexpr int CENTER_X = 750;
	export constexpr int CENTER_Y = 450;
	export constexpr int GROUND_Y = 450;
	export constexpr int GRAVITY = 2000;	//Gravity is 2,000 pixels per second per second acceleration downward
	export constexpr int FRAME_RATE = 60;
	export const string TITLE = "Captain";
	export const string IMAGE_PATH = "images";
}
