#include <iostream>
#include <memory>
#include <map>
#include <filesystem>
#include "output_service.h"
#include "raylib.h"
#include "not_std.h"
import constants;
using constants::MAX_X;
using constants::MAX_Y;
using constants::CENTER_X;
using constants::CENTER_Y;
using constants::TITLE;
using constants::FRAME_RATE;
using constants::IMAGE_PATH;
using std::string;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;
using std::map;
using Map = map<string, Texture>;
using namespace not_std;
using namespace std::filesystem;

OutputService::OutputService() {
	prev_time = 0;
	cur_time = 0;
	map = Map();
}
OutputService::OutputService(ActorPtr camera) {
	this->camera = camera;
}
void OutputService::setCamera(ActorPtr camera) {
	this->camera = camera;
}
ActorPtr OutputService::getCamera() {
	return camera;
}
void OutputService::updateTime() {
	if (prev_time == 0)		//since it hasn't updated yet, fix cur_time and prev_time to be the current time. Otherwise the deltatime will be wild for the first iteration of the main game loop.
		cur_time = now();

	prev_time = cur_time;
	cur_time = now();
}
double OutputService::deltaTime() {
	return (cur_time - prev_time) / 1000.0;
}
void OutputService::openWindow() {
	InitWindow(MAX_X, MAX_Y, TITLE.c_str()); //not string because InitWindow only takes char*. It's a C library.
	SetTargetFPS(FRAME_RATE);
	loadTextures();
}
void OutputService::closeWindow() {
	unloadTextures();
	CloseWindow();
}
bool OutputService::isWindowOpen() {
	return !WindowShouldClose();
}
void OutputService::clearBuffer() {
	BeginDrawing();
	ClearBackground(LIGHTGRAY);
}
void OutputService::flushBuffer() {
	EndDrawing();
}
void OutputService::drawText(string text, int x, int y, int font_size, Color color) {
	/*if (!onScreen(x, y))	// don't draw invalid coordinates
		return;*/
	DrawText(text.c_str(), x, y, font_size, color);
}
void OutputService::drawTexture(string texture, int x, int y) {
	/*if (!onScreen(x, y))	// don't draw invalid coordinates
		return;*/
	Color tint(255, 255, 255, 255);
	DrawTexture(map[texture], x, y, tint);
}
void OutputService::loadTextures() {
	for (auto& entry : directory_iterator(IMAGE_PATH))
		loadTexture(entry.path().string());
}
void OutputService::loadTexture(string path) {
	map[path] = LoadTexture(path.c_str());
}
void OutputService::unloadTextures() {
	for (auto& entry : directory_iterator(IMAGE_PATH))
		unloadTexture(entry.path().string());
}
void OutputService::unloadTexture(string path) {
	UnloadTexture(map[path]);
}
bool OutputService::onScreen(int x, int y) {
	return !(x > MAX_X - 1 || x < 1 ||
		y > MAX_Y - 1 || y < 1);
}
