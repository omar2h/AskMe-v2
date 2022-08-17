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

	int getId() const;
	std::string getIdString() const;
	std::string getUsername() const;
	std::string getPassword() const;
	bool getAllowAnonQs() const;
	std::string getAllowAnonQsString() const;
	void setId(const int id);
	void setId(std::string id);
	void setUsername(const std::string username);
	void setPassword(const std::string password);
	void setAllowAnonQs(const bool allowAnonQs);
	void setAllowAnonQs(std::string allowAnonQs);
};

#endif /* USER_H_ */
