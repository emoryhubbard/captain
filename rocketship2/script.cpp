#include <map>
#include <iostream>
#include <vector>
#include "script.h"
#include "action.h"
#include <memory>
using std::string;
using std::map;
using std::vector;
using std::shared_ptr;
using ActionPtr = shared_ptr<Action>;
using ActionPtrs = vector<shared_ptr<Action>>;
using ActionMap = map<string, ActionPtrs>;

Script::Script() {
	map = ActionMap();
}
void Script::addAction(string group, ActionPtr action) {
	if (map.find(group) == map.end())
		map[group];		//old comments. I was using a map of raw pointers at one point which translation: (*map)[group] = vector<Action>(); I didn't want to risk doing anything close to constructing an Actor, though, since I have a circular depenency on it. It will default to that translation anyway, either here or in map, hopefully map since it's outside of here. 
	map[group].emplace_back(action); 	//the old check, to see if an action is already added, didn't work because you have to define the == operator on Action to use find: if (find(map[group].begin(), map[group].end(), action) == map[group].end())
}
ActionPtrs& Script::getActions(string group) {
	return map[group];	//old comments. I went through several different types of things to return. why not return a reference? We want to be able to return a null value. Why not return an iterator? We might not have access to the container in the calling function, to use it!=conatiner.end(). Why not return a raw pointer? Memory might reallocate when vector resizes.
}
template<class T> void Script::add(string group, T action) {
	addAction(group, ActionPtr(new T));		// future method to be used by Action.runIn()
}