#include "grass.h"
#include "raylib.h"
import point;
using grass::Grass;

Grass::Grass() : Actor() {
	text = "green green grass";
	color = GREEN;
}
Grass::Grass(double x, double y) : Grass() {
	this->position = Point(x, y);
}