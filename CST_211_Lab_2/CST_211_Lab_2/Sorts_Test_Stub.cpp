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
template< typename T > void displayTest(T & a, int size);
template< typename T > void bruteForceBubble(T & a, int size);
template< typename T > void flagBubble(T & a, int size);
template< typename T > void selectionSort(T & a, int size);
template< typename T > void inserionSort(T & a, int size);
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
			//bruteForceBubble(t_array, n);
			//bruteForceBubble(v_array, n);
		}
		else if (i == 1)
		{
			sort = new char[strlen("Flagged Bubble Sort") + 1];
			strcpy(sort, "Flagged Bubble Sort");
			startTime = currentTimeMillis();
			bruteForceBubble(r_array, n);
			//bruteForceBubble(t_array, n);
			//bruteForceBubble(v_array, n);
		}
		else if (i == 2)
		{
			sort = new char[strlen("Selection Sort") + 1];
			strcpy(sort, "Selection Sort");
			startTime = currentTimeMillis();
			selectionSort(r_array, n);
			//selectionSort(t_array, n);
			//selectionSort(v_array, n);
		}
		else if (i == 3)
		{
			sort = new char[strlen("Insertion Sort") + 1];
			strcpy(sort, "Insertion Sort");
			startTime = currentTimeMillis();
			inserionSort(r_array, n);
			/*inserionSort(t_array, n);
			inserionSort(v_array, n);*/
		}
		else if (i == 4)
		{
			sort = new char[strlen("Shell Sort") + 1];
			strcpy(sort, "Shell Sort");
			startTime = currentTimeMillis();
			shellSort(r_array, n);
			/*shellSort(t_array, n);
			shellSort(v_array, n);*/
		}
		else if (i == 5)
		{
			sort = new char[strlen("Heap Sort") + 1];
			strcpy(sort, "Heap Sort");
			startTime = currentTimeMillis();
			heapSort(r_array, n);
			//heapSort(t_array, n);
			heapSort(v_array, n);
		}
		else if (i == 6)
		{
			sort = new char[strlen("Merge Sort") + 1];
			strcpy(sort, "Merge Sort");
			startTime = currentTimeMillis();
			mergeSort(r_array, n);
			//mergeSort(t_array, n);
			//mergeSort(v_array, n);
		}
		else if (i == 7)
		{
			sort = new char[strlen("Quick Sort") + 1];
			strcpy(sort, "Quick Sort");
			startTime = currentTimeMillis();
			quickSort(r_array, n);
			//mergeSort(t_array, n);
			//mergeSort(v_array, n);
		}
		long stopTime = currentTimeMillis();
		long elapsedTime = stopTime - startTime;
		myfile << endl << sort << " for " << n << " integers: " << elapsedTime << endl;
		cout << sort << " for " << n << " integers: " << elapsedTime << endl;
		for (int i = 0; i < n; i = i + 1000)
		{
			if (i < n)
			{
				cout << " " << r_array[i];
				myfile << " " << r_array[i];
			}
		}

		/*for (int i = 0; i < n; i++)
		{
			if (i < n) cout << " " << r_array[i];
		}*/

		cout << endl;

		delete[] sort;
	}
	
	myfile.close();

	delete[] r_array;
	delete[] c_r_array;

	return 0;
}


template< typename T > void bruteForceBubble(T & a, int size)
{
	/*
	(*a)[0] = 90;
	Loop n times
		Loop n – 1 times
			If array(i) > array(i + 1)
				Swap(array[i], array(i + 1)
			End If
		End Loop
	End Loop
	*/
	//int temp = 0;

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

template<typename T>
void flagBubble(T & a, int size)
{
	bool sorted = false;
	for (int i = 0; i < size; i++)
	{
		sorted = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a, j, j + 1);
			}
		}
	}
}

template<typename T>
void selectionSort(T & a, int size)
{
	int min = 0;
	for (int i = 0; i < size - 1; ++i) {
		min = i;
		for (int j = i + 1; j < size; ++j) {
			if (a[j] < a[min])
			{
				min = j;
			}

		}
		swap(a, min, i);
	}
}

template<typename T>
void inserionSort(T & a, int size)
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

template<typename T>
void shellSort(T & a, int size)
{
	for (int increment = size / 2; increment > 0; increment = increment / 2)
	{
		for (int i = increment; i < size; i += 1)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= increment && a[j - increment] > temp; j -= increment)
			{
				a[j] = a[j - increment];
			}
			a[j] = temp;
		}
	}
}

template<typename T>
void heapSort(T & a, int n)
{
	/*
	// Build the heap
	loop starting i at the midpoint of the array and 	continue while i greater than or equal to 0

		Call MoveDown(ra, i, n - 1)
	end loop
	// Sort the heap
	loop starting i at n – 1 and continue until i = 0	Swap the 0th element and the ith element
		Redo the heap by calling MoveDown(ra, 0, i–1)
	end loop
	*/
	//Build the heap
	for (int i = (n / 2); i >= 0; i--)
	{
		moveDown(a, i, n - 1);
	}
	//Sort the heap
	for (int i = (n - 1); i = 0; i--)
	{
		swap(a, 0, i);
		moveDown(a, 0, i - 1);
	}


}

template<typename T>
void moveDown(T & a, int first, int last)
{
	/*
	largest = first * 2 + 1

	loop while largest is not bigger than the last index	
	if largest is less than last AND 
			   the left child < the right child
			increment largest
		end if
	
		if data in the parent is less than the right child
			Swap the data in those to elements
			Set first = largest (The next parent)
			Set largest = first * 2 + 1 (The left child)
		
		else
			Exit the loop by setting largest = last + 1
		End if
	End loop
	*/
	int largest = first * 2 + 1;

	while (largest < last)
	{
		if (largest < last && a[largest + 1] > a[largest])
		{
			largest = largest + 1;
		}
		if (a[first] < a[largest + 1])
		{
			swap(a, first, largest + 1);
			first = largest;
			largest = first * 2 + 1;
		}
		else
		{
			largest = last + 1;
		}
	}
}

template<typename T>
void mergeSort(T & ra, int n)
{
	vector<int> temp(n);
	mergeSortFunction(ra, temp, 0, n - 1);
}

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

template<typename T>
void quickSort(T & ra, int n)
{
	/*	if n >= 2
		for (int i = 1, max = 0; i < n; i++)
			if (ra(max) < ra(i))
				max = i
		end loop
		Swap(ra(n – 1), ra(max))
		QuickSort(ra, 0, n - 2)
	end if
	*/
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

template<typename T>
void quickSort(T & ra, int first, int last)
{
	/*
	small = first + 1; large = last; pivot = ra(first);
	while(small <= large)
		while(ra(small) < pivot)
			small = small + 1
		while(ra(large) > pivot)
			large = large - 1
		if(small < large)
			Swap(ra(small++), ra(large--))
		else
			small = small + 1
		end if
	end loop
	Swap (ra(large), ra(first))
	if(first < large - 1)
		QuickSort(ra, first, upper - 1) // Sort left
	if(last > large + 1)
		QuickSort(ra, upper + 1, last) // Sort right
	*/

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
		//if(small < large)		Swap(ra(small++), ra(large--))
		if (m_small <= m_large) swap(ra, m_small++, m_large--);
	}
	if (first < m_large - 1) quickSort(ra, first, m_large);
	if (last > m_large + 1) quickSort(ra, m_small, last );
}

void genNum(int * r_array, Array<int> * t_array, vector<int> * v_array, int size)
{
	//Set them to right size
	int UpperTypeBound = 100;
	int LowerTypeBound = 0;
	int temp = 0;

	srand(time(0));

	for (int i = 0; i < size; i++)
	{

		// rand() % (UpperTypeBound - LowerTypeBound + 1) + LowerTypeBound
		temp = LowerTypeBound + rand() / (RAND_MAX / (UpperTypeBound - LowerTypeBound + 1) + 1);
		r_array[i] = temp;
		(*t_array)[i] = temp;
		(*v_array)[i] = temp;
	}
}

template<typename T>
inline void swap(T & a, int first, int second)
{
	int temp = 0;
	temp = (a)[first];
	(a)[first] = (a)[second];
	(a)[second] = temp;
}

template< typename T > void displayTest(T & a, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << " " << a[i];
	}
	cout << endl;
}

void copyVals(int * r_array, int * c_r_array, Array<int>* t_array, Array<int>* c_t_array, vector<int>* v_array, vector<int>* c_v_array, int size)
{
	(*v_array) = (*c_v_array);
	(*t_array) = (*c_t_array);
	for (int i = 0; i < size; i++)
	{
		r_array[i] = c_r_array[i];
	}
}

