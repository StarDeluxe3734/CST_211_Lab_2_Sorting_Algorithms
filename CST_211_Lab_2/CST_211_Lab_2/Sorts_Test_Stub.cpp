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
template< typename T > void moveDown(T & a, int n, int i);

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
			//heapSort(r_array, n - 1);
			//heapSort(t_array, n);
			//heapSort(v_array, n - 1);
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
			quickSort(v_array, n);
			//mergeSort(t_array, n);
			//mergeSort(v_array, n);
		}
		long stopTime = currentTimeMillis();
		long elapsedTime = stopTime - startTime;
		cout << sort << " for " << n << " integers: " << elapsedTime << endl;
		for (int i = 0; i < n; i = i + 1000)
		{
			if (i < n) cout << " " << r_array[i];
		}

		/*for (int i = 0; i < n; i++)
		{
			if (i < n) cout << " " << r_array[i];
		}*/

		cout << endl;

		delete[] sort;
	}
	
	//vector<int> first_test_v_array(n);
	//vector<int> second_test_v_array(n);

	//int temp = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	//rand() % (UpperTypeBound - LowerTypeBound + 1) + LowerTypeBound
	//	temp = 1 + rand() / (RAND_MAX / (50 - 1 + 1) + 1);
	//	first_test_v_array[i] = temp;
	//}
	/*for (int i = 0; i < n; i++)
	{
		//rand() % (UpperTypeBound - LowerTypeBound + 1) + LowerTypeBound
		temp = 1 + rand() / (RAND_MAX / (50 - 1 + 1) + 1);
		second_test_v_array[i] = temp;
	}
	
	int mid = (0 + n - 1) / 2;
	merge(first_test_v_array, second_test_v_array, 0, mid + 1, n-1);*/
	//mergeSortFunction(first_test_v_array, n);


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
	//int i = 0;
	//for (i = (size) / 2; i >= 1; i--)
	//{
	//	moveDown(a, i, (size));
	//}
	//i = 0;
	//int temp;
	//for (i = size; i >= 2; i--)
	//{
	//	// Storing maximum value at the end.
	//	temp = a[i];
	//	a[i] = a[1];
	//	a[1] = temp;
	//	// Building max heap of remaining element.
	//	moveDown(a, 1, i - 1);
	//}

}

template<typename T>
void moveDown(T & a, int n, int i)
{

	//int j, temp;
	////Go to middle take value
	//temp = a[firstNode];

	//j = 2 * firstNode;

	//while (j <= lastIndex)
	//{
	//	//If we are not out of range, if the one next to it is bigger point to it.
	//	if (j < lastIndex && a[j + 1] > a[j])
	//	{
	//		j = j + 1;
	//	}
	//	//If branch head is bigger end it.
	//	if (temp > a[j])
	//	{
	//		break;
	//	}
	//	//	break;
	//	// Switching value with the parent node if temp < a[j].
	//	else if (temp <= a[j])
	//	{
	//		a[j / 2] = a[j];
	//		j = 2 * j;
	//	}
	//}
	//a[j / 2] = temp;
	//return;

	//int largest = i; // Initialize largest as root 
	//int l = 2 * i + 1; // left = 2*i + 1 
	//int r = 2 * i + 2; // right = 2*i + 2 

	//// If left child is larger than root 
	//if (l < n && a[l] > a[largest])
	//	largest = l;

	//// If right child is larger than largest so far 
	//if (r < n && a[r] > a[largest])
	//	largest = r;

	//// If largest is not root 
	//if (largest != i)
	//{
	//	swap(a[i], a[largest]);

	//	// Recursively heapify the affected sub-tree 
	//	heapify(a, n, largest);
	//}
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
		for (int i = 1, max = 0; i < n; i++)
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
	int pivot = ra[first];
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
		if (m_small < m_large) swap(ra, m_small++, m_large--);
		else m_small = m_small + 1;
	}
	/*Swap (ra(large), ra(first))
	if(first < large - 1)
		QuickSort(ra, first, upper - 1) // Sort left
	if(last > large + 1)
		QuickSort(ra, upper + 1, last) // Sort right*/
	swap(ra, m_large, first);
	if (first < m_large - 1) quickSort(ra, first, m_large - 1);
	if (last > m_large + 1) quickSort(ra, m_small + 1, last );
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

