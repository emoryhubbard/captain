#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "actor.h"

namespace cast {
	using std::string;
	using std::map;
	using std::vector;
	using std::shared_ptr;
	using ActorPtr = shared_ptr<Actor>;
	using Map = map<std::string, vector<ActorPtr>>;

	class Cast {
	private:
		Map map;
		vector<string> groups;
		vector<ActorPtr> actors;
	public:
		Cast();
		void addActor(string group, ActorPtr actor);
		vector<ActorPtr>& getActors(string group);
		ActorPtr getActor(string name);
		vector<ActorPtr>& getAllActors();
		vector<string>& getGroups();
	};
}
