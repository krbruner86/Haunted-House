/**********************************************************************************************************************
* Description: This is the specification file for the Dining class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_DINING_HPP
#define FINAL_DINING_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class Dining: public Space {
private:
	std::string currentSpace ="dining room";
	std::vector<std::string> items{"knife", "candlestick", "broken glass"};
	int interaction = 0;


public:
	//constructor
	Dining(){}

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
	~Dining() {}
};


#endif //FINAL_DINING_HPP
