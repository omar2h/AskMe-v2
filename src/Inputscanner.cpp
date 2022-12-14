/*
 * Inputscanner.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Inputscanner.h"

Input_scanner::Input_scanner()
{
	// TODO Auto-generated constructor stub
}

Input_scanner::~Input_scanner()
{
	// TODO Auto-generated destructor stub
}

int Input_scanner::get_choice(const int low, const int high)
{
	int choice{};
	std::cin >> choice;
	if (verify_choice(choice, low, high))
		return choice;
	return 0;
}

bool Input_scanner::verify_choice(const int choice, const int low, const int high)
{
	if (choice < low && choice > high)
		return false;
	return true;
}

std::string Input_scanner::get_qText_from_user()
{
	std::string qText;
	std::cin.ignore();
	std::cout << "Enter Your Question: ";
	std::getline(std::cin, qText);
	return qText;
}
