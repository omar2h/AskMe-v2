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
#include "User.h"
//class Signup_handler;

class Authenticator {
	Login_handler login_handler;
	Signup_handler signup_handler{};

public:
	Authenticator();
	virtual ~Authenticator();

	void access(const int, User&);
};

#endif /* AUTHENTICATOR_H_ */
