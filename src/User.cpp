/*
 * User.cpp
 *
 *  Created on: Aug 10, 2022
 *      Author: omarh
 */

#include "User.h"

User::User()
{
	// TODO Auto-generated constructor stub
	id = -1;
	username = "";
	password = "";
	allowAnonQs = 0;
}

User::~User()
{
	// TODO Auto-generated destructor stub
}

int User::getId() const
{
	return id;
}
std::string User::getIdString() const
{
	return std::to_string(id);
}
std::string User::getUsername() const
{
	return username;
}
std::string User::getPassword() const
{
	return password;
}
bool User::getAllowAnonQs() const
{
	return allowAnonQs;
}
std::string User::getAllowAnonQsString() const
{
	return std::to_string(allowAnonQs);
}
void User::setId(const int id)
{
	this->id = id;
}
void User::setId(std::string id)
{
	this->id = stoi(id);
}
void User::setUsername(const std::string username)
{
	this->username = username;
}
void User::setPassword(const std::string password)
{
	this->password = password;
}
void User::setAllowAnonQs(const bool allowAnonQs)
{
	this->allowAnonQs = allowAnonQs;
}
void User::setAllowAnonQs(std::string allowAnonQs)
{
	this->allowAnonQs = stoi(allowAnonQs);
}
