#include "draw_actors.h"
#include "output_service.h"
#include "cast.h"
#include <iostream>
#include <memory>
import constants;
using constants::CENTER_X;
using constants::CENTER_Y;
using constants::MAX_X;
using constants::MAX_Y;
using std::vector;
using draw_actors::DrawActors;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;

void DrawActors::run() {
	output_service->clearBuffer();
	ActorPtr cameraPtr = output_service->getCamera();
	Point camera = cameraPtr->getPosition();
	int draw_y = CENTER_Y - 1 - (camera.y - CENTER_Y) - 10;
	int offset = draw_y - CENTER_Y;
	DrawRectangle(0, draw_y, MAX_X - 1, CENTER_Y - 1 - offset, ORANGE);
	//	DrawRectangle(0, CENTER_Y, MAX_X - 1, CENTER_Y - 1, ORANGE);

	draw("habitat");
	draw("grass");
	draw("green_house");
	draw("grass_pile");
	draw("captain");
	draw("holo_disk");
	draw("player");

	output_service->flushBuffer();
}
void DrawActors::draw(string group) {
	vector<ActorPtr> actors = cast->getActors(group);
	for (auto& actor : actors)
		actor->draw(output_service);
}
/*void DrawActors::run() {	// Draw Order System? Discuss with team
	output_service->clearBuffer();

	vector<string> drawOrder = {
		"grass",
		"player"
	};
	drawOrdered(drawOrder);
	drawUnordered(drawOrder);

	output_service->flushBuffer();
}
void DrawActors::drawOrdered(vector<string>& drawOrder) {
	for (auto& group : drawOrder)
		draw(group);
}
void DrawActors::drawUnordered(vector<string>& drawOrder) {

}*/
	/*ActorPtr player = cast.getFirstActor("players");
if (!player)		// Old code. Check if there is a player. Seems weird, just pretend player is a pointer. Optionals behave somewhat like pointers. It is as described here: https://arne-mertz.de/2018/06/modern-c-features-stdoptional/
	return;*/

