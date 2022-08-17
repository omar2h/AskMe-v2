/*
 * UsersDb.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#include "UsersDb.h"
#include "User.h"

UsersDb::UsersDb() : path(USERSTXT_PATH), del(DELIMITER) {
	// TODO Auto-generated constructor stub

}

UsersDb::~UsersDb() {
	// TODO Auto-generated destructor stub
}

std::string UsersDb::get_path(){
	return path;
}

std::string UsersDb::get_delimiter(){
	return del;
}
//std::pair<User, bool> UsersDb::get_user(const int id)
//{
//	User user;
//	DbManager dbManager;
//	std::pair<User, bool> userPair;
//	userPair.second = 0;
//
//	const std::string path = USERSTXT_PATH;
//	std::vector<std::string> lines;
//	dbManager.read_file_lines(path, lines);
//
//	for (auto &line : lines)
//	{
//		std::vector<std::string> v;
//		dbManager.split_line_toVector(line, v, DELIMITER);
//
//		if (stoi(v[ID]) == id)
//		{
//			user.id = stoi(v[ID]);
//			user.allowAnonQs = stoi(v[ALLOW_ANON_Q]);
//			userPair.first = user;
//			userPair.second = 1;
//			return userPair;
//		}
//	}
//	return userPair;
//}

bool UsersDb::check_user_login(std::vector<std::string>& v, User& user, const std::string username, const std::string password)
{
	if (username == v[USERNAME] && password == v[PASSWORD])
	{
		user.setId(v[ID]);
		user.setUsername(username);
		user.setAllowAnonQs(v[ALLOW_ANON_Q]);
		return true;
	}
	return false;
}

std::string UsersDb::get_user_string(User& user){
	return user.getIdString() + del + user.getUsername() + del + user.getPassword() + del + user.getAllowAnonQsString();
}

//bool UsersDb::add_user(User &user)
//{
//	DbManager dbManager;
//	user.id = dbManager.generate_id(USERSTXT_PATH);
//	std::vector<std::string> lines;
//	std::string line = std::to_string(user.id) + DELIMITER + user.username + DELIMITER + user.password + DELIMITER + std::to_string(user.allowAnonQs) + '\n';
//	lines.push_back(line);
//	return dbManager.write_file_lines(USERSTXT_PATH, lines, true);
//}
//
//void UsersDb::print()
//{
//	DbManager dbManager;
//	const std::string path = "users.txt";
//	std::vector<std::string> lines;
//	dbManager.read_file_lines(path, lines);
//
//	for (auto &line : lines)
//	{
//		std::vector<std::string> v;
//		dbManager.split_line_toVector(line, v, DELIMITER);
//		std::cout << "ID: " << v[ID] << "\tUserName: " << v[USERNAME] << '\n';
//	}
//	std::cout << '\n';
//}

