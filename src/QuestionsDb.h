/*
 * QuestionsDb.h
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#ifndef QUESTIONSDB_H_
#define QUESTIONSDB_H_

#include "graph.h"
#include <iostream>
#include <vector>
#include <map>

class Question;

#ifndef QUESTIONSTXT_PATH
#define QUESTIONSTXT_PATH "questions.txt"
#define DELIMITER ","
#define QUESTION_ITEMS 8
#define ID 0
#define THREAD_ID 1
#define FROM_ID 2
#define TO_ID 3
#define ANONQ 4
#define ANSWERED_BOOL 5
#define QTEXT 6
#define ANSWERTEXT 7
#endif

#ifndef ANSWER
#define ANSWER 1
#define DELETE 0
#endif

class QuestionsDb
{
	std::string path;
	std::string del;

public:
	QuestionsDb();
	virtual ~QuestionsDb();

	std::string get_path();
	const char *get_pathChar();
	std::string get_delimiter();
	void update_question_info(const std::vector<std::string> &v, Question &q);
	void get_Q_toUser(const std::vector<std::string> &, GRAPH &, const int uId);
	void get_Q_fromUser(const std::vector<std::string> &v, std::vector<Question> &qv, const int uId);
	bool get_Q(const std::vector<std::string> &v, Question &q, const int qId);
	void get_writeLines(std::vector<std::string> &writeLines, std::vector<std::string> &v, const int id, const int op, const std::string &ans = "");
	std::string get_question_string(const Question &q);
};

#endif /* QUESTIONSDB_H_ */
