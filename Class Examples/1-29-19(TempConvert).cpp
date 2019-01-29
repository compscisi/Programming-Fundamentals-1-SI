/******************************
   Mr. Class Example
   24 January 2019
   TempConvert.cpp
   Description: This program will ask for the date and temperature in
   Fahrenheit and convert it to Celsius
   NOTE: This example is INCOMPLETE
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global Variables
// month names
const string MONTHS[12] = { "January", "February", "March",
							"April", "May", "June", "July",
							"August", "Septemeber", "October",
							"November", "December" };

int main()
{
	int month,		//month number (1 - Jan, 12 - dec)
		day,		//day of the month
		year;		//current year
	double f,		//temperature in fahrenheit
		c;			//temperature in celsius

	//get info from the user
	cout << "What is the current year? ";
	cin >> year;
	cout << "What is the current month (1-12 for Jan-Dec)? ";
	cin >> month;
	cout << "What is the current day (1-31)? ";
	cin >> day;
	cout << "What is the temperature in degrees fahrenheit? ";
	cin >> f;

	//Convert fahrenheit to celsius
	c = (5.0 / 9.0) * (f - 32.0);

	//output the results
	cout << endl << endl;
	cout << "Date: " << MONTHS[month - 1] << " " << day
		<< ", " << year << endl;
	cout << "Fahrenheit: " << f << '\370' << "F\n";
	cout << "Celsius: " << c << '\370' << "C\n";
    
    
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
