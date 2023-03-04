#include "cast.h"
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "actor.h"
using std::string;
using std::map;
using std::vector;
using cast::Cast;
using std::shared_ptr;
using ActorPtr = shared_ptr<Actor>;
using Map = map<std::string, vector<ActorPtr>>;

Cast::Cast() {
	map = Map();
	groups = vector<string>();
	actors = vector<ActorPtr>();
}
void Cast::addActor(string group, ActorPtr actor) {
	if (map.find(group) == map.end()) { // make new group if needed
		map[group] = vector<ActorPtr>();
		groups.emplace_back(group);
	}
	map[group].emplace_back(actor);	//add actor to map
	actors.emplace_back(actor);		//add actor to vector
}
vector<ActorPtr>& Cast::getActors(string group) {
	return map[group];			//Old comments for getFirstActor, which returned optional: why not return a reference? We want to be able to return a null value. Why not return an iterator? We might not have access to the container in the calling function, to use it!=conatiner.end(). Why not return a raw pointer? Memory might reallocate when vector resizes.
}								//More old comments: why not use a smart pointer? We don't want to manage the memory of this object. Smart pointer will destroy its memory unintentionally. We just need to point to it.
ActorPtr Cast::getActor(string name) {
	return map[name][0];		//name is the group, but it serves double time as a unique identifier for actors placed alone in a "group" so they can be accessed individually later.
}
vector<ActorPtr>& Cast::getAllActors() {
	return actors;
}
vector<string>& Cast::getGroups() {
	//test function: std::cout << groups[0] << " " << groups[1] << "\n";
	return groups; //why not get the keys from map? To avoid generating many new vectors during rapid drawing or game update cycles.
}




