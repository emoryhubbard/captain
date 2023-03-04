#include "player.h"
#include "output_service.h"
#include <memory>
import constants;
using constants::GROUND_Y;
using constants::GRAVITY;
using ActorPtr = std::shared_ptr<Actor>;
using constants::MAX_X;
using constants::MAX_Y;
using constants::CENTER_X;
using constants::CENTER_Y;

Player::Player() : Actor() {
	text = "";
	texture = "images\\right1.png";
	width = 100;
	height = 100;
	speed = 500;
	jumpVelocity = -500;	//negative because upward is less y, equal to 500 pixels per second upward
	acceleration.y = GRAVITY;
}
void Player::update(double delta_time) {
	updateVelocity(delta_time);
	if (predictPosition(delta_time).y > GROUND_Y) {
		setVelocity(velocity.x, 0);
		setPosition(position.x, GROUND_Y);
	}
	updatePosition(delta_time);
}
/*void Actor::draw(OutputService* output_service) {
	ActorPtr cameraPtr = output_service->getCamera();
	Point camera = cameraPtr->getPosition();
	texture = this->texture;
	if (direction.x == 1)
		texture = "images\\right1.png";
	if (direction.x == -1)
		texture = "images\\left1.png";

	if (this->equals(cameraPtr)) {		//if this is the camera, draw it in the center
		if (text.size() != 0)
			output_service->drawText(text, CENTER_X,
				CENTER_Y - height, font_size, color);
		if (texture.size() != 0)
			output_service->drawTexture(texture,
				CENTER_X, CENTER_Y - height);
		return;
	}									//naively, you would try position.x - camera.x, and you will find out that it doesn't quite work as expected and realize this is the right way.
	int draw_x = position.x - (camera.x - CENTER_X);
	int draw_y = position.y - (camera.y - CENTER_Y) - height;

	if (text.size() != 0)
		output_service->drawText(text, draw_x, draw_y,
			font_size, color);
	if (texture.size() != 0)
		output_service->drawTexture(texture, draw_x, draw_y);
}*/

