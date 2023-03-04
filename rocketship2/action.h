#pragma once
#include "cast.h"
#include <iostream>
#include <memory>
#include "actor.h"
#include "input_service.h"

class OutputService;
class Script;
class Action {
protected:
	template<typename T> void add(std::string group, T original) {
		std::shared_ptr<Actor> copy =
			std::shared_ptr<Actor>(new T);
		original.copyTo(copy);
		cast->addActor(group, copy);
	};
	bool isDown(std::string key);
	bool isUp(std::string key);
	std::shared_ptr<Actor> actor(std::string name);
	static cast::Cast* cast;
	static Script* script;
	static InputService* input_service;
	static OutputService* output_service;
public:
	void runIn(std::string group);
	virtual void run();
	virtual void run(cast::Cast& cast);
	static void setCast(cast::Cast* cast);
	static void setScript(Script* script);
	static void setOutputService(OutputService* output_service);
	static void setAll(cast::Cast* cast, InputService* input_service,
		OutputService* output_service, Script* script);
};



