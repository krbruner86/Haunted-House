/*
 * Description: This is the class implementation file for getInt.hpp. This program gathers input from the user.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "getInt.hpp"


/*
 * Input validation for integers. Takes two ints, first for the lowest value allowed and the second one for the highest
 * value allowed. Returns the integers the user entered.
 */
int getInt(int low, int high) {

	// string to hold input from user. Strings provide an easy way to test for numbers only
	std::string input = "";
	int valid;

	// get input from user and only break loop if just an integer is entered
	do {
		valid = 0;
		std::cout << "Please enter a number " << low << " through " << high << "\n";
		std::getline(std::cin, input);

		// loop through each digit and set flag if anything but an integer is entered
		for (unsigned int i = 0; i < input.length(); i++) {
			if (!std::isdigit(input[i])) {
				valid++;
			}
		}
	} while (valid > 0 || atoi(input.c_str()) < low || atoi(input.c_str()) > high);

	// convert string to int and return
	return atoi(input.c_str());
}