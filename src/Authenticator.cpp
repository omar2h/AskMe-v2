/*
 * Authenticator.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Authenticator.h"
#include "Error.h"
#include "User.h"
#include <iostream>

Authenticator::Authenticator()
{
	// TODO Auto-generated constructor stub
}

Authenticator::~Authenticator()
{
	// TODO Auto-generated destructor stub
}

void Authenticator::access(const int choice, User &user)
{
	if (choice == LOGIN)
	{
		try
		{
			login_handler.login(user);
			std::cout << "\n-------------- Logged In Successfully -------------\n\n";
			return;
		}

		catch (const int err)
		{
			throw;
		}
	}

	else if (choice == SIGNUP)
	{
		try
		{
			signup_handler.signup();
			std::cout << "\n-------------- Signed Up Successfully -------------\n\n";
			return;
		}
		catch (const int err)
		{
			throw;
		}
	}
	else if (choice == EXIT)
		exit(0);
}
