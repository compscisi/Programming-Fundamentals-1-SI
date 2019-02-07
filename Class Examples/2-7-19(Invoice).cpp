/******************************
   Mr. Class Example
   7 February 2019
   invoice.cpp
   Description: This program will ask the user
   for her name, ask for the names and costs
   of three items, then calculate the total cost 
   and averagee of the three items
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Global variables
const int NUM_ITEMS = 3;		//number of items

// Function declarations


int main()
{
	string customerName;			//full name of the customer
	string itemNames[NUM_ITEMS];	//name of three items
	double itemCosts[NUM_ITEMS];	//Cost of each of three items
	double totalItemCost;			//total cost of three items
	double averageItemCost;			//average cost of the three items


	//get customer name
	cout << "Enter the full name of the customer: ";
	getline(cin, customerName);


	//get the name of the three items
	cout << "\nEnter the name of the " << NUM_ITEMS <<
		" items for the invoice\n";
	cout << "Item 1: ";
	getline(cin, itemNames[0]);

	cout << "Item 2: ";
	getline(cin, itemNames[1]);

	cout << "Item 3: ";
	getline(cin, itemNames[2]);
    

	//get the cost of the three items
	cout << "\nEnter the cost of the " << NUM_ITEMS
		<< " items\n";
	cout << "Cost of " << itemNames[0] << ": $";
	cin >> itemCosts[0];

	cout << "Cost of " << itemNames[1] << ": $";
	cin >> itemCosts[1];

	cout << "Cost of " << itemNames[2] << ": $";
	cin >> itemCosts[2];

	//calculate the total and average cost of the items
	totalItemCost = itemCosts[0] + itemCosts[1] + itemCosts[2];
	averageItemCost = totalItemCost / NUM_ITEMS;

	//display the invoice to the customer
	cout << fixed << setprecision(2) << showpoint;
	cout << "\nInvoice for customer: " << customerName << endl << endl;
	cout << "Items purchased: \n";
	//table header
	cout << setw(30) << left << "Item Name" << " " << setw(10) << right << "Cost" << endl;
	cout << setw(30) << left << itemNames[0] << "$" 
		<< setw(10) << right << itemCosts[0] << endl;		//row 1
	cout << setw(30) << left << itemNames[1] << "$" 
		<< setw(10) << right << itemCosts[1] << endl;		//row 2
	cout << setw(30) << left << itemNames[2] << "$" 
		<< setw(10) << right << itemCosts[2] << endl;		//row 3
	cout << setw(30) << left << "Total Cost" << "$" 
		<< setw(10) << right << totalItemCost << endl;		//row 4
	cout << setw(30) << left << "Average Cost" << "$" 
		<< setw(10) << right << averageItemCost << endl;	//row 5

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
