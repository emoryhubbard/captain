#include "add_test_actors.h"
#include "player.h"
#include "grass.h"
#include "draw_actors.h"
#include "habitat.h"
#include "holo_disk.h"
#include "green_house.h"
#include "captain.h"
#include "grass_pile.h"
import constants;
using grass::Grass;
using draw_actors::DrawActors;
using constants::MAX_X;
using constants::MAX_Y;
using constants::CENTER_Y;
using constants::CENTER_X;

void AddTestActors::run() {
    Player player;
    Grass grass;
    add("player", player);
    //add("grass", grass);
    add("habitat", Habitat());
    add("holo_disk", HoloDisk());
    add("green_house", GreenHouse());
    HoloDisk disk2 = HoloDisk();
    disk2.setPosition(CENTER_X + 1100, CENTER_Y);
    add("holo_disk", disk2);
    add("grass_pile", GrassPile());
    add("captain", Captain());
}