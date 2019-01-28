/******************************
   Mr. Bad Programmer
   28 January 2019
   spotTheError.cpp
   Description: The following program
   is supposed to display the results 
   of a survey about energy drinks.
   Use this code to fill out the 
   Spot the Error worksheet!
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables

// Function declarations


int main()
{
	//	Your code goes here
 	const int NUM_SURVEYED = 16500;
	
	float percent_1_or_more = .15,
	percent_pref_citrus = .58,
	total_1_or_more = NUM_SURVEYED * percent_1_or_more,
	grand_total = total_1_or_more * percent_pref_citrus;

	cout << endl << endl;
	cout << "The approximate # of customers in the survey who\n";
	cout << "purchase on or more energy drinks per week is ";
	cout << total_1_or_more << endl;
    
	cout << "The approximate # of customers in the survey who\n";
	cout << "prefer citrus-flavored energy drinks ";
	cout << grand_total << endl;

    
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
