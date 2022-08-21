/*
 * DBmanager.cpp
 *
 *  Created on: Aug 14, 2022
 *      Author: omarh
 */

#include "DBmanager.h"
#include "User.h"

#include <fstream>
DBmanager::DBmanager()
{
	// TODO Auto-generated constructor stub
}

DBmanager::~DBmanager()
{
	// TODO Auto-generated destructor stub
}

User DBmanager::get_user_login(std::string username, std::string password)
{
	User user;
	const std::string path = usersdb.get_path();
	const std::string del = usersdb.get_delimiter();
	std::vector<std::string> lines;
	try
	{
		read_file_lines(path, lines);
	}
	catch (const int err)
	{
		throw;
	}
	for (auto &line : lines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		if (usersdb.check_user_login(v, user, username, password))
			return user;
	}
	throw 2;
}

void DBmanager::add_user(User &user)
{
	const std::string path = usersdb.get_path();
	try
	{
		user.setId(generate_id(path));
	}
	catch (const int err)
	{
		throw;
	}
	std::vector<std::string> lines;
	std::string line = usersdb.get_user_string(user);
	lines.push_back(line);
	try
	{
		write_file_lines(path, lines, true);
	}
	catch (const int err)
	{
		throw;
	}
}

void DBmanager::get_Qs_to_user(const int uId, std::map<int, std::vector<Question>> &mp)
{
	const std::string path = questionsdb.get_path();
	const std::string del = questionsdb.get_delimiter();
	std::vector<std::string> lines;
	try
	{
		read_file_lines(path, lines);
	}
	catch (const int err)
	{
		throw;
	}
	for (auto &line : lines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		questionsdb.get_Q_toUser(v, mp, uId);
	}
}

void DBmanager::get_Qs_from_user(const int uId, std::vector<Question> &qv)
{
	const std::string path = questionsdb.get_path();
	const std::string del = questionsdb.get_delimiter();
	std::vector<std::string> lines;
	try
	{
		read_file_lines(path, lines);
	}
	catch (const int err)
	{
		throw;
	}
	for (auto &line : lines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		questionsdb.get_Q_fromUser(v, qv, uId);
	}
}

Question DBmanager::get_q_toUser(const int qId, const int uId)
{
	Question q;
	/* pair to store question and bool whether exist or not */
	try
	{
		q = get_question(qId);
	}
	catch(const int err)
	{
		throw;
	}
	/* check if q toId is the same as user id signifying user received question*/
	if (q.getToId() != uId)
		throw 4;
	return q;
}

Question DBmanager::get_q_from_toUser(const int qId, const int uId)
{
	Question q;
	/* pair to store question and bool whether exist or not */
	try
	{
		q = get_question(qId);
	}
	catch(const int err)
	{
		throw;
	}
	/* check if q toId is the same as user id signifying user received question*/
	if (q.getToId() != uId || q.getFromId() != uId)
		throw 4;
	return q;
}

void DBmanager::update_answer(const int qId, const std::string& ans){
	const char* path = questionsdb.get_pathChar();
	const char* tempPath = TEMPTXT_PATH;
	const std::string del = questionsdb.get_delimiter();
	std::vector<std::string> readLines, writeLines;
	read_file_lines(path, readLines);

	for (auto const &line : readLines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		questionsdb.get_writeLines(writeLines, v, ans, qId, ANSWER);
	}
	write_file_lines(tempPath, writeLines, false);
	remove(path);
	rename(tempPath, path);
}

//void DBmanager::del_q(const int qId, const int uId)
//{
//	Question q;
//	/* user can only delete question asked or received by user */
//	try
//	{
//		q = get_q_from_toUser(qId, uId);
//	}
//	catch(const int err)
//	{
//		throw;
//	}
//
//
//}

//void DBmanager::del_q_from_file()
//{
//	const char* path = questionsdb.get_pathChar();
//	const char* tempPath = TEMPTXT_PATH;
//	const std::string del = questionsdb.get_delimiter();
//	const int id = q.getId();
//	std::vector<std::string> readLines, writeLines;
//	read_file_lines(path, readLines);
//
//	for (auto const &line : readLines)
//	{
//		std::vector<std::string> v;
//		split_line_toVector(line, v, del);
//		questionsdb.get_writeLines(writeLines, v, q, id);
//	}
//	write_file_lines(tempPath, writeLines, false);
//	remove(path);
//	rename(tempPath, path);
//}

Question DBmanager::get_question(const int id)
{
	const std::string path = questionsdb.get_path();
	const std::string del = questionsdb.get_delimiter();
	Question q;
	std::vector<std::string> lines;

	try
	{
		read_file_lines(path, lines);
	}
	catch (const int err)
	{
		throw;
	}

	for (auto &line : lines)
	{
		std::vector<std::string> v;
		split_line_toVector(line, v, del);
		if(questionsdb.get_Q(v, q, id))
			return q;
	}
	throw 6;
}

void DBmanager::read_file_lines(std::string path, std::vector<std::string> &lines)
{
	std::fstream file_handler(path.c_str());
	if (file_handler.fail())
	{
		throw 5;
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
	try
	{
		read_file_lines(path, lines);
	}
	catch (const int err)
	{
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
