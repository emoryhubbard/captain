#pragma once
#include "raylib.h" // this is included so users can use Color
#include <iostream>
#include <memory>
#include <map>
import point;

class Actor;
class OutputService {
private:
	std::shared_ptr<Actor> camera;
	__int64 cur_time;
	__int64 prev_time;
	std::map<std::string, Texture> map;
	void loadTexture(std::string path);
	void unloadTexture(std::string path);
public:
	OutputService();
	OutputService(std::shared_ptr<Actor> camera);
	void setCamera(std::shared_ptr<Actor> camera);
	std::shared_ptr<Actor> getCamera();
	void updateTime();
	double deltaTime();
	void openWindow();
	void closeWindow();
	bool isWindowOpen();
	void clearBuffer();
	void flushBuffer();
	void drawText(std::string text, int x, int y, int font_size, Color color);
	void drawTexture(std::string texture, int x, int y);
	void loadTextures();
	void unloadTextures();
	bool onScreen(int x, int y);
};




