/**********************************************************************************************************************
* Description: This is the implementation file for the DownHall class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#include "DownHall.hpp"

//getters

// displays the user's legal moves fom this room, returns and integer, the number of legal moves
int DownHall::getMoves() {

	int counter = 0;
	for (int i = 0; i < 6; i++) {
		if (roomVects[i] != nullptr) {
			counter++;
			std::cout << counter << ". " << roomVects[i]->getRoomName() << std::endl;
		}
	}
	return counter;
}

//return a string of the name room
std::string DownHall::getRoomName() {
	return currentSpace;
}

// displays the items in the room
void DownHall::getItems() {
	for (int i = 0; i < int(items.size()); i++) {
		std::cout << i+1 << ". " << items[i] << std::endl;
	}
}

//returns an integer, the number of items in the items vector
int DownHall::getNumItems() {
	return items.size();
}

// displays the rooms interaction, if any, returns an integer the number of choices for the user
int DownHall::getInteraction() {
	if (!interaction) {
		std::cout << "There is a door to the basement that is locked, would you like to open it?\n";
		std::cout << "1. Yes\n2. No\n";
		return 2;
	} else {
		std::cout << "There aren't any interactions in this room\n";
		return 0;
	}
}

// returns the data in the integer variable interaction which is a flag as to if the room has
// or has not been interacted with
int DownHall::getInteractionInt() {
	return interaction;
}

// setters

// the setMoves methods allocate the pointers of Spaces to the correct moves
// if empty it is not the correct number of pointers
void DownHall::setMoves(Space* room) {
	// intentionally left empty
}

void DownHall::setMoves(Space* room1, Space* room2) {
	// intentionally left empty
}

void DownHall::setMoves(Space* room1, Space* room2, Space* room3, Space* room4, Space* room5) {
	roomVects[0] = room1;
	roomVects[1] = room2;
	roomVects[2] = room3;
	roomVects[3] = room4;
	roomVects[4] = room5;
	roomVects[5] = nullptr;
}

// the effect of the interaction, if any
void DownHall::interact(int choice) {
	if (choice == 1) {
		std::cout << "You use the skeleton key to clumsily unlock the door. You pull on the door handle and you suddenly\n";
		std::cout << "get knocked on your back by a powerful gust of wind. A foul odor appears\n";
		std::cout << "and apparitions appear above you!\n";
		std::cout << "You have unleashed the demons and ghosts.\n";
		std::cout << "You now must escape with the two kids, Coco and Toby!\n";
		interaction = 1;
	}
}

// mutators

// removes an item from the items vector, takes an integer as the index of the item to remove
std::string DownHall::removeItem(int index) {
	std::string temp = items[index-1];
	items.erase(items.begin() + (index-1));
	return temp;
}

// Returns a Spaces pointer of which the player selected to move to
// takes an integer as an argument, the index of the Space pointer in the roomVects vector
Space* DownHall::move(int index) {

	int counter = 0;
	for (int i = 0; i < 6; i++) {
		if (roomVects[i] != nullptr) {
			counter++;
			if (counter == index) {
				return roomVects[i];
			}
		}
	}

}