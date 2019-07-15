/**********************************************************************************************************************
* Description: This is the specification file for the UpHallway class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_UPHALLWAY_HPP
#define FINAL_UPHALLWAY_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class UpHallway: public Space {
private:
	std::string currentSpace ="upstairs hallway";
	std::vector<std::string> items{"batteries", "pens", "family pictures"};
	int interaction = 0;

public:
	//constructor
	UpHallway(){}

	//getters
	int getMoves();
	std::string getRoomName();
	void getItems();
	int getNumItems();
	int getInteraction();
	int getInteractionInt();

	//setters
	void setMoves(Space*);
	void setMoves(Space*, Space*);
	void setMoves(Space*, Space*, Space*, Space*, Space*);
	void interact(int);

	//mutators
	std::string removeItem(int);
	Space* move(int);

	//destructor
	~UpHallway() {}
};


#endif //FINAL_UPHALLWAY_HPP
