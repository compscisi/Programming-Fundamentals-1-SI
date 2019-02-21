/******************************
   Mr. Class Example
   21 February 2019
   Invoice.cpp
   
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Global variables
const int NUM_ITEMS = 3;	// number of items

//function declarations
string getCustomerName();
void getItemNames(string names[], int size);	//size not important for this example but important for Chapter 5
void getItemCosts(double costs[], string names[], int size);		//always want size of array
double getTotalCost(double cost[], int size);
double getAverageCost(double costs[], int size);
void displayInvoice(string custName, string names[], double costs[], int size);


int main()
{
	string customerName;			// Full name of the customer
	string itemNames[NUM_ITEMS];	// Names of three items
	double itemCosts[NUM_ITEMS];	// Cost of each of three items

	//get customer name
	customerName = getCustomerName();

	// Get the name of the three items
	getItemNames(itemNames, NUM_ITEMS);

	// Get the cost of the three items
	getItemCosts(itemCosts, itemNames, NUM_ITEMS);
    
	// Display the invoice to the customer
	displayInvoice(customerName, itemNames, itemCosts, NUM_ITEMS);
    
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

//asks for and return name of the customer
string getCustomerName()
{
	string customerName;
	// Get the customer name
	cout << "Enter the full name of the customer: ";
	getline(cin, customerName);
	return customerName;
}

//get item names
void getItemNames(string names[], int size)
{
	cout << "\nEnter the name of the " << size <<
		" items for the invoice\n";
	cout << "Item 1: ";
	getline(cin, names[0]);

	cout << "Item 2: ";
	getline(cin, names[1]);

	cout << "Item 3: ";
	getline(cin, names[2]);
}

//get the costs of items by name
void getItemCosts(double costs[], string names[], int size)
{
	cout << "\nEnter the cost of the " << size
		<< " items\n";
	cout << "Cost of " << names[0] << ": $";
	cin >> costs[0];

	cout << "Cost of " << names[1] << ": $";
	cin >> costs[1];

	cout << "Cost of " << names[2] << ": $";
	cin >> costs[2];
}

//get total cost of the items
double getTotalCost(double cost[], int size)
{
	return cost[0] + cost[1] + cost[2];
}

//get average cost of the items
double getAverageCost(double costs[], int size)
{
	return getTotalCost(costs, size) / size;
}


//display the invoice to the customer
void displayInvoice(string custName, string names[], double costs[], int size)
{
	cout << fixed << setprecision(2) << showpoint;
	cout << "\nInvoice for customer: " << custName << endl << endl;
	cout << "Items purchased:\n";
	cout << setw(30) << left << "Item Name" << " "
		<< setw(10) << right << "Cost" << endl;	// table header
	cout << setw(30) << left << names[0] << "$"
		<< setw(10) << right << costs[0] << endl;	// row 1
	cout << setw(30) << left << names[1] << "$"
		<< setw(10) << right << costs[1] << endl;	// row 2
	cout << setw(30) << left << names[2] << "$"
		<< setw(10) << right << costs[2] << endl;	// row 3
	cout << setw(30) << left << "Total Cost" << "$"
		<< setw(10) << right << getTotalCost(costs, size) << endl;	// row 4
	cout << setw(30) << left << "Average Cost" << "$"
		<< setw(10) << right << getAverageCost(costs, size) << endl;	// row 5
}
