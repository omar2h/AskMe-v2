/*
 * Loginhandler.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Loginhandler.h"
#include "User.h"
#include "DBmanager.h"

Login_handler::Login_handler() {
	// TODO Auto-generated constructor stub

}

Login_handler::~Login_handler() {
	// TODO Auto-generated destructor stub
}

void Login_handler::login(User &user)
{
    DBmanager DB;
    std::string username, password;
    std::pair<User, bool> userLoginPair;

    std::cout << "Please enter UserName and Password: ";
    std::cin >> username >> password;
    try{
    	user = DB.get_user_login(username, password);
    }
    catch(const int error){
    	throw error;
    }

}
