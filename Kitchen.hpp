/**********************************************************************************************************************
* Description: This is the specification file for the Kitchen class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_KITCHEN_HPP
#define FINAL_KITCHEN_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class Kitchen: public Space {
private:
	std::string currentSpace ="kitchen";
	std::vector<std::string> items{"knife", "skeleton key", "spare change"};
	int interaction = 0;

public:
	//constructor
	Kitchen(){}

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
	~Kitchen() {}
};


#endif //FINAL_KITCHEN_HPP
