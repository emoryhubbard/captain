#pragma once
#include "action.h"
#include "cast.h"
#include <iostream>

class OutputService;
namespace draw_actors {
	using cast::Cast;
	using std::string;
class DrawActors : public Action {
	private:
		void draw(string group);
	public:
		void run();
	};
}



