#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>

class Action;
class Script {
private:
	std::map<std::string, std::vector<std::shared_ptr<Action>>> map;
	template<typename T> void add(std::string group, T);
public:
	Script();
	void addAction(std::string group, std::shared_ptr<Action> action);
	std::vector<std::shared_ptr<Action>>& getActions(std::string group);						//why not use a smart pointer? We don't want to manage the memory of this object. Smart pointer will destroy its memory unintentionally. We just need to point to it.
};

