/*
 * App.cpp
 *
 *  Created on: Aug 10, 2022
 *      Author: omarh
 */

#include "App.h"
#include "User.h"
#include "Error.h"
#include "Inputscanner.h"
#include "Authenticator.h"
#include "AppMainMenu.h"
#include "Menu_printer.h"

App::App()
{
	// TODO Auto-generated constructor stub
}

App::~App()
{
	// TODO Auto-generated destructor stub
}

/* ****** helper functions ******** */

// std::string App::get_qText_from_user()
//{
//	std::string qText;
//	std::cin.ignore();
//	std::cout << "Enter Your Question: ";
//	std::getline(std::cin, qText);
//	return qText;
// }

/* *********************************************** */

/* 1- get login choice from user */
/* 2- if logged in proceed to the main menu */
void App::run()
{
	User user;
	Menuprinter menu;
	Authenticator auth;
	Error error;
	Input_scanner input_scanner;
	AppMainMenu appMain;

	int choice;

	while (1)
	{
		while (1)
		{
			/* prints login menu */
			menu.menu_login();
			choice = input_scanner.get_choice(1, 3);
			if (!choice)
				continue;
			try
			{
				auth.access(choice, user);
				break;
			}
			catch (const int err)
			{
				error.print(err);
			}
		}
		while (1)
		{
			menu.menu_main();
			choice = input_scanner.get_choice(1, 8);
			if (!choice)
				continue;
			try
			{
				appMain.run(choice, user);
			}
			catch (const int err)
			{
				error.print(err);
			}
		}
	}
}

// void App::main_menu(User &user)
//{
//	Menu menu;
//	Error error;
//	int choice;
//
//	while (1)
//	{
//		choice = menu.menu_main();
//		if (!verify_choice(choice, 1, 8))
//		{
//			error.print(1);
//			continue;
//		}
//
//		if (choice == 1)
//		{
//			// 1: print questions received
//			//print_questions_received(user.id);
//		}
//
//		else if (choice == 2)
//		{
//			// 2: print questions i asked
//			//print_questions_asked(user.id);
//		}
//		else if (choice == 3)
//		{
//			// 3 answer questions
//			//answer(user.id);
//		}
//		else if (choice == 4)
//		{
//			// 4 delete question
//			//delete_question(user.id);
//		}
//		else if (choice == 5)
//		{
//			// 5: ask question
//			//ask(user);
//		}
//		else if (choice == 6)
//		{
//			// 6: list system users
//			//list_users();
//		}
//		else if (choice == 7)
//		{
//			// 7 feed
//			//print_feed();
//		}
//		else if (choice == 8)
//		{
//			// 8: Logout
//			break;
//		}
//	}
// }

// void App::print_questions_received(const int uId)
//{
//	DbManager DB;
//	/* map variable to store questions where the id is the key and vector of questions beginning with the questions followed by its children if any */
//	std::map<int, std::vector<Question>> mp;
//	/* Fill the map with all question the user received */
//	DB.get_all_Qs_to_user(uId, mp);
//
//	// c++ 17 syntax
//	for (auto &[key, val] : mp)
//	{
//		/* if is a parent question then print the children */
//		if (val[0].threadId == -1)
//		{
//			int spaces = 0;
//			val[0].print();
//			for (int i = 1; i < (int)val.size(); i++)
//			{
//				/* at each child question increase space by 2 to distinguish from parent question */
//				print_children(mp[val[i].id], mp, spaces + 2);
//			}
//
//			std::cout << '\n';
//		}
//	}
// }

// void App::print_questions_asked(const int uId)
//{
//	DbManager DB;
//	/* vector variable to store questions user asked */
//	std::vector<Question> qv;
//	/* fill vector with questions asked only */
//	DB.questionsDb.get_questions_from_user(uId, qv);
//
//	// c++ 17 syntax
//	for (auto &q : qv)
//	{
//		/* print question in an asked format */
//		q.print_asked();
//	}
// }

/* 1- user enter if of the other user to ask (toUser) */
/* 2- check toUser exist in database */
/* 3- check if toUser allow anon questions. if allow ask user to choose question to be anon or not */
/* 4- enter question id if new enter -1 or id of existing q */
// void App::ask(User &user)
//{
//	/* variable to store new question asked by user */
//	Question q;
//	/* variable to store the user being asked */
//	User toUser;
//	/* update question fromId to the current user's id */
//	q.fromId = user.id;
//	Error error;
//	DbManager DB;
//	int toUserId;
//
//	/* Enter toUser id */
//	while (1)
//	{
//		std::cout << "Enter User ID You Want to Ask or -1 to cancel:  ";
//		std::cin >> toUserId;
//		if (toUserId == -1)
//			return;
//
//		toUser.id = toUserId;
//		/* check whether user exists then. user is sent by reference so it is updated */
//		/* sending user as a parameter not just the id to check later if it allows anon questions or not*/
//		if (DB.check_user_exist(toUser))
//			break;
//		/* print error User ID doesn't seem to exist */
//		error.print(3);
//	}
//	q.toId = toUser.id;
//
//	/* check the user being asked if it allows anon questions and print a disclaimer if it does not*/
//	if (!toUser.allowAnonQs)
//	{
//		q.anon = 0;
//		std::cout << "Note: This User doesn't Allow Anonymous Questions\n";
//	}
//	int qId;
//
//	/* enter question id */
//	while (1)
//	{
//		std::cout << "Enter question thread ID or -1 to Ask a New Question: ";
//		std::cin >> qId;
//		/* only if user allow anon questions you can ask anon questions*/
//		if (toUser.allowAnonQs)
//		{
//			while (1)
//			{
//				char c;
//				std::cout << "Keep this Question Anonymous? (y/n): ";
//				std::cin >> c;
//				if (c == 'y')
//				{
//					q.anon = 1;
//					break;
//				}
//				if (c == 'n')
//				{
//					q.anon = 0;
//					break;
//				}
//			}
//		}
//		if (qId == -1)
//		{
//			q.text = get_qText_from_user(), q.threadId = -1, q.answered = 0;
//			break;
//		}
//		else
//		{
//			/* if it is not parent question then check whether the user being asked has the parent thread or not*/
//			if (DB.check_user_has_q(qId, toUserId))
//			{
//				q.threadId = qId, q.answered = 0;
//				q.text = get_qText_from_user();
//				break;
//			}
//			else
//			{
//				/* error: Question ID doesn't seem to exist for this user */
//				error.print(4);
//			}
//		}
//	}
//
//	DB.questionsDb.add_question(q);
//	std::cout << "\n\n--------- Question Saved ----------\n\n";
// }

/* 1- user enter question to answer */
/* 2- enter answer */
// void App::answer(const int uId)
//{
//	DbManager DB;
//	Error error;
//	Question q;
//	int qId;
//
//	/* user enter question to answer */
//	while (1)
//	{
//		std::cout << "Enter question id to answer or -1 to cancel: ";
//		std::cin >> qId;
//
//		if (qId == -1)
//			return;
//
//		/* check whether user received this question or not. can only answer if it is received */
//		if (!DB.check_user_has_q(qId, uId))
//			/* error: Question ID doesn't seem to exist for this user */
//			error.print(4);
//		else
//			break;
//	}
//	q = DB.questionsDb.get_question(qId).first;
//
//	q.print();
//	if (q.answered)
//		std::cout << "\n--- Warning: Question already answered. Answer will be overwritten ---\n\n";
//	std::cin.ignore();
//
//	/* enter answer */
//	std::cout << "Enter answer: ";
//	std::getline(std::cin, q.ans);
//	q.answered = 1;
//
//	DB.questionsDb.update_answer(q);
//	std::cout << "\n\n---- Answer Saved ----\n\n";
// }

/* 1- enter question id */
// void App::delete_question(const int uId)
//{
//	DbManager DB;
//	Error error;
//	Question q;
//	int qId;
//
//	/* enter question id */
//	while (1)
//	{
//		std::cout << "Enter question id to delete or -1 to cancel: ";
//		std::cin >> qId;
//
//		if (qId == -1)
//			return;
//
//		/* user can only delete question asked or received by user */
//		if (!DB.check_user_from_to_q(qId, uId))
//			/* error: Question ID doesn't seem to exist for this user */
//			error.print(4);
//		else
//			break;
//	}
//	DB.questionsDb.delete_q(qId);
//	std::cout << "\n\n ----- Question Deleted -----\n\n";
// }

// void App::list_users()
//{
//	DbManager DB;
//	DB.usersDb.print();
// }

// void App::print_feed()
//{
//	/* vector to store answered questions */
//	std::vector<Question> qv;
//	DbManager DB;
//	qv = DB.questionsDb.feed();
//	for (Question &q : qv)
//		q.print_feed();
// }
