#include "director.h"
#include "add_test_actors.h"
#include "action.h"
#include <iostream>
#include <vector>
#include <memory>
#include "draw_actors.h"
#include "move_actors.h"
#include "control_player.h"
using director::Director;
using cast::Cast;
using draw_actors::DrawActors;
using std::vector;
using std::map;
using std::string;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;
using ActionPtr = shared_ptr<Action>;
using ActionPtrs = vector<shared_ptr<Action>>;

Director::Director(Cast &cast, InputService &input_service,
	OutputService &output_service, Script &script) {
	this->cast = cast;
	this->input_service = input_service;
	this->output_service = output_service;
	this->script = script;
}
void Director::startGame() {
	output_service.openWindow();
	loadGame();

	while (output_service.isWindowOpen()) {
		run("input");
		run("output");
	}

	output_service.closeWindow();
}
void Director::loadGame() {
	Action::setAll(&cast, &input_service, &output_service,
		&script);
	AddTestActors().run();
	output_service.setCamera(actor("player"));

	add("input", ControlPlayer());
	add("output", DrawActors()); //in the future, you'll have Action.runIn("group") or Action.put("group") instead
	add("output", MoveActors());
}
void Director::add(string group, ActionPtr action) {
	script.addAction(group, action);
}
ActorPtr Director::actor(string name) {
	return cast.getActor(name);
}
void Director::run(string group) {
	for (auto &action : script.getActions(group))
		action->run();
}






// not complicated, helps add Actions without using ActionPtr
template<class T> void Director::add(string group, T action) {
	script.addAction(group, ActionPtr(new T));
}













