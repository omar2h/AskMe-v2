/*
 * Menu.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Menu_printer.h"

Menuprinter::Menuprinter() {
	// TODO Auto-generated constructor stub

}

Menuprinter::~Menuprinter() {
	// TODO Auto-generated destructor stub
}

void Menuprinter::menu_login()
{
	std::vector<std::string> menuStrings{};
	menuStrings.push_back("Login");
	menuStrings.push_back("Sign up");
	menuStrings.push_back("Exit");
	print(menuStrings);
}

void Menuprinter::menu_main()
{
	std::vector<std::string> menuStrings{};
	menuStrings.push_back("Print Questions Received");
	menuStrings.push_back("Print Questions I Asked");
	menuStrings.push_back("Answer Questions");
	menuStrings.push_back("Delete Questions");
	menuStrings.push_back("Ask Questions");
	menuStrings.push_back("List System Users");
	menuStrings.push_back("Feed");
	menuStrings.push_back("Logout");
	print(menuStrings);
}

void Menuprinter::print(const std::vector<std::string> menuStrings) const
{
	int sz = (int)menuStrings.size();
	std::cout<<"Menu:\n";
    for(int i=0; i<sz; i++){
    	std::cout<<"\t"<<i+1<<": "<<menuStrings[i]<<"\n";
    }
    std::cout<<"\nPlease enter a number (1 - "<<sz<<"): ";
}

