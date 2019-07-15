/**********************************************************************************************************************
* Description: This is the Space specification file. Space is an abstract class. It's children hold information and
* methods about rooms of a house.
**********************************************************************************************************************/

#ifndef FINAL_SPACE_HPP
#define FINAL_SPACE_HPP

#include <string>
//#include <map>
#include <vector>

class Space {
protected:
	std::string currentSpace;
	std::vector<Space*> roomVects;


public:
	//constructor
	Space () {

		for (int i = 0; i < 6; i++) {
			roomVects.push_back(nullptr);
		}



	}

	//getters
	virtual std::string getRoomName() = 0;
	virtual int getMoves() =0;
	virtual void getItems() =0;
	virtual int getNumItems() =0;
	virtual int getInteraction() =0;
	virtual int getInteractionInt() =0;


	//setters
	virtual void setMoves(Space*) =0;
	virtual void setMoves(Space*, Space*) =0;
	virtual void setMoves(Space*, Space*, Space*, Space*, Space*) =0;
	virtual void interact(int) =0;

	//mutators
	virtual std::string removeItem(int) =0;
	virtual Space* move(int) =0;

	//destructor
	virtual ~Space() {};
};


#endif //FINAL_SPACE_HPP
