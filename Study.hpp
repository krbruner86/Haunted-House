/**********************************************************************************************************************
* Description: This is the specification file for the Study class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_STUDY_HPP
#define FINAL_STUDY_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class Study: public Space {
private:
	std::string currentSpace ="study";
	std::vector<std::string> items{"leather bound books", "letter opener", "garage keys"};
	int interaction = 0;

public:
	//constructor
	Study(){}

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
	~Study() {}
};


#endif //FINAL_STUDY_HPP
