#include "App.h"
#include "User.h"
#include "Error.h"
#include "Inputscanner.h"
#include "Authenticator.h"
#include "AppMainMenu.h"
#include "Menu_printer.h"

App::App()
{
	// TODO Auto-generated constructor stub
}

App::~App()
{
	// TODO Auto-generated destructor stub
}
/* 1- get login choice from user */
/* 2- if logged in proceed to the main menu */
void App::run()
{
	User user;
	Menuprinter menu;
	Authenticator auth;
	Error error;
	Input_scanner input_scanner;
	AppMainMenu appMain;

	int choice;

	while (1)
	{
		while (1)
		{
			/* prints login menu */
			menu.menu_login();
			choice = input_scanner.get_choice(1, 3);
			if (!choice)
				continue;
			try
			{
				auth.access(choice, user);
				break;
			}
			catch (const int err)
			{
				error.print(err);
			}
		}
		while (1)
		{
			menu.menu_main();
			choice = input_scanner.get_choice(1, 8);
			if (!choice)
				continue;
			try
			{
				if (!appMain.run(choice, user))
					break;
			}
			catch (const int err)
			{
				error.print(err);
			}
		}
	}
}
