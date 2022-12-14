#include "QuestionsDb.h"
#include "Question.h"
#include <algorithm>
#include <string>
QuestionsDb::QuestionsDb() : path(QUESTIONSTXT_PATH), del(DELIMITER)
{
	// TODO Auto-generated constructor stub
}

QuestionsDb::~QuestionsDb()
{
	// TODO Auto-generated destructor stub
}

std::string QuestionsDb::get_path()
{
	return path;
}

const char *QuestionsDb::get_pathChar()
{
	return path.c_str();
}

std::string QuestionsDb::get_delimiter()
{
	return del;
}

void QuestionsDb::get_Q_toUser(const std::vector<std::string> &v, GRAPH &graph, const int uId)
{
	if (!v[TO_ID].empty() && std::all_of(v[TO_ID].begin(), v[TO_ID].end(), ::isdigit) && stoi(v[TO_ID]) == uId)
	{
		int qId = stoi(v[ID]);
		int threadId = stoi(v[THREAD_ID]);
		graph[qId] = {};
		if (threadId != -1)
			graph[threadId].push_back(qId);
	}
}

void QuestionsDb::get_Q_fromUser(const std::vector<std::string> &v, std::vector<Question> &qv, const int uId)
{
	Question q;
	if (!v[FROM_ID].empty() && std::all_of(v[FROM_ID].begin(), v[FROM_ID].end(), ::isdigit) && stoi(v[FROM_ID]) == uId)
	{
		update_question_info(v, q);
		qv.push_back(q);
	}
}

bool QuestionsDb::get_Q(const std::vector<std::string> &v, Question &q, const int qId)
{
	if (stoi(v[ID]) == qId)
	{
		update_question_info(v, q);
		return 1;
	}
	return 0;
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

void QuestionsDb::get_writeLines(std::vector<std::string> &writeLines, std::vector<std::string> &v, const int qId, const int op, const std::string &ans)
{
	std::string writeLine{};

	if (op == DELETE && (stoi(v[ID]) == qId || stoi(v[THREAD_ID]) == qId))
	{
		return;
	}
	else if (op == ANSWER && stoi(v[ID]) == qId)
	{
		v[ANSWERED_BOOL] = "1";
		v[ANSWERTEXT] = ans;
	}

	for (int i = 0; i < (int)v.size(); i++)
	{
		if (i)
			writeLine += del;
		writeLine += v[i];
	}

	writeLines.push_back(writeLine);
}

std::string QuestionsDb::get_question_string(const Question &q)
{
	return q.getIdString() + del + q.getThreadIdString() + del + q.getFromIdString() + del + q.getToIdString() + del + q.getAnonString() + del + q.getAnsweredString() + del + q.getText() + del + q.getAns();
}
