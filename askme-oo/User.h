/*
 * User.h
 *
 *  Created on: Aug 10, 2022
 *      Author: omarh
 */

#ifndef USER_H_
#define USER_H_
#include <iostream>

class User {
/* id, username, password, allow anon questions bool */
	int id{};
	std::string username{}, password{};
	bool allowAnonQs{};

public:
	User();
	virtual ~User();

	int getId();
	std::string getIdString();
	std::string getUsername();
	std::string getPassword();
	bool getAllowAnonQs();
	std::string getAllowAnonQsString();
	void setId(const int id);
	void setId(std::string id);
	void setUsername(const std::string username);
	void setPassword(const std::string password);
	void setAllowAnonQs(const bool allowAnonQs);
	void setAllowAnonQs(std::string allowAnonQs);
};

#endif /* USER_H_ */
