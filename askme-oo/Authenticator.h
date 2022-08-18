/*
 * Authenticator.h
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#ifndef AUTHENTICATOR_H_
#define AUTHENTICATOR_H_
#include "Loginhandler.h"
#include "Signuphandler.h"

class User;

#define LOGIN 1
#define SIGNUP 2
#define EXIT 3

class Authenticator
{
	Login_handler login_handler;
	Signup_handler signup_handler{};

public:
	Authenticator();
	virtual ~Authenticator();

	void access(const int, User &);
};

#endif /* AUTHENTICATOR_H_ */
