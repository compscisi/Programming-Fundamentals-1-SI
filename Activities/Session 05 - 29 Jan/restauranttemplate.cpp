/******************************
   Name
   29 January 2019
   restauranttemplate.cpp
   Description: Write a program that computes the tax and tip on the restaurant bill for a patron
with a $44.50 meal charge. The tax should be 6.75 percent of the meal cost. The
tip should be 15 percent of the total after adding the tax. Display the meal cost,
tax amount, tip amount, and total bill on the screen.
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
  
	 //declare variables
 	 double mealCost = 44.50;         //total cost of the meal
  	                                 //the dollar amount of the tip
  	                                 //the dollar amount of the bill
  	double totalBill;                //amount of the total bill
    
  	//calculations
  
  
  	totalBill = mealCost + tax + tip; //the total bill

	//display results

	return 0;
    
	//Make sure we place the end message on a new line
  	cout << endl;

	//The following is system dependent.  It will only work on Windows
	system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
	  return 0;
}
