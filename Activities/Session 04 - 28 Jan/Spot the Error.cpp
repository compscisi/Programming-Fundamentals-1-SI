/******************************
   Mr. Bad Programmer
   28 January 2019
   spotTheError.cpp
   Description: A survey found that 15% of 
   people prefer one or more drinks, and that
   58% of those people prefer citrus drinks.
   The following program is supposed to display 
   the percentage of people who prefer citrus 
   flavored energy drinks, based off the 
   results of the survey. 
  
   List all errors identified on a piece of
   scratch paper!
********************************/

// Headers
#include iostream;
#include cstdlib;
#include string;
using namespace std;

// Global variables

// Function declarations


int main()
{
	//	Your code goes here
 	const int num_surveyed = 16500;		//the amount of people surveyed
	
	float percentOneOrMore = .15,		//percent of people who preferred one or more energy drinks
	char percentPrefCitrus = .58;		//percent of people who preferred citrus energy drinks
	
	//calculate the amount of people who preferred one or more
	float totalOneOrMore = NUM_SURVEYED * percent_1_or_more;
	
	//calculate the grand total
	totalOneOrMore * percentPrefCitrus = grand_total;

	cout << endl << endl;
	cout << "The approximate # of customers in the survey who\n";
	cout >> "purchase on or more energy drinks per week is "
	cout << num_surveyed << endl;
    
	cout << "The approximate # of customers in the survey who\n"
	<< "prefer citrus-flavored energy drinks ";
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
