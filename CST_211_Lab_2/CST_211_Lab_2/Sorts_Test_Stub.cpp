/*************************************************************
* Author: David Abaroa
* Assignment: Lab 2 Sorting Algorithms
* Filename: Sorts_Test_Stub.cpp
* Date Created: 4/22/2019
**************************************************************/
/*************************************************************
* Lab/Assignment: Lab 2
*
* Overview:
* The purpose of this lab is to create and see how different sorting algorithms behave.
*
* Input:
* argv is the number of items to generate and sort.
*
* Output:
* The output of this program will be the outputs of all the tests.
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <crtdbg.h>
#include <iostream>
#include <vector>
#include "Array.h"
#include <fstream>


using std::ofstream;
using std::cout;
using std::endl;
using std::vector;

#include <windows.h>

__int64 currentTimeMillis() 
{
	FILETIME f;
	::GetSystemTimeAsFileTime(&f);
	__int64 nano = (__int64(f.dwHighDateTime) << 32LL) + __int64(f.dwLowDateTime);
	return (nano - 116444736000000000LL) / 10000;
}

void genNum(int * r_array, Array<int> * t_array, vector<int> * v_array, int size);
void copyVals(int * r_array, int * c_r_array, Array<int>* t_array, Array<int>* c_t_array, vector<int>* v_array, vector<int>* c_v_array, int size);
template< typename T >inline void swap(T & a, int first, int second);

//Sorts
template< typename T > void bruteForceBubble(T & a, int size);

template< typename T > void flagBubble(T & a, int size);

template< typename T > void selectionSort(T & a, int size);

template< typename T > void insertionSort(T & a, int size);

template< typename T > void shellSort(T & a, int size);

template< typename T > void heapSort(T & a, int n);
template< typename T > void moveDown(T & a, int first, int last);

template< typename T > void mergeSort(T & a, int size);
template< typename T , typename Y> void mergeSortFunction(T & la, Y & ra, int left_index, int right_index);
template< typename T, typename Y> void merge(T & la, Y & temp, int left, int right, int right_end);

template< typename T > void quickSort(T & ra, int n);
template< typename T > void quickSort(T & ra, int first, int last);

int main(int argc, const char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	time_t compile(0);
	const int n = atoi(argv[1]);


	/*********************Initiate Different Arrays***********************************/
	int * r_array = new int[n + 1];
	Array<int> t_array(n, 0);
	vector<int> v_array(n);

	int * c_r_array = new int[n + 1];
	Array<int> c_t_array(n, 0);
	vector<int> c_v_array(n);

	//Generate Numbers
	genNum(c_r_array, &c_t_array, &c_v_array, n);

	//Copy values to working arrays
	copyVals(r_array, c_r_array, &t_array, &c_t_array, &v_array, &c_v_array, n);

	/*********************Initiate Different Arrays***********************************/

	//Open File
	ofstream myfile;
	myfile.open("Time of Sorts.txt");



	for (int i = 0; i <= 7; i++)
	{
		char * sort = nullptr;
		copyVals(r_array, c_r_array, &t_array, &c_t_array, &v_array, &c_v_array, n);
		long startTime = currentTimeMillis();

		if (i == 0)
		{
			sort = new char[strlen("Brute Force Sort") + 1];
			strcpy(sort, "Brute Force Sort");
			startTime = currentTimeMillis();
			bruteForceBubble(r_array, n);
			bruteForceBubble(t_array, n);
			bruteForceBubble(v_array, n);
		}
		else if (i == 1)
		{
			sort = new char[strlen("Flagged Bubble Sort") + 1];
			strcpy(sort, "Flagged Bubble Sort");
			startTime = currentTimeMillis();
			flagBubble(r_array, n);
			flagBubble(t_array, n);
			flagBubble(v_array, n);
		}
		else if (i == 2)
		{
			sort = new char[strlen("Selection Sort") + 1];
			strcpy(sort, "Selection Sort");
			startTime = currentTimeMillis();
			selectionSort(r_array, n);
			selectionSort(t_array, n);
			selectionSort(v_array, n);
		}
		else if (i == 3)
		{
			sort = new char[strlen("Insertion Sort") + 1];
			strcpy(sort, "Insertion Sort");
			startTime = currentTimeMillis();
			insertionSort(r_array, n);
			insertionSort(t_array, n);
			insertionSort(v_array, n);
		}
		else if (i == 4)
		{
			sort = new char[strlen("Shell Sort") + 1];
			strcpy(sort, "Shell Sort");
			startTime = currentTimeMillis();
			shellSort(r_array, n); 
			shellSort(v_array, n);
			shellSort(t_array, n);
		}
		else if (i == 5)
		{
			sort = new char[strlen("Heap Sort") + 1];
			strcpy(sort, "Heap Sort");
			startTime = currentTimeMillis();
			heapSort(r_array, n);
			heapSort(t_array, n);
			heapSort(v_array, n);
		}
		else if (i == 6)
		{
			sort = new char[strlen("Merge Sort") + 1];
			strcpy(sort, "Merge Sort");
			startTime = currentTimeMillis();
			mergeSort(r_array, n);
			mergeSort(t_array, n);
			mergeSort(v_array, n);
		}
		else if (i == 7)
		{
			sort = new char[strlen("Quick Sort") + 1];
			strcpy(sort, "Quick Sort");
			startTime = currentTimeMillis();
			quickSort(r_array, n);
			quickSort(t_array, n);
			quickSort(v_array, n);
		}
		long stopTime = currentTimeMillis();
		long elapsedTime = stopTime - startTime;
		myfile << endl << sort << " for " << n << " integers milliseconds: " << elapsedTime << endl;
		cout << sort << " for " << n << " integers in milliseconds: " << elapsedTime << endl;
		for (int i = 0; i < n; i = i + 1000)
		{
			if (i < n)
			{
				cout << " " << r_array[i];
				myfile << " " << r_array[i];
			}
		}
		cout << endl;

		delete[] sort;
	}
	
	myfile.close();

	delete[] r_array;
	delete[] c_r_array;

	return 0;
}

/**********************************************************************
* Purpose: This is the Brute Force Bubble Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int size - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template< typename T > 
void bruteForceBubble(T & a, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a, j, j + 1);
			}
		}
	}
}

/**********************************************************************
* Purpose: This is the Flag Bubble Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int size - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template<typename T>
void flagBubble(T & a, int size)
{
	bool sorted = false;
	for (int i = 0; i < size && sorted != true; i++)
	{
		sorted = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				sorted = false;
				swap(a, j, j + 1);
			}
		}
	}
}

/**********************************************************************
* Purpose: This is the Selection Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int size - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template<typename T>
void selectionSort(T & a, int size)
{
	int min = 0;
	for (int i = 0; i < size - 1; ++i) 
	{
		min = i;
		for (int j = i + 1; j < size; ++j) 
		{
			if (a[j] < a[min])
			{
				min = j;
			}

		}
		swap(a, min, i);
	}
}

/**********************************************************************
* Purpose: This is the Insertion Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int size - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template<typename T>
void insertionSort(T & a, int size)
{
	int key = 0;
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

/**********************************************************************
* Purpose: This is the Shell Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int size - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template<typename T>
void shellSort(T & a, int size)
{
	vector<int> Increments;
	int h = 0;
	int i = 0;
	for (h = 1, i = 0; h < size; i++)
	{
		Increments.push_back(h);
		h = 3 * h + 1;
	}
	int temp = 0;
	int k = 0;
	for (i = Increments.size() - 1; i >= 0; i--)
	{
		h = Increments[i];
		for (int hCnt = h; hCnt < 2 * h; hCnt++)
		{
			for (int j = hCnt; j < size; j++)
			{
				temp = a[j];
				for (k = j; (k >= h) && (temp < a[k-h]); k -= h)
				{
					a[k] = a[k - h];
				}
				a[k] = temp;
			}
		}
	}
}


/**********************************************************************
* Purpose: This is the Heap Sort function.
*
* Precondition:
*	T & a - Array to sort.
*	int n - Size of the array.
*
* Postcondition:
*	Array is sorted from smallest to largest.
************************************************************************/
template<typename T>
void heapSort(T & a, int n)
{
	//Build the heap
	for (int i = (n / 2); i >= 0; i--)
	{
		moveDown(a, i, n - 1);
	}
	//Sort the heap
	for (int i = (n - 1); i != 0; i--)
	{
		swap(a, 0, i);
		moveDown(a, 0, i - 1);
	}
}

/**********************************************************************
* Purpose: This is the Move Down function. Used by Heap Sort.
*
* Precondition:
*	T & a - Array to sort.
*	int first - Parent node
*	int last - End of array
*
* Postcondition:
*	Parent, right child, and left child are sorted accordingly.
************************************************************************/
template<typename T>
void moveDown(T & a, int first, int last)
{
	int largest = first * 2 + 1;

	while (largest <= last)
	{
		if (largest + 1 < last && a[largest + 1] > a[largest])
		{
			largest = largest + 1;
		}
		if (a[first] < a[largest])
		{
			swap(a, first, largest);
			first = largest;
			largest = first * 2 + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}

/**********************************************************************
* Purpose: This is the Merge Sort.
*
* Precondition:
*	T & ra - Array to sort.
*	int n - Size of array
*
* Postcondition:
*	Array is sorted from smalles to biggest.
************************************************************************/
template<typename T>
void mergeSort(T & ra, int n)
{
	vector<int> temp(n);
	mergeSortFunction(ra, temp, 0, n - 1);
}


/**********************************************************************
* Purpose: This is a helper function for MergeSort, that performs the actual sort.
*
* Precondition:
*	T & la - Array which actually holds data
*	Y & ra - Temp Array which will hold sorted array.
*	int left_index - Left Indexing
*	int right_index - RIght Indexint
*
* Postcondition:
*	Function is recursively called until array is sorted.
************************************************************************/
template<typename T , typename Y>
void mergeSortFunction(T & la, Y & ra, int left_index, int right_index)
{
	// Checks to see if there is one element in subarray 
	if (left_index == right_index) {
		//At single element
	}
	//If left < right
	else if (left_index < right_index)
	{
		//Set mid = (left + right) / 2
		int mid = (left_index + right_index) / 2;
		
		// Sort first and second halves 
		mergeSortFunction(la, ra, left_index, mid); // left half
		mergeSortFunction(la, ra, mid + 1, right_index); // right half

		merge(la, ra, left_index , mid + 1, right_index); //Merge 2 Halves
	}
}

/**********************************************************************
* Purpose: This is a helper function for MergeSort, that performs the merge of two "arrays".
*
* Precondition:
*	T & la - Array which actually holds data
*	Y & temp - Temp Array which will hold sorted array.
*	int left - Left start index
*	int right -  Right Start Index
*	int right_end - RIght End Index
*
* Postcondition:
*	Function combines and sorts two "Arrays" into temp which is then copied over la.
************************************************************************/
template<typename T, typename Y>
void merge(T & la, Y & temp, int left, int right, int right_end)
{
	int left_end = right - 1; //Set left_end = right - 1
	int temp_pos = left; //Set temp_pos = left
	int num_elements = right_end - left + 1; //Set num_elements = right_end - left + 1
	int toCopyStart = right_end - num_elements + 1; //For Copying elements over
	if (toCopyStart < 0) toCopyStart = 0; //In case we go negative
	
	//Until we reach the end of ONE of the arrays
	while (left <=  left_end && right <= right_end)
	{
		//Interweeb arrays
		if (la[left] <= la[right])
		{
			temp[temp_pos] = la[left];
			temp_pos++;
			left++;
		}
		else
		{
			temp[temp_pos] = la[right];
			temp_pos++;
			right++;
		}
	}

	/* Copy the rest of the left array into the temp array */
	while (left <= left_end)
	{
		temp[temp_pos] = la[left];
		left++;
		temp_pos++;
	}
	/*Copy the rest of the right array into the temp array*/
	while (right <= right_end)
	{
		temp[temp_pos] = la[right];
		right++;
		temp_pos++;
	}
	/*Copy the temp array over the top of the original array*/
	for (int i = 0; i < num_elements; i++)
	{
		la[toCopyStart + i] = temp[toCopyStart + i];
	}
}

/**********************************************************************
* Purpose: This is the Quick Sort.
*
* Precondition:
*	T & ra - Array to sort.
*	int n - Size of array
*
* Postcondition:
*	Array is sorted from smalles to biggest.
************************************************************************/
template<typename T>
void quickSort(T & ra, int n)
{
	int max = 0;
	if (n >= 2) {
		//find max
		for (int i = 1; i < n; i++)
		{
			if (ra[max] < ra[i])
			{
				max = i;
			}
		}	
		swap(ra, n - 1, max);
		quickSort(ra, 0, n - 2);
	}
}

/**********************************************************************
* Purpose: This is the Quick Sort.
*
* Precondition:
*	int first - 
*	int last - 
*
* Postcondition:
*	Array is sorted from smalles to biggest.
************************************************************************/
template<typename T>
void quickSort(T & ra, int first, int last)
{
	int m_small = first;
	int m_large = last;
	int pivot = ra[(m_small + m_large) / 2];

	while(m_small <= m_large)
	{
		while (ra[m_small] < pivot)
		{
			m_small = m_small + 1;
		}
		while (ra[m_large] > pivot)
		{
			m_large = m_large - 1;
		}
		if (m_small <= m_large) swap(ra, m_small++, m_large--);
	}
	if (first < m_large - 1)
	{
		quickSort(ra, first, m_large);
	}
	if (last > m_large + 1)
	{
		quickSort(ra, m_small, last);
	}
}


/**********************************************************************
* Purpose: This function initiates three arrays to the same randomly generated numbers.
*
* Precondition:
*	int * r_array - C Style Array
*	Array<int> * t_array - Templetated Class Array.
*	vector<int> * v_array - Vector array of type of int.
*	int size - Size of the arrays
*
* Postcondition:
*	All three arrays are filled with the same data.
************************************************************************/
void genNum(int * r_array, Array<int> * t_array, vector<int> * v_array, int size)
{
	//Set them to right size
	int UpperTypeBound = 100;
	int LowerTypeBound = 0;
	int temp = 0;

	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		temp = LowerTypeBound + rand() / (RAND_MAX / (UpperTypeBound - LowerTypeBound + 1) + 1);
		r_array[i] = temp;
		(*t_array)[i] = temp;
		(*v_array)[i] = temp;
	}
}

/**********************************************************************
* Purpose: Swaps two elements in the array.
*
* Precondition:
*	T & a - Array in which data is found
*	int first - First element index.
*	int second - Second element index.
*
* Postcondition:
*	Data at indexes are swapped.
************************************************************************/
template<typename T>
inline void swap(T & a, int first, int second)
{
	int temp = (a)[first];
	(a)[first] = (a)[second];
	(a)[second] = temp;
}

/**********************************************************************
* Purpose: Copies value from three arrays into another three arrays of the same type.
*
* Precondition:
*	int * r_array - C Style Array To copy values into.
*	int * c_r_array - C Style Array To copy values from.
*	Array<int>* t_array - Templetated Array To copy values into.
*	Array<int>* c_t_array - Templetated Array To copy values from.
*	vector<int>* v_array - Vector array to copy values into.
*	vector<int>* c_v_array - Vector array to copy values from.
*	int size - Size of the arrays.
* Postcondition:
*	Data is updated for all three arrays.
************************************************************************/
void copyVals(int * r_array, int * c_r_array, Array<int>* t_array, Array<int>* c_t_array, vector<int>* v_array, vector<int>* c_v_array, int size)
{
	(*v_array) = (*c_v_array);
	(*t_array) = (*c_t_array);
	for (int i = 0; i < size; i++)
	{
		r_array[i] = c_r_array[i];
	}
}