#include "actor.h"
#include "output_service.h"
#include "raylib.h"
#include <memory.h>
#include <iostream>
using constants::MAX_X;
using constants::MAX_Y;
using constants::CENTER_X;
using constants::CENTER_Y;
using std::string;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;

Actor::Actor() {
	text = "Test";
	font_size = 15;
	color = BLUE;
	texture = "";
	width = 0;
	height = 0;
	speed = 0;
	position = Point(0, 0);
	velocity = Point(0, 0);
	acceleration = Point(0, 0);
	direction = Point(0, 0);
	setPosition(CENTER_X, CENTER_Y);
}
string Actor::getText() {
	return text;
}
int Actor::getFontSize() {
	return font_size;
}
Color Actor::getColor() {
	return color;
}
void Actor::setSpeed(double speed) {
	this->speed = speed;
}
double Actor::getSpeed() {
	return speed;
}
void Actor::setPosition(double x, double y) {
	position.x = x, position.y = y;
}
Point& Actor::getPosition() {
	return position;
}
void Actor::update(double delta_time) {
	updateVelocity(delta_time);
	updatePosition(delta_time);
}
void Actor::updatePosition(double delta_time) {
	double x = position.x + velocity.x * delta_time;
	double y = position.y + velocity.y * delta_time;
	position.x = x;
	position.y = y;
}
Point Actor::predictPosition(double delta_time) {
	double x = position.x + velocity.x * delta_time;
	double y = position.y + velocity.y * delta_time;
	return Point(x, y);
}
void Actor::setVelocity(double x, double y) {
	velocity.x = x, velocity.y = y;
}
Point& Actor::getVelocity() {
	return velocity;
}
void Actor::updateVelocity(double delta_time) {
	double x = velocity.x + acceleration.x * delta_time;
	double y = velocity.y + acceleration.y * delta_time;
	velocity.x = x;
	velocity.y = y;
}
void Actor::setAcceleration(double x, double y) {
	acceleration.x = x, acceleration.y = y;
}
Point& Actor::getAcceleration() {
	return acceleration;
}
void Actor::setDirection(double x, double y) {
	direction.x = x, direction.y = y;
}
Point& Actor::getDirection() {
	return direction;
}
void Actor::setColor(int r, int g, int b) {
	color = Color(r, g, b);
}
void Actor::draw(OutputService* output_service) {
	ActorPtr cameraPtr = output_service->getCamera();
	Point camera = cameraPtr->getPosition();
	texture = this->texture;
	if (speed == 500) {
		if (direction.x == 1)
			texture = "images\\right1.png";
		if (direction.x == -1)
			texture = "images\\left1.png";
	}

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
}
bool Actor::equals(ActorPtr other) {
	return this == &(*other);
}


//copy utility here, not complicated
void Actor::copyTo(std::shared_ptr<Actor> copy) {
	copy->text = this->text;
	copy->font_size = this->font_size;
	copy->color = GetColor(ColorToInt(this->color));
	copy->texture = this->texture;
	copy->width = this->width;
	copy->height = this->height;
	copy->speed = this->speed;
	copy->position.x = this->position.x;
	copy->position.y = this->position.y;
	copy->velocity.x = this->velocity.x;
	copy->velocity.y = this->velocity.y;
	copy->acceleration.x = this->acceleration.x;
	copy->acceleration.y = this->acceleration.y;
}




/*
Test functions.
updateVelocity()
	std::cout << x << " " << y << "\n";
updatePosition()
	//std::cout << position.x << " " << velocity.x << " " << delta_time << "\n";
	//std::cout << velocity.x * delta_time << "\n";
	<rest of method>
	//std::cout << position.x << " " << position.y << "\n";
draw()
	//std::cout << text << "\n";
	//std::cout << position.x << " " << position.y << "\n";


*/