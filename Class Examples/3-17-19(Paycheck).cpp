/******************************
   Mr Class Example
   7 March 2019
   Paycheck.cpp
   Calculate the gross pay based on hourly rate and hours worked
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Global variables
//how many hours worked before overtime
	//REMEMBER: no global variables in your program unless they are constant!!!!! ~  prof.
const double REGULAR_TIME_MAX = 40.0;
//overtime adjustment
const double OVERTIME_FACTOR = 1.5;

// Function declarations

string getEmployeeName();
double getHoursWorked();
double getHourlyWage();
double calculateRegTimeWage(double totalHoursWorked,
							double hourlyWage, double regTimeMax);
double calculateOvertimeWage(double totalHoursWorked,
							double hourlyWage, double regTimeMax,
							double otFactor);
double calculateTotalWage(double totalHoursWorked,
							double hourlyWage, double regTimeMax,
							double otFactor);


int main()
{
	//	Your code goes here
	string employeeName;		//name of employee
	double hourlyWage;			//what do we make per hour
	double hoursWorked;			//how many hours do we give the man
	double totalWage;			//total gross pay (and my pay is gross)

	//get the name of the employee
	employeeName = getEmployeeName();

	//get the hourly wage
	cout << endl;
	hourlyWage = getHourlyWage();

	//get the number of hours worked for the week
	cout << endl;
	hoursWorked = getHoursWorked();

	//calculate the total wage
	totalWage = calculateTotalWage(hoursWorked, hourlyWage, REGULAR_TIME_MAX, OVERTIME_FACTOR);
    
	//print report
	cout << "\n\nPaycheck Report\n";
	cout << "Employee: " << employeeName << endl;
	cout << "Hourly Wage: " << hourlyWage << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Total Salary: " << totalWage << endl;
    
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

//get the name of the employee
string getEmployeeName()
{
	string name;		//to hold the name
	cout << "Enter the name of the employee: ";
	getline(cin, name);	//gets full name of person, including whitespace
	return name;
}

//get the number of hours worked by the employee
double getHoursWorked()
{
	double hours;		//hours worked
	cout << "Enter the number of hours worked: ";
	cin >> hours;
	return hours;
}
//get the wage per hour earned by the employee
double getHourlyWage()
{
	double wage;	//hourly wage
	cout << "Enter the hourly wage: ";
	cin >> wage;
	return wage;
}

//calculate regular time wage seperately 
double calculateRegTimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax)
{
	if (totalHoursWorked > regTimeMax)
	{
		return hourlyWage * regTimeMax;
	}
	else
	{
		return hourlyWage * totalHoursWorked;
	}
}

//calculate the overtime wage
double calculateOvertimeWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor)
{
	if (totalHoursWorked > regTimeMax)
	{
		return (totalHoursWorked - regTimeMax) * hourlyWage * otFactor;
	}
	else
	{
		return 0.0;
	}
}

//calculate the total wage
double calculateTotalWage(double totalHoursWorked, double hourlyWage, double regTimeMax, double otFactor)
{

	return calculateRegTimeWage(totalHoursWorked, hourlyWage, regTimeMax) + 
		calculateOvertimeWage(totalHoursWorked, hourlyWage, regTimeMax, otFactor);
}
