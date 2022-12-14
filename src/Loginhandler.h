/*
 * Loginhandler.h
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#ifndef LOGINHANDLER_H_
#define LOGINHANDLER_H_

class User;
class Login_handler
{
public:
	Login_handler();
	virtual ~Login_handler();
	/**
	 * logs in user
	 *
	 * @param non
	 * @return bool indicating successful login or not
	 */
	void login(User &);
};

#endif /* LOGINHANDLER_H_ */
