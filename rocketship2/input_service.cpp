#include "input_service.h"
#include "raylib.h"
#include <iostream>
#include <map>
using std::string;
using std::map;

InputService::InputService() {
	k = map<string, int>();
	k["a"] = KEY_A;
	k["b"] = KEY_B;
	k["c"] = KEY_C;
	k["d"] = KEY_D;
	k["e"] = KEY_E;
	k["f"] = KEY_F;
	k["g"] = KEY_G;
	k["h"] = KEY_H;
	k["i"] = KEY_I;
	k["j"] = KEY_J;
	k["k"] = KEY_K;
	k["l"] = KEY_L;
	k["m"] = KEY_M;
	k["n"] = KEY_N;
	k["o"] = KEY_O;
	k["p"] = KEY_P;
	k["q"] = KEY_Q;
	k["r"] = KEY_R;
	k["s"] = KEY_S;
	k["t"] = KEY_T;
	k["u"] = KEY_U;
	k["v"] = KEY_V;
	k["w"] = KEY_W;
	k["x"] = KEY_X;
	k["y"] = KEY_Y;
	k["z"] = KEY_Z;
}
bool InputService::isKeyUp(string key) {
	return IsKeyUp(k[key]);		//raylib takes int id
}
bool InputService::isKeyDown(string key) {
	return IsKeyDown(k[key]);	//raylib takes int id
}
/*
This was an old method intended to make
isKeyUp and down not case sensitive.
Didn't get to work right yet.

int InputService::id(string key) {
	char ckey = key[0];			//convert key to char
	char lower = (char) tolower(ckey);	//convert char to lower
	string str = "" + lower;	//convert lower to str
	return k[str];				//lookup key int id
}*/