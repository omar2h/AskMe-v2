/*
 * AppMainMenu.cpp
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#include "AppMainMenu.h"
#include "DBmanager.h"
#include "User.h"
#include "Question.h"
#include "Inputscanner.h"

AppMainMenu::AppMainMenu()
{
	// TODO Auto-generated constructor stub
}

AppMainMenu::~AppMainMenu()
{
	// TODO Auto-generated destructor stub
}

void AppMainMenu::run(int choice, User &user)
{
	if (choice == PRINT_QUESTIONS_RECEIVED)
	{
		print_questions_received(user.getId());
	}
	else if (choice == PRINT_QUESTIONS_ASKED)
	{
		print_questions_asked(user.getId());
	}
	else if (choice == ANSWER)
	{
		answer(user.getId());
	}
	else if (choice == DELETE)
	{
		delete_question(user.getId());
	}
	else if (choice == ASK)
	{
		ask(user.getId());
	}
	else if (choice == LIST_USERS)
	{
		list_users();
	}
	else if (choice == FEED)
	{
		print_feed();
	}
}

void AppMainMenu::print_questions_received(const int uId)
{
	DBmanager DB;
	/* map variable to store questions where the id is the key and vector of questions beginning with the questions followed by its children if any */
	std::map<int, std::vector<Question>> mp;
	/* Fill the map with all question the user received */
	DB.get_Qs_to_user(uId, mp);

	for (auto &[key, val] : mp)
	{
		/* if is a parent question then print the children */
		if (val[0].getThreadId() == -1)
		{
			int spaces = 0;
			val[0].print();
			for (int i = 1; i < (int)val.size(); i++)
			{
				/* at each child question increase space by 2 to distinguish from parent question */
				print_children(mp[val[i].getId()], mp, spaces + 2);
			}
			std::cout << '\n';
		}
	}
}

void AppMainMenu::print_questions_asked(const int uId)
{
	DBmanager DB;
	/* vector variable to store questions user asked */
	std::vector<Question> qv;
	/* fill vector with questions asked only */
	DB.get_Qs_from_user(uId, qv);

	// c++ 17 syntax
	for (auto &q : qv)
	{
		/* print question in an asked format */
		q.print_asked();
	}
}

void AppMainMenu::answer(const int uId)
{
	DBmanager DB;
	Question q;
	int qId;
	/* user enter question to answer */
	while (1)
	{
		std::cout << "Enter question id to answer or -1 to cancel: ";
		std::cin >> qId;

		if (qId == -1)
			return;
		/* check whether user received this question or not. can only answer if it is received */
		try
		{
			q = DB.get_q(qId, uId, TO);
			break;
		}
		catch (const int err)
		{
			throw;
		}
	}
	q.print();
	if (q.getAnswered())
		std::cout << "\n--- Warning: Question already answered. Answer will be overwritten ---\n\n";
	std::cin.ignore();
	/* enter answer */
	std::cout << "Enter answer: ";
	std::string ans;
	std::getline(std::cin, ans);
	DB.update_answer(qId, ans);
	std::cout << "\n\n---- Answer Saved ----\n\n";
}

void AppMainMenu::delete_question(const int uId)
{
	DBmanager DB;
	Question q;
	int qId;

	/* enter question id */
	while (1)
	{
		std::cout << "Enter question id to delete or -1 to cancel: ";
		std::cin >> qId;

		if (qId == -1)
			return;

		/* user can only delete question asked or received by user */
		try
		{
			DB.del_q(qId, uId);
			break;
		}
		catch (const int err)
		{
			throw;
		}
	}
	std::cout << "\n\n ----- Question Deleted -----\n\n";
}

void AppMainMenu::ask(const int uId)
{
	DBmanager DB;
	Input_scanner input_scanner;
	/* variable to store new question asked by user */
	Question q;
	/* variable to store the user being asked */
	User toUser;
	int toUserId;
	/* update question fromId to the current user's id */
	q.setFromId(uId);

	/* Enter toUser id */
	while (1)
	{
		std::cout << "Enter User ID You Want to Ask or -1 to cancel:  ";
		std::cin >> toUserId;
		if (toUserId == -1)
			return;

		toUser.setId(toUserId);
		/* check whether user exists then. user is sent by reference so it is updated */
		/* sending user as a parameter not just the id to check later if it allows anon questions or not*/
		try
		{
			DB.get_user(toUser);
			break;
		}
		catch (const int err)
		{
			throw;
		}
		/* print error User ID doesn't seem to exist */
	}
	q.setToId(toUser.getId());

	/* check the user being asked if it allows anon questions and print a disclaimer if it does not*/
	if (!toUser.getAllowAnonQs())
	{
		q.setAnon(false);
		std::cout << "Note: This User doesn't Allow Anonymous Questions\n";
	}
	int qId;

	/* enter question id */
	while (1)
	{
		std::cout << "Enter question thread ID or -1 to Ask a New Question: ";
		std::cin >> qId;
		/* only if user allow anon questions you can ask anon questions*/
		if (toUser.getAllowAnonQs())
		{
			while (1)
			{
				char c;
				std::cout << "Keep this Question Anonymous? (y/n): ";
				std::cin >> c;
				if (c == 'y')
				{
					q.setAnon(true);
					break;
				}
				if (c == 'n')
				{
					q.setAnon(false);
					break;
				}
			}
		}
		if (qId == -1)
		{
			q.setText(input_scanner.get_qText_from_user()), q.setThreadId(-1), q.setAnswered(false);
			break;
		}
		else
		{
			/* if it is not parent question then check whether the user being asked has the parent thread or not*/
			try
			{
				DB.check_user_has_q(qId, toUserId, TO, q, true);
				q.setThreadId(qId), q.setAnswered(false);
				q.setText(input_scanner.get_qText_from_user());
				break;
			}
			catch (const int err)
			{
				throw;
			}
		}
	}

	DB.add_question(q);
	std::cout << "\n\n--------- Question Saved ----------\n\n";
}

void AppMainMenu::list_users()
{
	DBmanager DB;
	DB.print_users();
}

void AppMainMenu::print_feed()
{
	DBmanager DB;
	std::vector<Question> qv;
	qv = DB.get_answered_Qs();

	for (const Question &q : qv)
		q.print_answered();
}
