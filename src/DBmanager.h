/*
 * DBmanager.h
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#ifndef DBMANAGER_H_
#define DBMANAGER_H_
#include "UsersDb.h"
#include "QuestionsDb.h"
#include "Question.h"
#include <iostream>
#include <vector>
#include <map>

#define TEMPTXT_PATH "temp.txt"
#define FROM 1
#define TO 2
#define FROM_TO 3

class User;

class DBmanager
{
	UsersDb usersdb;
	QuestionsDb questionsdb;

	void read_file_lines(std::string path, std::vector<std::string> &lines);
	void write_file_lines(std::string path, std::vector<std::string> &lines, bool append);
	void split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del);

	void del_q_from_file(const int qId);

public:
	DBmanager();
	virtual ~DBmanager();

	User get_user_login(std::string username, std::string password);
	void signup_user();
	void add_user(User &user);
	void get_Qs_to_user(const int uId, GRAPH &);
	void get_Qs_from_user(const int uId, std::vector<Question> &qv);
	bool check_user_has_q(const int qId, const int uId, const int dir, Question &q, const bool isQ);
	Question get_q(const int qId, const int uId, const int dir);
	Question get_question(const int id);
	void update_answer(const int qId, const std::string &ans);
	void del_q(const int qId, const int uId);
	int generate_id(const std::string path);
	void get_user(User &user);
	void add_question(Question &q);
	void print_users();
	std::vector<Question> get_answered_Qs();
};

#endif /* DBMANAGER_H_ */
