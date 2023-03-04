#include "captain.h"
Captain::Captain() : Actor() {
	text = "";
	texture = "images\\Captain.png";
	width = 150;
	height = 200;
	position.x -= 1500;
}