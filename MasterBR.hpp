/**********************************************************************************************************************
* Description: This is the specification file for the MasterBR class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_MASTERBR_HPP
#define FINAL_MASTERBR_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class MasterBR: public Space {
private:
	std::string currentSpace ="Danial's bedroom";
	std::vector<std::string> items{"cell phone", "watch", "clock radio"};
	int interaction = 0;

public:
	//constructor
	MasterBR(){}

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
	~MasterBR() {}
};


#endif //FINAL_MASTERBR_HPP
