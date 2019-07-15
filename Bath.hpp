/**********************************************************************************************************************
* Description: This is the specification file for the Bath class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_BATH_HPP
#define FINAL_BATH_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class Bath: public Space {
private:
	std::string currentSpace ="bathroom";
	std::vector<std::string> items{"photo locket", "towel", "toilet paper"};
	int interaction = 0;

public:
	//constructor
	Bath(){}

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
	~Bath() {}
};


#endif //FINAL_BATH_HPP
