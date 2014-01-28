/*
 * EalException.h
 *
 *  Created on: 28-01-2014
 *      Author: kuba
 */

#ifndef EALEXCEPTION_H_
#define EALEXCEPTION_H_

#include <exception>

namespace EAL {

class EalException: public std::exception {
public:
	EalException(const char* what) : m_what(what) {}
	virtual ~EalException() {}
	virtual const char* what() const throw() { return m_what; }
private:
	const char* m_what;
};

} /* namespace EAL */
#endif /* EALEXCEPTION_H_ */
