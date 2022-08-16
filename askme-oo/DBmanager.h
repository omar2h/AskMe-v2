/*
 * DBmanager.h
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#ifndef DBMANAGER_H_
#define DBMANAGER_H_
#include "Usersdb.h"

#include <iostream>
#include <vector>

class User;

class DBmanager {
	UsersDb usersdb;

	void read_file_lines(std::string path, std::vector<std::string> &lines);
	void write_file_lines(std::string path, std::vector<std::string> &lines, bool append);
	void split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del);
public:
	DBmanager();
	virtual ~DBmanager();

	User get_user_login(std::string username, std::string password);
	void signup_user();
	void add_user(User& user);
	int generate_id(const std::string path);
};

#endif /* DBMANAGER_H_ */
