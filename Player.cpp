//
// Created by Kyle on 12/1/2018.
//

#include "Player.hpp"

// getters
void Player::getInventory() {
	for (int i = 0; i < int(inventory.size()); i++) {
		std::cout << i+1 << ". " << inventory[i] << std::endl;
	}
}

bool Player::searchInventory(std::string term) {
	return std::find(inventory.begin(), inventory.end(), term) != inventory.end();
}

int Player::getInventoryLength() {
	return int(inventory.size());
}

std::string Player::getLocation(Space* space) {
	return space->getRoomName();
}

// setters
void Player::addInventory(std::string item) {
	if (inventory.size() < 5) {
		inventory.push_back(item);
	} else {
		std::cout << "Can't pick up any more items, please drop an item\n";
		std::cout << "Select an item to drop:\n";
		getInventory();
		removeInventory(getInt(1,getInventoryLength()));
		addInventory(item);
	}
}

void Player::setLocation(Space* newLocation) {
	currentLocation = newLocation;
}

//mutators
void Player::removeInventory(int index) {
	inventory.erase(inventory.begin() + (index-1));
}

void Player::removeInventoryStr(std::string item) {
	auto itr = std::find(inventory.begin(), inventory.end(), item);
	if (itr != inventory.end()) inventory.erase(itr);
}