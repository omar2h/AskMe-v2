# AskMe-v2
![image](https://user-images.githubusercontent.com/29601694/199635081-6be78934-359c-4447-8dea-5a41ffce9f51.png)

AskMe is a Ask.fm clone project. It is a social media platform where you may ask questions -anonymously- and answer questions from other individuals you may find interesting. This program is based on the Graph theory to store and print questions. 

## Requirements
1. User should be able to ask other users questions anonymously.
2. User should be able to answer a question received.
3. User should be able to print questions received.
4. User should be able to print questions the user asked.
5. User should be able to to delete any question received and questions the user asked.

## Backend
The database is consisted of users and questions classes which are saved in two files users.txt and questions.txt.
* A User structure is composed of multiple variables: id, username, password and allowAnonymousQuestions.
* A Question structure is composed of multiple variables and functions: id, threadId, fromId, toId, anonymous question?, answered?, question text, answer text.<br />
Variables are saved in files separeted with a comma.<br />
The frontend access the database using a class called DbManager. Within the DbManager there are UsersDb and QuestionsDb.<br/>

## Features
1. Signup and LogIn. For the user to access the following features of the program the user has to be logged in. User choose either to signup or login.
    * For the SignUp option: User should provide a username followed by a password. An id is automatically generated for the user. Then the user asked whether he would like to accept anonymous questions or not.
    * For the logIn option: User enter credentials which are authanticated and compared to our database.
2. Print questions received. Any question the user was asked, is printed in a chronological order and in a parent child format.
3. Print questions asked.
4. Answer questions. User can answer only the questions he/she was asked, hence the user is asked to provide a question id which is then checked whether the user was asked before or not. In addition, if a question is already answered, the answer would be overwritten.
5. Delete questions. User can delete only the question he/she has received or asked, hence the user is asked to provide a question id which is then checked whether the user was asked before or not. In addition if the question happens to be a parent question, all the thread would be deleted.
6. Ask questions. User can ask questions to other people firstly, the id of the ohter user to be asked is entered to check if exists. Then user choose to ask a fresh new question or enter an id of an existing question to be added in its thread.
7. List users
8. Print feed. Print only answered questions.

## Run Run
1. Choice of SignUp, Login or Exit.<br/>
![image](https://user-images.githubusercontent.com/29601694/183286019-7550850f-857a-4468-a3ee-ca78ef0a146a.png)<br/>
    1.1. SignUp<br/>
    ![image](https://user-images.githubusercontent.com/29601694/183286086-87134aff-9d7f-4668-b577-dae4c4c0e8b6.png)<br/>
    1.2 LoginIn<br/>
    ![image](https://user-images.githubusercontent.com/29601694/183286127-a9944895-3c99-4f6d-81e0-1cb6e2211bd4.png)<br/>
2. Main Menu<br/>
 ![image](https://user-images.githubusercontent.com/29601694/183288670-2f72fd39-b144-4b28-904a-d22ca7f37489.png)<br/>
   2.1 Print Questions Received<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183285877-038e6205-94ed-4b57-b65a-f3243cf4e515.png)<br/>
   2.2 Print Questions Asked<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183288754-fbbedf2b-c668-43bd-b37e-61df7fcfebff.png)<br/>
   2.3 Answer Question<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183288829-8de106f4-3be1-4a07-a14c-4a15eb297dbc.png)<br/>
   2.4 Delete Question<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183288867-07e7c1bd-c7c3-416e-ab68-693ac871be79.png)<br/>
   2.5 Ask Question<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183288949-575d30ce-f82e-4c01-b2a2-dd8118dd7fdb.png)<br/>
   2.6 List System Users<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183288980-0bd64568-c821-4218-9ae7-6b74d3a5f962.png)<br/>
   2.7 Print Feed<br/>
   ![image](https://user-images.githubusercontent.com/29601694/183289029-b4e66df3-145a-4f69-9364-88b15cdf47e2.png)<br/>


 
