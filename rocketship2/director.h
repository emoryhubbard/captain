#pragma once
#include <iostream>
#include <memory>
#include "output_service.h"
#include "input_service.h"
#include "cast.h"
#include "script.h"
#include "action.h"
#include "actor.h"

namespace director {
	using cast::Cast;
	using std::string;
	using std::shared_ptr;
	using ActorPtr = shared_ptr<Actor>;
	using ActionPtr = shared_ptr<Action>;
class Director {
private:
	InputService input_service;
	OutputService output_service;
	Cast cast;
	Script script;
	void run(string group);
	void loadGame();
	void add(string group, ActionPtr);
	ActorPtr actor(string name);
	template<typename T> void add(string group, T);
public:
	Director(Cast &cast, InputService &input_service, OutputService &outputService, Script &script);
	void startGame();
};
}

