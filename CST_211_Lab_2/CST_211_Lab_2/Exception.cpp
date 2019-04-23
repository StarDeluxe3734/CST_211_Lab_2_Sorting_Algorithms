#include "Exception.h"

/**********************************************************************
* Purpose: This is the default constructor.
*
* Precondition:
*
* Postcondition:
* Initializes message to nullptr
************************************************************************/
Exception::Exception() : m_msg(nullptr)
{
}

/**********************************************************************
* Purpose: This is the 1 Arg constructor.
*
* Precondition:
*	const char * msg - Message to initiallize our message to.
*
* Postcondition:
*	Initializes message to the passed in message
************************************************************************/
Exception::Exception(const char * msg) : m_msg(nullptr)
{
	if (msg != nullptr)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy(m_msg, msg);
	}
}

/**********************************************************************
* Purpose: This is the copy constructor.
*
* Precondition:
*	const Exception & copy - exception to copy message from
*
* Postcondition:
*	Initializes message to the passed in copy's message
************************************************************************/
Exception::Exception(const Exception & copy) : m_msg(nullptr)
{
	if (copy.m_msg != nullptr)
	{
		m_msg = new char[strlen(copy.m_msg) + 1];
		strcpy(m_msg, copy.m_msg);
	}
}

/**********************************************************************
* Purpose: This is the overload of the = operator.
*
* Precondition:
*	const Array & rhs - Exception to copy values from.
*
* Postcondition:
* copies the values from the copy.
************************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs)
	{
		delete[] m_msg;
		if (rhs.m_msg != nullptr)
		{
			m_msg = new char[strlen(rhs.m_msg) + 1];
			strcpy(m_msg, rhs.m_msg);
		}
		else
		{
			m_msg = nullptr;
		}
	}
	return *this;
}

/**********************************************************************
* Purpose: This is the function for getting the message
*
* Precondition:
*
* Postcondition:
*	Returns the message
************************************************************************/
char * Exception::getMessage() const
{
	return m_msg;
}

/**********************************************************************
* Purpose: This is the function for changing/setting the message.
*
* Precondition:
*	const char * msg - message to set to.
*
* Postcondition:
*	Message is updated.
************************************************************************/
void Exception::setMessage(const char * msg)
{
	delete[] m_msg;
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}

/**********************************************************************
* Purpose: This is the overload of the << operator.
*
* Precondition:
*	ostream & os - ostream to put message into
*	const Exception & except - exception containing message to put into ostream
*
* Postcondition:
* Puts message into ostream.
************************************************************************/
ostream & operator<<(ostream & os, const Exception & except)
{
	os << except.m_msg << "\n";
	return os;
}

/**********************************************************************
* Purpose: This is the destructor.
*
* Precondition:
*
* Postcondition:
*	Memory is deallocated and reset
************************************************************************/
Exception::~Exception()
{
	if (m_msg != nullptr)
	{
		delete[] m_msg;
		m_msg = nullptr;
	}
}
