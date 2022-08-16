/*
 * App.h
 *
 *  Created on: Aug 10, 2022
 *      Author: omarh
 */

#ifndef APP_H_
#define APP_H_


class App {
private:
//	/**
//	 * verify choice between low and high inclusive
//	 *
//	 * @param user choice
//	 * @return whether choice is correct or not
//	 */
//	bool verify_choice(const int choice, const int low, const int high);
//
//	/**
//	 * prompt user to enter question text
//	 *
//	 * @param non
//	 * @return question text
//	 */
//	std::string get_qText_from_user();
//
//	/**
//	 * run main menu
//	 *
//	 * @param Logged in user
//	 * @return non
//	 */
//	void main_menu(User &);
//
//	/**
//	 * ask question
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void ask(User &);
//
//	/**
//	 * answer (if there is an answer it would be overwritten)
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void answer(const int);
//
//	/**
//	 * delete a question or thread
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void delete_question(const int);
//
//	/**
//	 * display questions user received
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void print_questions_received(const int);
//
//	/**
//	 * display questions asked by user
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void print_questions_asked(const int);
//
//	/**
//	 * display list of system users
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void list_users();
//
//	/**
//	 * display feed (Answered questions for all users)
//	 *
//	 * @param non
//	 * @return non
//	 */
//	void print_feed();
public:
	App();
	virtual ~App();

	/**
	 * Main app run function
	 *
	 * @param non
	 * @return non
	 */
	void run();


};

#endif /* APP_H_ */
