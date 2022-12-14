/*
 * Inputscanner.h
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#ifndef INPUTSCANNER_H_
#define INPUTSCANNER_H_

#include <iostream>
class Input_scanner
{
	bool verify_choice(const int choice, const int low, const int high);

public:
	Input_scanner();
	virtual ~Input_scanner();

	int get_choice(const int low, const int high);
	std::string get_qText_from_user();
};

#endif /* INPUTSCANNER_H_ */
