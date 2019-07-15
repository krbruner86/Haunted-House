/**********************************************************************************************************************
* Description: This is the Menu specification file. It runs the main loop of the game, it presents the options to the
* user and calls the getInt class to gather user input.
**********************************************************************************************************************/

#ifndef PROJECT3_MENU_HPP
#define PROJECT3_MENU_HPP

#include <iostream>
#include <algorithm>
#include "getInt.hpp"
#include "Space.hpp"
#include "Player.hpp"

class Menu {
// these are flags for different parts of the game
// it allows for progression of the game happen, and limits the options at other parts
private:
	bool lightswitch = false;
	bool flashlight = false;
	bool lamp = false;
	bool skel_key = false;
	bool kid1 = false;
	bool kid2 = false;
	bool keys = false;
	bool locket = false;
	int result = 0;

public:
	// constructor
	Menu() {}

	void start();
	void game(Player*, Space*);
	bool checks(Player&, Space*, Space*);
	void win();
	void lose();
	void map();
	void pause();

	// destructor
	~Menu() {}
};


#endif //PROJECT3_MENU_HPP
