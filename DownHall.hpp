/**********************************************************************************************************************
* Description: This is the specification file for the DownHall class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_DOWNHALL_HPP
#define FINAL_DOWNHALL_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class DownHall: public Space {
private:
	std::string currentSpace ="downstairs hallway";
	std::vector<std::string> items{"batteries", "pens", "family pictures"};
	int interaction = 0;

public:
	//constructor
	DownHall() {}

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
	~DownHall() {}
};


#endif //FINAL_DOWNHALL_HPP
