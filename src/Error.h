/*
 * Error.h
 *
 *  Created on: Aug 11, 2022
 *      Author: omarh
 */

#ifndef ERROR_H_
#define ERROR_H_

class Error
{
public:
	Error();
	virtual ~Error();

	/**
	 * display error
	 *
	 * @param error number
	 * @return non
	 */
	void print(const int) const;
};

#endif /* ERROR_H_ */
