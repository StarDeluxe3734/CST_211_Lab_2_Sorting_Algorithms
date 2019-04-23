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
template< typename T > void heapSort(T & a, int size);
template< typename T > void moveDown(T & a, int firstNode, int lastIndex);
template< typename T > void mergeSort(T & a, int size);

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

	for (int i = 0; i < 6; i++)
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
			//heapSort(r_array, n - 1);/*
			//heapSort(t_array, n);*/
			//heapSort(v_array, n - 1);
		}
		long stopTime = currentTimeMillis();
		long elapsedTime = stopTime - startTime;
		cout << sort << " for " << n << " integers: " << elapsedTime << endl;
		/*for (int i = 0; i < n; i = i + 1000)
		{
			if (i < n) cout << " " << r_array[i];
		}*/

		for (int i = 0; i < n; i++)
		{
			if (i < n) cout << " " << r_array[i];
		}

		cout << endl;

		delete[] sort;
	}
	/*bruteForceBubble(v_array, n);
	bruteForceBubble(t_array, n);
	bruteForceBubble(v_array, n);*/

	/*displayTest(v_array, n);
	displayTest(t_array, n);
	displayTest(v_array, n);*/


	delete[] r_array;
	delete[] c_r_array;

	return 0;
}


template< typename T > void bruteForceBubble(T & a, int size)
{
	/*(*a)[0] = 90;
	Loop n times
		Loop n – 1 times
			If array(i) > array(i + 1)
				Swap(array[i], array(i + 1)
			End If
		End Loop
	End Loop*/
	//int temp = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				/*temp = (a)[j];
				(a)[j] = (a)[j + 1];
				(a)[j + 1] = temp;*/
				swap(a, j, j + 1);
			}
		}
	}
}

template<typename T>
void flagBubble(T & a, int size)
{
	//Loop n times keep track of the pass number and quit 		if sorted equals true
	//	Set sorted = true
	//	Loop n – pass - 1 times
	//	If array(i) > array(i + 1)
	//	sorted = false
	//	Swap(array[i], array(i + 1)
	//		End If
	//		End Loop
	//		End Loop
	bool sorted = false;
	//int temp = 0;
	for (int i = 0; i < size; i++)
	{
		sorted = true;
		for (int j = 0; j < size - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				/*sorted = false;
				temp = (a)[j];
				(a)[j] = (a)[j + 1];
				(a)[j + 1] = temp;*/

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
	/*int temp = 0;
	int j = 0;
	for (int i = 1; i < size; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && temp < a[j-1]; j++)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}*/



}

template<typename T>
void shellSort(T & a, int size)
{

	// Start with a big gap, then reduce the gap 
	for (int increment = size / 2; increment > 0; increment = increment / 2)
	{
		for (int i = increment; i < size; i += 1)
		{
			// add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			int temp = a[i];

			// shift earlier gap-sorted elements up until the correct  
			// location for a[i] is found 
			int j;
			for (j = i; j >= increment && a[j - increment] > temp; j -= increment)
			{
				a[j] = a[j - increment];
			}

			//  put temp (the original a[i]) in its correct location 
			a[j] = temp;
		}
	}
}

template<typename T>
void heapSort(T & a, int size)
{
	int i = 0;
	for (i = (size) / 2; i >= 1; i--)
	{
		moveDown(a, i, (size));
	}
	i = 0;
	int temp;
	for (i = size; i >= 2; i--)
	{
		// Storing maximum value at the end.
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		// Building max heap of remaining element.
		moveDown(a, 1, i - 1);
	}

}

template<typename T>
void moveDown(T & a, int firstNode, int lastIndex)
{

	int j, temp;
	//Go to middle take value
	temp = a[firstNode];

	j = 2 * firstNode;

	while (j <= lastIndex)
	{
		//If we are not out of range, if the one next to it is bigger point to it.
		if (j < lastIndex && a[j + 1] > a[j])
		{
			j = j + 1;
		}
		//If branch head is bigger end it.
		if (temp > a[j])
		{
			break;
		}
		//	break;
		// Switching value with the parent node if temp < a[j].
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;

	//int largest = i; // Initialize largest as root 
	//int l = 2 * i + 1; // left = 2*i + 1 
	//int r = 2 * i + 2; // right = 2*i + 2 

	//// If left child is larger than root 
	//if (l < n && arr[l] > arr[largest])
	//	largest = l;

	//// If right child is larger than largest so far 
	//if (r < n && arr[r] > arr[largest])
	//	largest = r;

	//// If largest is not root 
	//if (largest != i)
	//{
	//	swap(arr[i], arr[largest]);

	//	// Recursively heapify the affected sub-tree 
	//	heapify(arr, n, largest);
	//}
}

template<typename T>
void mergeSort(T & a, int size)
{


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

