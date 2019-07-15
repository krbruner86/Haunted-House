/**********************************************************************************************************************
* Description: This is the specification file for the BedRoom2 class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_BEDROOM2_HPP
#define FINAL_BEDROOM2_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class BedRoom2: public Space {
private:
	std::string currentSpace ="Coco's bedroom";
	std::vector<std::string> items{"teddy bear", "pink blanket", "book"};
	int interaction = 0;


public:
	//constructor
	BedRoom2(){}

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
	~BedRoom2() {}
};


#endif //FINAL_BEDROOM2_HPP
