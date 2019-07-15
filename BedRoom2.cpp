/**********************************************************************************************************************
* Description: This is the implementation file for the BedRoom2 class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#include "BedRoom2.hpp"

//getters.

// displays the user's legal moves fom this room, returns and integer, the number of legal moves
int BedRoom2::getMoves() {

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
std::string BedRoom2::getRoomName() {
	return currentSpace;
}

// displays the items in the room
void BedRoom2::getItems() {
	for (int i = 0; i < int(items.size()); i++) {
		std::cout << i+1 << ". " << items[i] << std::endl;
	}
}

//returns an integer, the number of items in the items vector
int BedRoom2::getNumItems() {
	return int(items.size());
}

// dispays the rooms interaction, if any, returns an integer the number of choices for the user
int BedRoom2::getInteraction() {
	if (!interaction) {
		std::cout << "Coco is sleeping, would you like to wake her up?\n";
		std::cout << "1. Yes\n2. No\n";
		return 2;
	} else {
		std::cout << "There aren't any interactions in this room";
		return 0;
	}
}

// returns the data in the integer variable interaction which is a flag as to if the room has
// or has not been interacted with
int BedRoom2::getInteractionInt() {
	return interaction;
}

// setters

// the setMoves methods allocate the pointers of Spaces to the correct moves
// if empty it is not the correct number of pointers
void BedRoom2::setMoves(Space* room) {
	roomVects[0] = nullptr;
	roomVects[1] = nullptr;
	roomVects[2] = nullptr;
	roomVects[3] = room;
	roomVects[4] = nullptr;
	roomVects[5] = nullptr;
}

void BedRoom2::setMoves(Space* room1, Space* room2) {
	// intentionally left empty
}

void BedRoom2::setMoves(Space* room1, Space* room2, Space* room3, Space* room4, Space* room5) {
	// intentionally left empty
}

// the effect of the interaction, if any
void BedRoom2::interact(int choice) {
	if (choice == 1) {
		std::cout << "You wake up Coco and grab her hand, and tell her that we must leave!\n";
		interaction = 1;
	}
}

// mutators

// removes an item from the items vector, takes an integer as the index of the item to remove
std::string BedRoom2::removeItem(int index) {
	std::string temp = items[index-1];
	items.erase(items.begin() + (index-1));
	return temp;
}

// Returns a Spaces pointer of which the player selected to move to
// takes an integer as an argument, the index of the Space pointer in the roomVects vector
Space* BedRoom2::move(int index) {

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