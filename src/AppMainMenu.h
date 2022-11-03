/*
 * AppMainMenu.h
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#ifndef APPMAINMENU_H_
#define APPMAINMENU_H_
#include <unordered_set>
#include "DBmanager.h"
#include "graph.h"
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
	void print_questions_received(const int uId) const;
	void print_questions_asked(const int uId) const;
	void answer(const int uId) const;
	void delete_question(const int uId) const;
	void ask(const int uId) const;
	void list_users() const;
	void print_feed() const;
	void dfs(const GRAPH &, int key, std::unordered_set<int> &, DBmanager &, int, int = 0) const;

public:
	AppMainMenu();
	virtual ~AppMainMenu();

	int run(int choice, User &);
};

#endif /* APPMAINMENU_H_ */
