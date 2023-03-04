#include "control_player.h"
#include "input_service.h"
#include "player.h"

void ControlPlayer::ControlPlayer::run() {
	setDirection();
	setVelocity();
}
void ControlPlayer::ControlPlayer::setDirection() {
	int x = 0, y = 0;

	if (isDown("a")) x = -1;
	if (isDown("d")) x = 1;
	if (isDown("w")) y = -1;
	if (isDown("s")) y = 1;

	actor("player")->setDirection(x, y);
}
void ControlPlayer::ControlPlayer::setVelocity() {
	double x = 0;
	double y = actor("player")->getVelocity().y;
	double speed = actor("player")->getSpeed();

	Player* player = dynamic_cast<Player*>(&(*actor("player")));
	double jump = player->jumpVelocity;

	if (isUp("a")) x = 0;
	if (isUp("d")) x = 0;
	if (isDown("a")) x = -speed;
	if (isDown("d")) x = speed;

	if (isDown("w")) y = jump;
	
	actor("player")->setVelocity(x, y);
}




/*
Test function for setDirection()

	//std::cout << x << " " << y << "\n";
*/