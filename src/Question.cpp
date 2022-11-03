/*
 * Question.cpp
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#include "Question.h"
#include <string>
Question::Question() : id(-1), threadId(-1), fromId(-1), toId(-1), anon(0), answered(0), text(""), ans("")
{
	// TODO Auto-generated constructor stub
}

Question::~Question()
{
	// TODO Auto-generated destructor stub
}

int Question::getId() const
{
	return id;
}
std::string Question::getIdString() const
{
	return std::to_string(id);
}
int Question::getThreadId() const
{
	return threadId;
}
std::string Question::getThreadIdString() const
{
	return std::to_string(threadId);
}
int Question::getFromId() const
{
	return fromId;
}
std::string Question::getFromIdString() const
{
	return std::to_string(fromId);
}
int Question::getToId() const
{
	return toId;
}
std::string Question::getToIdString() const
{
	return std::to_string(toId);
}
bool Question::getAnon() const
{
	return anon;
}
std::string Question::getAnonString() const
{
	return std::to_string(anon);
}
bool Question::getAnswered() const
{
	return answered;
}
std::string Question::getAnsweredString() const
{
	return std::to_string(answered);
}
std::string Question::getText() const
{
	return text;
}
std::string Question::getAns() const
{
	return ans;
}

void Question::setId(const int id)
{
	this->id = id;
}
void Question::setId(std::string id)
{
	this->id = stoi(id);
}
void Question::setThreadId(const int threadId)
{
	this->threadId = threadId;
}
void Question::setThreadId(std::string threadId)
{
	this->threadId = stoi(threadId);
}
void Question::setFromId(const int fromId)
{
	this->fromId = fromId;
}
void Question::setFromId(std::string fromId)
{
	this->fromId = stoi(fromId);
}
void Question::setToId(const int toId)
{
	this->toId = toId;
}
void Question::setToId(std::string toId)
{
	this->toId = stoi(toId);
}
void Question::setAnon(const bool anon)
{
	this->anon = anon;
}
void Question::setAnon(std::string anon)
{
	this->anon = stoi(anon);
}
void Question::setAnswered(const bool answered)
{
	this->answered = answered;
}
void Question::setAnswered(std::string answered)
{
	this->answered = stoi(answered);
}
void Question::setText(std::string text)
{
	this->text = text;
}
void Question::setAns(std::string ans)
{
	this->ans = ans;
}
