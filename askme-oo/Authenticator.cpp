/*
 * Authenticator.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Authenticator.h"
#include "Error.h"
#include <iostream>

Authenticator::Authenticator() {
	// TODO Auto-generated constructor stub

}

Authenticator::~Authenticator() {
	// TODO Auto-generated destructor stub
}

void Authenticator::access(const int choice, User& user){
	Error error;
	if (choice == 1)
	{
		try
		{
			login_handler.login(user);
			std::cout << "\n-------------- Logged In Successfully -------------\n\n";
		}

		catch(const int err){
			error.print(err);
		}
	}

	else if (choice == 2)
	{
		try
		{
			signup_handler.signup();
			std::cout << "\n-------------- Signed Up Successfully -------------\n\n";
		}
		catch(const int err){
			error.print(err);
		}
	}
	else if (choice == 3)
		exit(0);
}
