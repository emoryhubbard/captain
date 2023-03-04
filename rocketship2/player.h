#pragma once
#include "actor.h"

class Player : public Actor {
public:
	double jumpVelocity;
	Player();
	void update(double delta_time);
};


