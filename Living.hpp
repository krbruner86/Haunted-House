/**********************************************************************************************************************
* Description: This is the specification file for the Living class. It is a child of the abstract Spaces class. It
* provides data and methods of rooms in a house.
**********************************************************************************************************************/

#ifndef FINAL_LIVING_HPP
#define FINAL_LIVING_HPP

#include "Space.hpp"
#include <iostream>
#include <string>
#include <vector>

class Living: public Space {
private:
	std::string currentSpace ="living room";
	std::vector<std::string> items{"glass of whiskey", "truck keys", "tv remotes"};
	int interaction = 0;

public:
	//constructor
	Living(){}

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
	~Living() {}
};


#endif //FINAL_LIVING_HPP
