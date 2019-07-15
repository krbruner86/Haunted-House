/**********************************************************************************************************************
* Description: This is the main file for the haunted house escape game. Compile by typing make into the commandline,
* run by typing ./main. The goal of the game is to move around the house investigating and running away from the
* ghosts. You have 25 steps to escape the house, although this is not your first goal, that will be the ending.
*
* At the beginning of each turn, you are presented with the current room, your inventory, and what you can pick up in
* the room. You will then have the option to pick-up an item, drop an item, interact with the room, view the map, or
* move to another room. Not every room has interactions.
**********************************************************************************************************************/

#include <iostream>
#include "Kitchen.hpp"
#include "DownHall.hpp"
#include "Dining.hpp"
#include "Living.hpp"
#include "Study.hpp"
#include "UpHallway.hpp"
#include "MasterBR.hpp"
#include "BedRoom2.hpp"
#include "BedRoom3.hpp"
#include "Bath.hpp"
#include "Player.hpp"
#include "Menu.hpp"

int main() {

	// create a pointer to the abstract class Space
	// as the player moves throughout the house, this pointer will change
	// to the current room
	Space* house;

	// allocate space for each room
	Space* kitchen = new Kitchen;
	Space* downHall = new DownHall;
	Space* dining = new Dining;
	Space* living = new Living;
	Space* study = new Study;
	Space* upHall = new UpHallway;
	Space* master = new MasterBR;
	Space* bed2 = new BedRoom2;
	Space* bed3 = new BedRoom3;
	Space* bath = new Bath;

	// set the moves that are legal from each room
	kitchen->setMoves(downHall);
	downHall->setMoves(kitchen, dining, living, study, upHall);
	dining->setMoves(living, downHall);
	living->setMoves(dining, downHall);
	study->setMoves(downHall);
	upHall->setMoves(master,bed2,bed3,bath,downHall);
	master->setMoves(upHall,bath);
	bed2->setMoves(upHall);
	bed3->setMoves(upHall);
	bath->setMoves(master,upHall);


	// create a Player and Menu object instances
	Player p;
	Menu m;

	// introduce the game to the player
	m.start();

	// set the beginning location of the game
	p.setLocation(master);
	house = master;

	// the game loop
	m.game(&p, house);

	// free all allocated memory
	delete kitchen;
	delete downHall;
	delete dining;
	delete living;
	delete study;
	delete upHall;
	delete master;
	delete bed2;
	delete bed3;
	delete bath;

	// goodbye!
	return 0;
}