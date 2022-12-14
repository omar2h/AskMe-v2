/*
 * UsersDb.h
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#ifndef USERSDB_H_
#define USERSDB_H_
#include <iostream>
#include <vector>
class User;

#ifndef USERSTXT_PATH
#define USERSTXT_PATH "users.txt"
#define DELIMITER ","
#define ID 0
#define USERNAME 1
#define PASSWORD 2
#define ALLOW_ANON_Q 3
#define USER_ITEMS 4
#endif

class UsersDb
{
	std::string path;
	std::string del;
	//	/**
	//		 * get user from db
	//		 *
	//		 * @param user id
	//		 * @return pair of user and bool if user is found via id
	//		 */
	//		std::pair<User, bool> get_user(const int id);
	//
	//		/**
	//		 * save user to db
	//		 *
	//		 * @param user to save
	//		 * @return bool whether user is saved or not
	//		 */
	//		bool add_user(User &);
	//
	//		/**
	//		 * get user from db using username and password
	//		 *
	//		 * @param User having username and password
	//		 * @return pair of user and bool if user is found via username and password
	//		 */
	//		std::pair<User, bool> get_user_login(const std::string, const std::string);
	//
	//		/**
	//		 * print all users id and username
	//		 *
	//		 * @param non
	//		 * @return non
	//		 */
	//		void print();
public:
	UsersDb();
	virtual ~UsersDb();

	std::string get_path();
	std::string get_delimiter();
	bool check_user_login(const std::vector<std::string> &v, User &user, const std::string username, const std::string password);
	std::string get_user_string(User &);

	bool get_user(const std::vector<std::string> &v, User &);
};

#endif /* USERSDB_H_ */
