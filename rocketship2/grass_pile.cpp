#include "grass_pile.h"
GrassPile::GrassPile() : Actor() {
	text = "";
	texture = "images\\GrassPile.png";
	width = 200;
	height = 200;
	position.x -= 1500;
}