/**********************************************************************************************************************
* Description: This is the implementation file for the Kitchen class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#include "Kitchen.hpp"

//getters

// displays the user's legal moves fom this room, returns and integer, the number of legal moves
int Kitchen::getMoves() {

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
std::string Kitchen::getRoomName() {
	return currentSpace;
}

// displays the items in the room
void Kitchen::getItems() {
	for (int i = 0; i < int(items.size()); i++) {
		std::cout << i+1 << ". " << items[i] << std::endl;
	}
}

//returns an integer, the number of items in the items vector
int Kitchen::getNumItems() {
	return items.size();
}

// displays the rooms interaction, if any, returns an integer the number of choices for the user
int Kitchen::getInteraction() {
	std::cout << "There aren't any interactions in this room\n";
	return 0;
}

// returns the data in the integer variable interaction which is a flag as to if the room has
// or has not been interacted with
int Kitchen::getInteractionInt() {
	return interaction;
}

// setters

// the setMoves methods allocate the pointers of Spaces to the correct moves
// if empty it is not the correct number of pointers
void Kitchen::setMoves(Space* room) {
	roomVects[0] = nullptr;
	roomVects[1] = room;
	roomVects[2] = nullptr;
	roomVects[3] = nullptr;
	roomVects[4] = nullptr;
	roomVects[5] = nullptr;
}

void Kitchen::setMoves(Space* room1, Space* room2) {
	// intentionally left empty
}

void Kitchen::setMoves(Space* room1, Space* room2, Space* room3, Space* room4, Space* room5) {
	//
}

void Kitchen::interact(int choice) {
	// intentionally left empty
}

// mutators

// removes an item from the items vector, takes an integer as the index of the item to remove
std::string Kitchen::removeItem(int index) {
	std::string temp = items[index-1];
	items.erase(items.begin() + (index-1));
	return temp;
}

// Returns a Spaces pointer of which the player selected to move to
// takes an integer as an argument, the index of the Space pointer in the roomVects vector
Space* Kitchen::move(int index) {

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