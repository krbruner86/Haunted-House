//
// Created by Kyle on 12/1/2018.
//

#ifndef FINAL_PLAYER_HPP
#define FINAL_PLAYER_HPP

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Space.hpp"
#include "getInt.hpp"

class Player {
private:
	Space* currentLocation;
	std::vector<std::string> inventory;

public:
	//constructor
	Player() {};

	// getters
	void getInventory();
	bool searchInventory(std::string);
	int getInventoryLength();
	std::string getLocation(Space*);

	//setters
	void addInventory(std::string);
	void setLocation(Space*);

	//mutators
	void removeInventory(int);
	void removeInventoryStr(std::string);

	//destructor
	~Player() {}
};


#endif //FINAL_PLAYER_HPP
