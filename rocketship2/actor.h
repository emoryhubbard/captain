#pragma once
#include <memory>
#include <iostream>
#include "raylib.h"
import point;
import constants;

class OutputService;
class Actor {
protected:
	std::string text;
	int font_size;
	std::string texture;
	Color color;
	double width;
	double height;
	double speed;
	Point position;
	Point velocity;
	Point acceleration;
	Point direction;
	void updatePosition(double delta_time);
	Point predictPosition(double delta_time);
	void updateVelocity(double delta_time);
public:
	Actor();
	void copyTo(std::shared_ptr<Actor> copy);
	std::string getText();
	int getFontSize();
	Color getColor();
	void setSpeed(double speed);
	double getSpeed();
	void setPosition(double x, double y);
	Point& getPosition();
	void setVelocity(double x, double y);
	Point& getVelocity();
	void setAcceleration(double x, double y);
	Point& getAcceleration();
	void setDirection(double x, double y);
	Point& getDirection();
	void setColor(int r, int g, int b);
	virtual void update(double delta_time);
	virtual void draw(OutputService* output_service);
	bool equals(std::shared_ptr<Actor> other);
};

