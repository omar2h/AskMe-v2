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
class User;

class DBmanager
{
	UsersDb usersdb;
	QuestionsDb questionsdb;

	void read_file_lines(std::string path, std::vector<std::string> &lines);
	void write_file_lines(std::string path, std::vector<std::string> &lines, bool append);
	void split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del);

public:
	DBmanager();
	virtual ~DBmanager();

	User get_user_login(std::string username, std::string password);
	void signup_user();
	void add_user(User &user);
	void get_Qs_to_user(const int uId, std::map<int, std::vector<Question>> &);
	void get_Qs_from_user(const int uId, std::vector<Question> &qv);
	Question get_q_toUser(const int qId, const int uId);
	Question get_question(const int id);
	void update_answer(const Question&);
	int generate_id(const std::string path);
};

#endif /* DBMANAGER_H_ */
