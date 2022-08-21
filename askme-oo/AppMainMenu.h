/*
 * AppMainMenu.h
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#ifndef APPMAINMENU_H_
#define APPMAINMENU_H_

class User;

#define PRINT_QUESTIONS_RECEIVED 1
#define PRINT_QUESTIONS_ASKED 2
#define ANSWER 3
#define DELETE 4
#define ASK 5
#define LIST_USERS 6
#define FEED 7
#define LOGOUT 8

class AppMainMenu
{
	void print_questions_received(const int uId);
	void print_questions_asked(const int uId);
	void answer(const int uId);
	void delete_question(const int uId);

public:
	AppMainMenu();
	virtual ~AppMainMenu();

	void run(int choice, User &);
};

#endif /* APPMAINMENU_H_ */
