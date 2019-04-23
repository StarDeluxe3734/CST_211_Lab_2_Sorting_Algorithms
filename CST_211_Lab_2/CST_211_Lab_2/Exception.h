#pragma once
#ifndef _EXCEPTION_H
#define _EXCEPTION_H
# define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using std::ostream;
/************************************************************************
* Programmer: David Abaroa
*
* Class: Exception
*
* Purpose: This class serves as an exception for the array class.
*
* Manager functions:
*Exception(); //Default Ctor
*	Initializes message to nullptr
*Exception(const char * msg); //1 Arg Ctor
*	Initializes message to the passed in value
*Exception(const Exception &copy); //Copy Ctor
*	Initializes message to the copys message
*~Exception(); //Dtor
*	Destructor deallocates memory
*Exception &operator=(const Exception &rhs); //OP =
*	Overloaded = operator sets message to rhs exeption message
*
* Methods:
*char * getMessage() const; //get Message
*	Returns the message
*void setMessage(const char * msg); //Set Message
*	Sets the message to new value
*friend ostream& operator<<(ostream& os, const Exception& except); //OP <<
*	overloaded << operator for printing to ostream
*************************************************************************/
class Exception
{
public:
	Exception(); //Default Ctor
	Exception(const char * msg); //1 Arg Ctor
	Exception(const Exception &copy); //Copy Ctor
	~Exception(); //Dtor
	Exception &operator=(const Exception &rhs); //OP =
	char * getMessage() const; //get Message
	void setMessage(const char * msg); //Set Message
	friend ostream& operator<<(ostream& os, const Exception& except); //OP <<

private:
	char * m_msg;
};


#endif // _EXCEPTION_H