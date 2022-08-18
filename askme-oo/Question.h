/*
 * Question.h
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#ifndef QUESTION_H_
#define QUESTION_H_

#include <iostream>
#include <vector>
#include <map>

class Question
{
	/* id, threadId, fromId, toId, anonymous question?, answered?, question text, answer text */
	int id{}, threadId{}, fromId{}, toId{};
	bool anon{}, answered{};
	std::string text{}, ans{};

public:
	Question();
	virtual ~Question();

	int getId() const;
	std::string getIdString() const;
	int getThreadId() const;
	std::string getThreadIdString() const;
	int getFromId() const;
	std::string getFromIdString() const;
	int getToId() const;
	std::string getToIdString() const;
	bool getAnon() const;
	std::string getAnonString() const;
	bool getAnswered() const;
	std::string getAnsweredString() const;
	std::string getText() const;
	std::string getAns() const;

	void setId(const int id);
	void setId(std::string id);
	void setThreadId(const int);
	void setThreadId(std::string);
	void setFromId(const int);
	void setFromId(std::string);
	void setToId(const int);
	void setToId(std::string);
	void setAnon(const bool);
	void setAnon(std::string);
	void setAnswered(const bool);
	void setAnswered(std::string);
	void setText(std::string);
	void setAns(std::string);

	void print() const;
	void print_asked() const;
	void print_child(int space) const;
};

void print_children(std::vector<Question> qv, std::map<int, std::vector<Question>> &mp, int spaces);
#endif /* QUESTION_H_ */
