#pragma once
#include <iostream>
#include <map>

class InputService {
private:
	std::map<std::string, int> k;
	int id(std::string key);
public:
	InputService();
	bool isKeyUp(std::string key);
	bool isKeyDown(std::string key);
};

