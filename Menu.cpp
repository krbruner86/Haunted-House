/**********************************************************************************************************************
* Description: This is the Menu specification file. It runs the main loop of the game, it presents the options to the
* user and calls the getInt class to gather user input.
**********************************************************************************************************************/

#include "Menu.hpp"

// sets up the game situation and tells the user how the game will be played
void Menu::start() {
	system("clear");
	std::cout << "You will have 25 steps to complete the game. Follow the story to get you're next objective.\n";
	std::cout << "Each turn you will be presented with the current room that you are in, your inventory and\n";
	std::cout << "the items in the room that you can pick up.\n";
	pause();
	system("clear");
	std::cout << "You will then have 5 options; to pick up an item, to drop an item, to interact with the room,\n";
	std::cout << "view the map, and move to a different room.\n";
	std::cout << "Now, on with the game...\n";
	pause();
	system("clear");
	std::cout << "You (Danial) wake in the middle of a stormy night in your bed to a loud crashing downstairs.\n";
	std::cout << "You reluctantly decide to investigate, and stand up from bed.\n";
	pause();

}

// this is the main loop of the program
// It takes a Player pointer and a Space pointer
void Menu::game(Player* player, Space* house) {

	// set variables to be used throughout the program
	int choice;
	int action;
	int liveCounter = 25;
	int player_menu = 0;
	bool passCheck = false;

	// display the map so th player can visualize the space
	map();
	pause();


	// main loop is there are still steps available and it's not a game over
	while (liveCounter > 0 && result == 0) {

		// this is the winning scenario
		// catch it at the beginning of the loop so we can break out
		if (kid1 && kid2 && keys && house->getRoomName() == "downstairs hallway") {
			win();
			break;
		}

		// reset flag to false so to start loop
		passCheck = false;

		// if scenario did not play out the way the game is scripted
		// you will re-do your turn and the game will push you in the right direction
		while (!passCheck) {

			// the main menu shown for each turn
			do {
				system("clear");

				//display current room and steps remaining
				std::cout << "\nCurrent room: " << house->getRoomName() << std::endl;
				std::cout << "You have " << liveCounter << " steps remaining!\n";

				// show inventory
				if (player->getInventoryLength()) {
					std::cout << "\nYour current inventory:\n";
					player->getInventory();
				} else {
					std::cout << "\nYour are not currently carrying anything\n";
				}

				// show the items in the room
				if (house->getNumItems()) {
					std::cout << "\nThe items in the room:\n";
					house->getItems();
				} else {
					std::cout << "\nThere aren't any items available in the room.\n";
				}

				// prompt player with choice
				std::cout << "\nWhat would you like to do in " << player->getLocation(house) << std::endl;

				std::cout << "1. Pick up item\n";
				std::cout << "2. Drop item\n";
				std::cout << "3. Interact\n";
				std::cout << "4. View map\n";
				std::cout << "5. Move\n";

				// gather input
				player_menu = getInt(1,5);

				// based upon user input, go to the option they chose
				switch (player_menu) {
					// pick up an item
					case 1:
						if (house->getNumItems()) {
							std::cout << "Select an item to pick up\n";
							house->getItems();
							player->addInventory(house->removeItem(getInt(1, house->getNumItems())));
						} else {
							std::cout << "No items left in this room\n";
							pause();
						}
						break;
					// drop an item
					case 2:
						if (player->getInventoryLength()) {
							std::cout << "Select an item to drop\n";
							// remove item from player inventory
							player->getInventory();
							player->removeInventory(getInt(1, player->getInventoryLength()));
						} else {
							std::cout << "\nYour are not currently carrying anything\n";
						}
						break;
					// interact with the room
					case 3:
						choice = house->getInteraction();

						if (choice) {
							action = getInt(1, choice);
							if (action == 1) {
								system("clear");
								if (house->getRoomName() == "upstairs hallway" && house->getInteractionInt() == 0) {
									player->addInventory("flashlight");
									flashlight = true;
								}
								if ((house->getRoomName() == "downstairs hallway" && !skel_key) || (house->getRoomName() == "downstairs hallway" && !lamp)) {
									if (!skel_key) {
										std::cout << "You need to have the skeleton key in your inventory to unlock the door.\n";
									} else {
										std::cout << "I should look around in a different room and investigate that noise...\n";
									}
								} else if (house->getRoomName() == "Coco's bedroom" && !skel_key) {
									std::cout << "I shouldn't disturb Coco, she looks like she's sleeping OK.\n";
								}  else if (house->getRoomName() == "Toby's bedroom" && !skel_key) {
									std::cout << "I shouldn't disturb Toby, he looks like he's sleeping OK.\n";
								}  else {
									house->interact(action);
								}
								pause();
							}
						}
						break;
					// view map
					case 4:
						map();
						std::cout << "\nCurrent room: " << house->getRoomName() << std::endl;
						pause();
						break;
				}

			} while (player_menu != 5);

			// ask player where they want to move to
			std::cout << "Which room would you like to move to:\n";
			int option = getInt(1, house->getMoves());

			// store the players choice in a temporary variable so that we can check
			// if certain events and flags conditions are met to actually move
			Space *temp = house->move(option);

			// send the potential move to be checked
			passCheck = checks(*player, house, temp);

			// if it is a legal move at the time
			// go ahead an move the player
			if (passCheck) {
				player->setLocation(temp);
				house = temp;
			}

			// remind player what to do at certain point of the game
			if (kid1 && kid2 && !keys) {
				system("clear");
				std::cout << "I need to grab my truck keys from downstairs before I leave the house.\n";
				if (!locket) {
					system("clear");
					std::cout << "Coco says to grab a photo locket from the bathroom to help keep the ghosts away.\n";
				}
			}

			// if the locket was grabbed
			// if you grab the photo locket then 5 more steps are added to your life
			if (locket) {
				system("clear");
				std::cout << "The photo locket gave you an extra 5 steps!\n";
				pause();
				liveCounter+=5;
				locket = false;
			}

			// decrease the steps available
			liveCounter--;
		}

	}

	// if the result didn't change, display losing message
	if (result == 0) {
		lose();
	}
}

// this method provides checks on the progression of the game and unlocks certain elements
bool Menu::checks(Player &p, Space* current_room, Space* next_room) {

	// you must turn on the lightswitch before you leave the bedroom
	if (current_room->getRoomName() == "Danial's bedroom") {
		if (current_room->getInteractionInt() == 0) {
			system("clear");
			std::cout << "I should try to turn on the light switch to help see where I'm going.\n";
			pause();
			return false;
		} else if (current_room->getRoomName() == "Danial's bedroom" && current_room->getInteractionInt() == 1 && !lightswitch) {
			lightswitch = true;
			system("clear");
			std::cout << "I should grab the flashlight in the hallway so I can see where I'm going.\n";
			return true;
		}
	}

	// you must open the drawer and pick up the flashlight before going downstairs
	if (current_room->getRoomName() == "upstairs hallway") {
		if (current_room->getInteractionInt() == 0) {
			system("clear");
			std::cout << "I can't see well enough to go to another room, I might have left the flashlight in the drawer...\n";
			pause();
			return false;
		} else if (current_room->getInteractionInt() == 1 && flashlight) {
			system("clear");
			std::cout << "\nI need to check out what that noise that woke me up from downstairs.\n";
			return true;
			}
	}

	// investigate the noise in the dining room
	if (current_room->getRoomName() == "dining room") {
		if (current_room->getInteractionInt() == 0) {
			system("clear");
			std::cout << "I though I heard that noise come from this room somewhere...\n";
			pause();
			return false;
		} else if (current_room->getInteractionInt() == 1 && !lamp) {
			system("clear");
			std::cout << "OK, now I can grab the key and get to the breaker box.\n";
			lamp = true;
			return true;
		}
	}

	// you need to visit the dining room and have the skeleton key in your inventory to open the basement door
	if (current_room->getRoomName() == "downstairs hallway") {
		if (!lamp) {
			system("clear");
			std::cout << "I should look around in a different room and investigate that noise...\n";
		} else if (lamp) {
			if (current_room->getInteractionInt() == 0) {
				system("clear");
				std::cout << "I need the skeleton key to open the door,...\n";
				return true;
			} else if (current_room->getInteractionInt() == 1 && skel_key && flashlight) {
				p.removeInventoryStr("skeleton key");
				return true;
			}
		}
	}

	// you must pick up the skeleton key in kitchen
	if (current_room->getRoomName() == "kitchen") {
		if (!p.searchInventory("skeleton key")) {
			system("clear");
			std::cout << "I should grab the key from this room before leaving.\n";
			pause();
			return false;
		} else {
			skel_key = true;
			system("clear");
			std::cout << "Now to unlock the basement door.\n";
			return true;
		}
	}

	//you must pick up both kids to leave
	if (current_room->getRoomName() == "Coco's bedroom" && current_room->getInteractionInt()) {
		if (flashlight && lightswitch && skel_key && lamp && !kid1) {
			kid1 = true;
			std::cout << "I grab Coco\n";
			return true;
		}
	}

	if (current_room->getRoomName() == "Toby's bedroom" && current_room->getInteractionInt()) {
		if (flashlight && lightswitch && skel_key && lamp && !kid2) {
			kid2 = true;
			std::cout << "I grab Toby\n";
			return true;
		}
	}

	// if you grab the photo locket you get an extra 5 steps
	if (current_room->getRoomName() == "bathroom" && p.searchInventory("photo locket")) {
			locket = true;
			return true;
	}

	// you must pick up the truck keys in living room
	if (current_room->getRoomName() == "living room" && kid1 && kid2) {
		if (!p.searchInventory("truck keys")) {
			system("clear");
			std::cout << "I should grab the truck keys from this room before leaving.\n";
			pause();
			return false;
		} else if (p.searchInventory("truck keys")) {
			keys = true;
			system("clear");
			std::cout << "You rush out the front door with the kids in hand.\n";
			std::cout << "You have escaped the house!\n";
			return true;
		}
	} else { return true; }

}

// display win message
void Menu::win() {
	system("clear");
	std::cout << "Congratulations you win!\n";
	result = 1;
}

// display losing message
void Menu::lose() {
	system("clear");
	std::cout << "Sorry the ghost got you, you lose!\n";
	result = 2;
}

// display the map
void Menu::map() {
	system("clear");
	std::cout << "                                     Upstairs                                    \n";
	std::cout << " ------------------------------------------------------------------------------- \n";
	std::cout << "|                             |                                                 |\n";
	std::cout << "|        Danial's             |                              Coco's             |\n";
	std::cout << "|         Room                |                 |----|       Room               |\n";
	std::cout << "|                                    Upstairs   |----|                          |\n";
	std::cout << "|                                    Hallway    |----|                          |\n";
	std::cout << "|                             |                 |----|                          |\n";
	std::cout << "|                             |                 |----|--------------------------|\n";
	std::cout << "|------------    -------------|                 |----|                          |\n";
	std::cout << "|                             |                 |----|                          |\n";
	std::cout << "|                             |                 |----|       Toby's             |\n";
	std::cout << "|         Bathroom                              |____|       Room               |\n";
	std::cout << "|                                                                               |\n";
	std::cout << "|                             |                                                 |\n";
	std::cout << "|                             |                      |                          |\n";
	std::cout << " ------------------------------------------------------------------------------- \n";

	pause();

	std::cout << "                                     Downstairs                                  \n";
	std::cout << " ------------------------------------------------------------------------------- \n";
	std::cout << "|                             |                                                 |\n";
	std::cout << "|         Kitchen                                           Dining              |\n";
	std::cout << "|                                               |----|       Room               |\n";
	std::cout << "|                                  Downstairs   |----|                          |\n";
	std::cout << "|                                    Hallway    |----|                          |\n";
	std::cout << "|                             |                 |----|                          |\n";
	std::cout << "|                             |                 |----|------            --------|\n";
	std::cout << "|-----------------------------|                 |----|                          |\n";
	std::cout << "|                             |                 |----|                          |\n";
	std::cout << "|                                               |----|      Living              |\n";
	std::cout << "|         Study                                 |____|       Room               |\n";
	std::cout << "|                                                                               |\n";
	std::cout << "|                             |                                                 |\n";
	std::cout << "|                             |                      |                          |\n";
	std::cout << " ------------------------------------      ------------------------------------- \n";

}

// pauses the menu output so that the user can see what has been printed to the screen
void Menu::pause() {
	do
	{
		std::cout << '\n' << "Press Enter key to continue";
	} while (std::cin.get() != '\n');
}