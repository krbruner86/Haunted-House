/**********************************************************************************************************************
* Description: This is the implementation file for the Dining class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#include "Dining.hpp"

//getters

// displays the user's legal moves fom this room, returns and integer, the number of legal moves
int Dining::getMoves() {

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
std::string Dining::getRoomName() {
	return currentSpace;
}

// displays the items in the room
void Dining::getItems() {
	for (int i = 0; i < int(items.size()); i++) {
		std::cout << i+1 << ". " << items[i] << std::endl;
	}
}

//returns an integer, the number of items in the items vector
int Dining::getNumItems() {
	return items.size();
}

// dispays the rooms interaction, if any, returns an integer the number of choices for the user
int Dining::getInteraction() {
	if (!interaction) {
		std::cout << "There is a table lamp broken on the floor, Do you want to investigate?\n";
		std::cout << "1. Yes\n2. No\n";
		return 2;
	} else {
		std::cout << "There aren't any interactions in this room";
		return 0;
	}
}

// returns the data in the integer variable interaction which is a flag as to if the room has
// or has not been interacted with
int Dining::getInteractionInt() {
	return interaction;
}

// setters

// the setMoves methods allocate the pointers of Spaces to the correct moves
// if empty it is not the correct number of pointers
void Dining::setMoves(Space* room) {
	// intentionally left empty
}

void Dining::setMoves(Space* room1, Space* room2) {
	roomVects[0] = nullptr;
	roomVects[1] = nullptr;
	roomVects[2] = room1;
	roomVects[3] = room2;
	roomVects[4] = nullptr;
	roomVects[5] = nullptr;
}

void Dining::setMoves(Space* room1, Space* room2, Space* room3, Space* room4, Space* room5) {
	// intentionally left empty
}

// the effect of the interaction, if any
void Dining::interact(int choice) {
	if (choice == 1) {
		std::cout << "The window is open, the wind must've knocked the lamp over.\n";
		std::cout << "You carefully walk past the broken glass and shut the window.\n";
		std::cout << "OK! That solves that...now I better get to the basement to get the lights back on.\n";
	}
	interaction = 1;
}

// mutators

// removes an item from the items vector, takes an integer as the index of the item to remove
std::string Dining::removeItem(int index) {
	std::string temp = items[index-1];
	items.erase(items.begin() + (index-1));
	return temp;
}

// Returns a Spaces pointer of which the player selected to move to
// takes an integer as an argument, the index of the Space pointer in the roomVects vector
Space* Dining::move(int index) {

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