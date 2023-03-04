#include "action.h"
#include "cast.h"
#include <iostream>
#include <memory>
#include "actor.h"
using cast::Cast;
using std::string;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;

void Action::run() {}
void Action::run(Cast &cast) {

}
void Action::runIn(string group) {
	//future method
}
bool Action::isDown(string key) {
	return input_service->isKeyDown(key);
}
bool Action::isUp(string key) {
	return input_service->isKeyUp(key);
}
ActorPtr Action::actor(string name) {
	return cast->getActor(name);
}
//static members below
Cast* Action::cast;
Script* Action::script;
InputService* Action::input_service;
OutputService* Action::output_service;

void Action::setCast(Cast* cast) {
	Action::cast = cast;
}
void Action::setScript(Script* script) {
	Action::script = script;
}
void Action::setOutputService(OutputService* output_service) {
	Action::output_service = output_service;
}
void Action::setAll(Cast* cast, InputService* input_service,
	OutputService* output_service, Script* script) {
	Action::cast = cast;
	Action::script = script;
	Action::input_service = input_service;
	Action::output_service = output_service;
}