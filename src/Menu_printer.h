/*
 * Menu.h
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#ifndef MENU_PRINTER_H_
#define MENU_PRINTER_H_
#include <iostream>
#include <vector>

class Menuprinter
{
private:
	/**
	 * displays menu
	 *
	 * @param menu string to display
	 * @return non
	 */
	void print(const std::vector<std::string> menuStrings) const;

public:
	Menuprinter();
	virtual ~Menuprinter();

	/**
	 * displays first menu login
	 *
	 * @param non
	 * @return user choice
	 */
	void menu_login();

	/**
	 * displays main menu
	 *
	 * @param non
	 * @return user choice
	 */
	void menu_main();
};

#endif /* MENU_PRINTER_H_ */
