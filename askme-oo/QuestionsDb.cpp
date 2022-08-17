/*
 * QuestionsDb.cpp
 *
 *  Created on: Aug 17, 2022
 *      Author: omarh
 */

#include "QuestionsDb.h"
#include "Question.h"

#include <algorithm>

QuestionsDb::QuestionsDb() : path(QUESTIONSTXT_PATH), del(DELIMITER){
	// TODO Auto-generated constructor stub


}

QuestionsDb::~QuestionsDb() {
	// TODO Auto-generated destructor stub
}

std::string QuestionsDb::get_path(){
	return path;
}

std::string QuestionsDb::get_delimiter(){
	return del;
}

void QuestionsDb::get_Q_toUser(const std::vector<std::string>& v, std::map<int, std::vector<Question>>& mp, const int uId){
	Question q;
	if (!v[TO_ID].empty() && std::all_of(v[TO_ID].begin(), v[TO_ID].end(), ::isdigit) && stoi(v[TO_ID]) == uId)
	{
		update_question_info(v, q);
		if (q.getThreadId() == -1)
			mp[q.getId()].push_back(q);
		else
		{
			mp[q.getId()].push_back(q);
			mp[q.getThreadId()].push_back(q);
		}
	}
}

void QuestionsDb::get_Q_fromUser(const std::vector<std::string>& v, std::vector<Question>& qv, const int uId){
	Question q;
	if (!v[FROM_ID].empty() && std::all_of(v[FROM_ID].begin(), v[FROM_ID].end(), ::isdigit) && stoi(v[FROM_ID]) == uId)
	{
		update_question_info(v, q);
		qv.push_back(q);
	}
}


void QuestionsDb::update_question_info(const std::vector<std::string> &v, Question &q)
{
	q.setId(v[ID]);
	q.setThreadId(v[THREAD_ID]);
	q.setFromId(v[FROM_ID]);
	q.setToId(v[TO_ID]);
	q.setAnon(v[ANONQ]);
	q.setAnswered(v[ANSWERED_BOOL]);
	q.setText(v[QTEXT]);
	q.setAns(v[ANSWERTEXT]);
}
