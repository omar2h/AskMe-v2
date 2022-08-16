/*
 * Menu.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Menu.h"

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::menu_login()
{
	std::vector<std::string> menuStrings{};
	menuStrings.push_back("Menu: \n");
	menuStrings.push_back("\t1: Login\n");
	menuStrings.push_back("\t2: Sign up\n");
	menuStrings.push_back("\t3: Exit\n\n");
	menuStrings.push_back("Please enter a number (1 - 3): ");

	print(menuStrings);
}

void Menu::menu_main()
{
	std::vector<std::string> menuStrings{};
	menuStrings.push_back("Menu: \n");
	menuStrings.push_back("\t1: Print Questions Received\n");
	menuStrings.push_back("\t2: Print Questions I Asked\n");
	menuStrings.push_back("\t3: Answer Questions\n");
	menuStrings.push_back("\t4: Delete Questions\n");
	menuStrings.push_back("\t5: Ask Questions\n");
	menuStrings.push_back("\t6: List System Users\n");
	menuStrings.push_back("\t7: Feed\n");
	menuStrings.push_back("\t8: Logout\n\n");
	menuStrings.push_back("Please enter a number (1 - 8): ");

	print(menuStrings);
}

void Menu::print(const std::vector<std::string> menuStrings) const
{
    for(std::string str: menuStrings){
    	std::cout<<str;
    }
}

