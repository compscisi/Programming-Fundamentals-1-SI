/******************************
   Shelby King 
   16 April 2019
   BubbleSortSearch.cpp
   Bubble sort program and some other stuff.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

// Global variables
const int SIZE = 10000;				//size of array
const int MAX_VALUE = 100000;		//max value in our array
const int EXP_SIZE = SIZE * 100;	//num of experimental runs

// Function declarations
void bubbleSort(int arr[], int size);
void swap(int &a, int &b);
void copyArray(const int s[], int t[], int size);
int linearSearch(const int s[], int key, int size);
int binarySearch(const int s[], int key, int size);

int main()
{
	//	Your code goes here
	int unsortedArray[SIZE];		//unsorted data
	int sortedArray[SIZE];			//sorted data
	int searchSequence[SIZE];		//set of search elements
	clock_t startTime;				//time tun started
	clock_t endTime;				//time run ended
	double totalTime;				//time the run took in seconds

	//seed the rng
	srand(unsigned(time(0)));

	//get some values for our array
	for (int i = 0; i < SIZE; i++)
	{
		unsortedArray[i] = 1 + rand() % MAX_VALUE;	//1 to MAX_VALUE
	}

	//copy the array to another so we can use the values again
	copyArray(unsortedArray, sortedArray, SIZE);

	//sort it out
	bubbleSort(sortedArray, SIZE);

	//setup the search sequence
	for (int i = 0; i < SIZE; i++)
	{
		searchSequence[i] = 1 + rand() % (MAX_VALUE + 1000);
	}

	//run the experiment
	//linear search
	startTime = clock();
	for (int i = 0, j = 0; i < EXP_SIZE; i++)
	{
		j = i % SIZE;	//j will be 0 to SIZE - 1
		linearSearch(unsortedArray, searchSequence[j], SIZE);
	}
	endTime = clock();
	//get the total time in seconds 
	totalTime = (endTime - startTime) / static_cast<double>(CLOCKS_PER_SEC);
	cout << "The number of seconds used by linearSearch: "
		<< totalTime << endl;

	//binary search
	startTime = clock();
	for (int i = 0, j = 0; i < EXP_SIZE; i++)
	{
		j = i % SIZE;	//j will be 0 to SIZE - 1
		binarySearch(sortedArray, searchSequence[j], SIZE);
	}
	endTime = clock();
	//get the total time seconds
	totalTime = (endTime - startTime) / static_cast<double>(CLOCKS_PER_SEC);
	cout << "The number of seconds used by binarySearch: "
		<< totalTime << endl;

	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}

//do an ascending order of arr
void bubbleSort(int arr[], int size)
{
	bool didSwap;			//did we do a swap(?)
	
	//go thru each element from size - 1 to element 1
	for (int i = size - 1; i < 0; i--)
	{
		didSwap = false;	//assume no swaps

		//check all the remaining elements from 0 to i
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				didSwap = true;
			}
		}//end of inner loop
		if (!didSwap) break;	//get out of here we are done
	}//end of outer loop
}

//swap the values a and b
void swap(int & a, int & b)
{
	int temp;	//temporary holding cell
	temp = a;	//put a in a temp
	a = b;		//a has now become b
	b = temp;	//we did it ! horray
}

//copies contents of first array to second array
//assumes both arrays are the same size
void copyArray(const int s[], int t[], int size)
{
	for (int i = 0; i < size; i++)
	{
		t[i] = s[i];
	}
}

//returns -1 if key is not found
//return position of key if found
//searches for key in s[]
int linearSearch(const int s[], int key, int size)
{
	int index = -1;	//hold the index value where key is found
	for (int i = 0; i < size; i++)
	{
		if (s[i] == key)
		{
			index = i;
			break;
		}
	}
	return index;
}

//return -1 if key not found
//return position of key if found
//search for key in s[]
//array s must be sorted in ascending order
int binarySearch(const int s[], int key, int size)
{
	//starting position of first and last elements
	int first = 0, last = size - 1;	//recall, this is because of the 0 based index!
	//starting position of the middle element
	int mid = (first + last) / 2;
	int index = -1;					//position where key is found

	//loop while numbers are available to search
	while (first <= last)
	{
		if (s[mid] == key)		//we found it!
		{
			index = mid;
			break;				//no reason to keep looking for it once we found it
		}
		else if (s[mid] > key)	//key is on left 
		{
			last = mid - 1;
		}
		else					//key is on right
		{
			first = mid + 1;
		}
		//calculate a new mid
		mid = (first + last) / 2;

	}
	return index;
}
