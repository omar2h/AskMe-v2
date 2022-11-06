# AskMe-v2
![image](https://user-images.githubusercontent.com/29601694/199635081-6be78934-359c-4447-8dea-5a41ffce9f51.png)

AskMe is a Ask.fm clone project. It is a social media platform where you may ask questions -anonymously- and answer questions from other individuals you may find interesting. This a file-based program using OOP concepts and applying the graph theory and traversal to display the questions threads.
## Video
https://youtu.be/Om2koglw6bc
## Requirements
1. User should be able to ask other users questions anonymously.
2. User should be able to answer a question received.
3. User should be able to print questions received.
4. User should be able to print questions the user asked.
5. User should be able to to delete any question received and questions the user asked.

## Activity Diagram
User ask a question </br>
![image](https://user-images.githubusercontent.com/29601694/200147637-b3e6726d-ab46-45c8-8785-d7f9d9328468.png)

## Database
The database is consisted of users and questions classes which are saved in two files users.txt and questions.txt.
* User class is composed of multiple variables: id, username, password and allowAnonymousQuestions.
* Question class is composed of multiple variables and functions: id, threadId, fromId, toId, anonymous question?, answered?, question text, answer text.<br />
Variables are saved in files separeted with a comma.<br />
The frontend access the database using a class called DbManager. Within the DbManager there are UsersDb and QuestionsDb.<br/>

## Graphs Application
In displaying the questions received to the users. Firstly, build the graph from the questions received in files. then depth first search to display the questions. Using visited unordered_set to avoid printing question more than one.
```
void AppMainMenu::print_questions_received(const int uId) const
{
	DBmanager DB;
	/* adjacency list */
	GRAPH graph;
	/* Build graph with all questions the user received */
	DB.get_Qs_to_user(uId, graph);

	Question q{};
	std::unordered_set<int> visited{};
	for (auto const &[key, val] : graph)
	{
		if (!visited.count(key))
		{
			dfs(graph, key, visited, DB, uId, 0);
			std::cout << "\n";
		}
	}
}
```
```
void AppMainMenu::dfs(const GRAPH &graph, int key, std::unordered_set<int> &visited, DBmanager &DB, int uId, int spaces) const
{
	visited.insert(key);
	Question q = DB.get_q(key, uId, TO);
	QuestionPrinter::printQuestion(q, spaces);
	for (const int &neighbourQuestionId : graph.at(key))
	{
		if (!visited.count(neighbourQuestionId))
			dfs(graph, neighbourQuestionId, visited, DB, uId, spaces + 2);
	}
}
```
## Features
1. Signup and LogIn. For the user to access the following features of the program the user has to be logged in. User choose either to signup or login.
    * For the SignUp option: User should provide a username followed by a password. An id is automatically generated for the user. Then the user asked whether he would like to accept anonymous questions or not.
    * For the logIn option: User enter credentials which are authanticated and compared to our database.
2. Print questions received. Any question the user was asked, is printed in a chronological order and in a parent child format.
3. Print questions asked.
4. Answer questions. User can answer only the questions he/she was asked, hence the user is asked to provide a question id which is then checked whether the user was asked before or not. In addition, if a question is already answered, the answer would be overwritten.
5. Delete questions. User can delete only the question he/she has received or asked, hence the user is asked to provide a question id which is then checked whether the user was asked before or not. In addition if the question happens to be a parent question, all the thread would be deleted.
6. Ask questions. User can ask questions to other people firstly, the id of the other user to be asked is entered to check if exists. Then user choose to ask a fresh new question or enter an id of an existing question to be added in its thread.
7. List users
8. Print feed. Print only answered questions.

 
