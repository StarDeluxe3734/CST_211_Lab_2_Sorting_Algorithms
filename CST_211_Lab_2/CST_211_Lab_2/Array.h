#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H

#include "Exception.h"
/************************************************************************
* Programmer: David Abaroa
*
* Class: Array
*
* Purpose: This class creates a dynamic one-dimensional array that can be * started at any base.
*
* Manager functions:
* Array ( )
* The default size is zero and the base is zero.
* Array (int length, int start_index = 0)
*	Creates an appropriate sized array with the starting index
*	either zero or the supplied starting value.
* Array (const Array & copy)
*	Sets all values to the copy values.
* operator = (const Array & rhs)
*	Sets all values to the rhs values
* ~Array()
*	Destructor
* Methods:
* operator [ ] (int index)
*	Overloaded [] operator that returns item at index.
* getStartIndex ()
*	returns the start index
* setStartIndex (int start_index)
*	sets new starting index
* getLength ()
*	returns the length
* setLength(int length)
*	sets new length
*************************************************************************/
template <typename T>
class Array
{
public:
	Array();
	Array(int length, int starting_index = 0);
	Array(const Array &copyArray);
	~Array();
	Array<T>&operator=(const Array &rhs);
	T &operator[](int index) const;
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);
	//friend ostream& operator<<(ostream& os, const Array<T> toOut);
private:

	int m_length;
	int m_start_index;
	void Clear();
	T * m_array;
};


/**********************************************************************
* Purpose: This is the default constructor.
*
* Precondition:
*
* Postcondition:
* Initializes array to nulptr and length and index to 0
************************************************************************/
template <typename T>
inline Array<T>::Array() : m_length(0), m_start_index(0), m_array(nullptr)
{
}

/**********************************************************************
* Purpose: This is the 2 Arg constructor.
*
* Precondition:
*	int length - Specified Length of the array.
*	int starting_index - Specified starting index
*
* Postcondition:
* Initializes array and length and index to the specified length and index
************************************************************************/
template<typename T>
inline Array<T>::Array(int length, int starting_index) : m_length(length), m_start_index(starting_index), m_array(nullptr)
{
	if (length < 0) {
		throw(Exception("Cant have negative legth array."));
	}

	m_array = new T[m_length];
	for (int i = 0; i < m_length; i++)
	{
		m_array[i] = T();
	}
}

/**********************************************************************
* Purpose: This is the copy constructor.
*
* Precondition:
*	const Array & copyArray - Array to copy values from.
*
* Postcondition:
* Initializes array and length and index to the values from the copy
************************************************************************/
template<typename T>
inline Array<T>::Array(const Array & copyArray) : m_length(copyArray.m_length), m_start_index(copyArray.m_start_index), m_array(nullptr)
{
	m_array = new T[m_length];
	for (int i = 0; i < copyArray.m_length; i++)
	{
		m_array[i] = copyArray.m_array[i];
	}
}

/**********************************************************************
* Purpose: This is the clear function.
*
* Precondition:
*
* Postcondition:
* Deallocates the memory and resets length and index to their default val.
************************************************************************/
template<typename T>
inline void Array<T>::Clear()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}

/**********************************************************************
* Purpose: This is the overload of the = operator.
*
* Precondition:
*	const Array & rhs - Array to copy values from.
*
* Postcondition:
* Initializes array and length and index to the values from the copy.
************************************************************************/
template<typename T>
inline Array<T>& Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs) //If we are not = ourselves
	{
		Clear(); //Clear what we have
		m_length = rhs.m_length; //Set new length
		m_start_index = rhs.m_start_index; //Set new index
		if (m_length != 0) //If rhs is null
		{
			m_array = new T[m_length]; //Create new array
			for (int i = 0; i < rhs.m_length; i++)
			{
				m_array[i] = rhs.m_array[i]; //Copy all values
			}
		}
		else
		{
			m_array = nullptr;
		}

	}
	return *this;
}

/**********************************************************************
* Purpose: This is the overload of the [] operator.
*
* Precondition:
*	int index - index from which we have to get an item.
*
* Postcondition:
*	Value of array at index is returned
************************************************************************/
template<typename T>
inline T &Array<T>::operator[](int index) const
{
	//If index is within range, we are not in a default. Note : we have to do m_length + m_start_index because m_start_index can be not 0
	if (m_length != 0 && index < m_length + m_start_index && index >= 0)
	{
		return *(m_array + index - m_start_index);
	}
	else
	{
		//Throw out of range exception
		throw(Exception("Out of Bounds"));
	}
}


/**********************************************************************
* Purpose: This is the function for getting the starting index.
*
* Precondition:
*
* Postcondition:
*	Returns the starting index.
************************************************************************/
template<typename T>
inline int Array<T>::getStartIndex() const
{
	return m_start_index;
}


/**********************************************************************
* Purpose: This is the function for setting the starting index.
*
* Precondition:
*	int start_index - index to set to.
*
* Postcondition:
*	Index is updated.
************************************************************************/
template<typename T>
inline void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

/**********************************************************************
* Purpose: This is the function for getting the length.
*
* Precondition:
*
* Postcondition:
*	Returns the length.
************************************************************************/
template<typename T>
inline int Array<T>::getLength() const
{
	return m_length;
}

/**********************************************************************
* Purpose: This is the function for setting the length.
*
* Precondition:
*	int length - length to set to.
*
* Postcondition:
*	length is updated.
************************************************************************/
template<typename T>
inline void Array<T>::setLength(int length)
{
	if (length >= 0)
	{
		//Temporary Array
		T * m_arrayTemp;

		//If length is bigger set to bigger length size, else cut
		int toSetLength = length < m_length ? m_length : length;

		m_arrayTemp = new T[toSetLength];
		for (int i = 0; i < toSetLength; i++)
		{
			m_arrayTemp[i] = T();
		}

		for (int i = 0; i < m_length; i++)
		{
			m_arrayTemp[i] = m_array[i];
		}
		delete[] m_array;
		m_array = m_arrayTemp;
		m_length = length;
	}
	else
	{
		throw(Exception("Can't have lower than 0 size"));
	}

}

/**********************************************************************
* Purpose: This is the destructor.
*
* Precondition:
*
* Postcondition:
*	Memory is deallocated and reset
************************************************************************/
template<typename T>
inline Array<T>::~Array()
{
	Clear();
}
#endif // _ARRAY_H