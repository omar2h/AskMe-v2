/*
 * DBmanager.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#include "DBmanager.h"
#include "User.h"


#include <fstream>
DBmanager::DBmanager() {
	// TODO Auto-generated constructor stub

}

DBmanager::~DBmanager() {
	// TODO Auto-generated destructor stub
}

User DBmanager::get_user_login(std::string username, std::string password){
	User user;
	const std::string path = usersdb.get_path();
	const std::string del = usersdb.get_delimiter();
	std::vector<std::string> lines;
	read_file_lines(path, lines);
	for (auto &line : lines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		if(usersdb.check_user_login(v, user, username, password))
			return user;
	}
	throw 2;
}

void DBmanager::add_user(User& user){
	const std::string path = usersdb.get_path();
	try{
	user.setId(generate_id(path));
	}
	catch(const int err){
		throw;
	}
	std::vector<std::string> lines;
	std::string line = user.getIdString() + DELIMITER + user.getUsername() + DELIMITER + user.getPassword() + DELIMITER + user.getAllowAnonQsString();
	lines.push_back(line);
	try{
	write_file_lines(path, lines, true);
	}
	catch(const int err){
		throw;
	}
}

void DBmanager::read_file_lines(std::string path, std::vector<std::string> &lines)
{
	std::fstream file_handler(path.c_str());
	if (file_handler.fail())
	{
		throw "Can't open file";
	}

	std::string line;
	/* check if file is empty */
	if (file_handler.peek() == std::ifstream::traits_type::eof())
	{
		file_handler.close();
		return;
	}

	while (getline(file_handler, line))
	{
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
}

void DBmanager::write_file_lines(std::string path, std::vector<std::string> &lines, bool append = true)
{
	auto status = std::ios::in | std::ios::out | std::ios::app;

	if (!append)
		status = std::ios::in | std::ios::out | std::ios::trunc; // overwrite

	std::fstream file_handler(path.c_str(), status);

	if (file_handler.fail())
	{
		throw 5;
	}
	for (auto line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

void DBmanager::split_line_toVector(std::string line, std::vector<std::string> &v, const std::string del)
{
	int pos = 0;
	std::string substr;
	while ((pos = (int)line.find(del)) != -1)
	{
		substr = line.substr(0, pos);
		v.push_back(substr);
		line.erase(0, pos + (int)del.size());
	}
	v.push_back(line);
}

int DBmanager::generate_id(const std::string path)
{
	std::vector<std::string> lines;
	try{
	read_file_lines(path, lines);
	}
	catch(const int err){
		throw;
	}

	std::vector<std::string> v;
	const int linesSize = (int)lines.size();
	if (linesSize)
	{
		split_line_toVector(lines[linesSize - 1], v, DELIMITER);
		return stoi(v[ID]) + 1;
	}
	return 1;
}
