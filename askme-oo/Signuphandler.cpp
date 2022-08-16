/*
 * Signuphandler.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Signuphandler.h"
#include "User.h"
#include "DBmanager.h"

Signup_handler::Signup_handler() {
	// TODO Auto-generated constructor stub

}

Signup_handler::~Signup_handler() {
	// TODO Auto-generated destructor stub
}

void Signup_handler::signup()
{
	User user;
	DBmanager DB;
	std::string username, password;
	char ans;

	std::cout << "Please enter UserName and Password: ";
	std::cin >> username >> password;

	user.setUsername(username);
	user.setPassword(password);
	do
	{
		std::cout << "Allow anonymous questions? (y/n): ";
		std::cin >> ans;

	} while (ans != 'y' && ans != 'n');

	ans == 'y' ? user.setAllowAnonQs(1) : user.setAllowAnonQs(0);

	try{
		DB.add_user(user);
	}
	catch(const int err){
		throw;
	}
}
