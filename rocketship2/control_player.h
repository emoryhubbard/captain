#pragma once
#include "action.h"
class ControlPlayer : public Action {
private:
	void setDirection();
	void setVelocity();
public:
	void run();
};

