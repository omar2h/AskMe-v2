/*
 * Error.cpp
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#include "Error.h"
#include <iostream>

Error::Error()
{
	// TODO Auto-generated constructor stub
}

Error::~Error()
{
	// TODO Auto-generated destructor stub
}

void Error::print(const int c) const
{
	if (c == 1)
		std::cout << "\n---------- Error 1: Invalid choice -----------\n\n";
	else if (c == 2)
		std::cout << "\n---------- ERROR 2: Incorrect UserName/Password ------------\n\n";
	else if (c == 3)
		std::cout << "\n---------- Error 3: User ID doesn't seem to exist ------------\n\n";
	else if (c == 4)
		std::cout << "\n---------- Error 4: Question ID doesn't seem to exist for this user ------------\n\n";
	else if (c == 5)
		std::cout << "\n---------- ERROR 5: Can't open the file ------------\n\n";
	else if (c==6)
		std::cout << "\n---------- Error 6: Question ID doesn't seem to exist ------------\n\n";
}
