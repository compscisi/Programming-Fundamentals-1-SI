/****************************************************************************************************************
Write a program that computes and displays the charges for a patient’s hospital stay.
First, the program should ask if the patient was admitted as an in-patient or an outpatient.
If the patient was an in-patient, the following data should be entered:
• The number of days spent in the hospital
• The daily rate
• Hospital medication charges
• Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an out-patient:
• Charges for hospital services (lab tests, etc.)
• Hospital medication charges
The program should use two overloaded functions to calculate the total charges. One
of the functions should accept arguments for the in-patient data, while the other function
accepts arguments for out-patient information. Both functions should return the
total charges.
Input Validation: Do not accept negative numbers for any data.

NOTE: While this may seem difficult, I promise this is on your level. YOU CAN DO THIS!!!
I have taken the liberty of doing any necessary loops for you in main(). The loops are entirely optional. If
you do not want to use loops, you can just have the program quit if a user enters a negative value. 

********************************************************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototype
//you stub these out and write them
double calcData(int, double, double, double);	//This function accepts the arguments for in-patient data, 
												//calculates and returns the total charges.

double calcData(double, double);				//This function accepts the arguments for out-patient data, 
												//calculates and returns the total charges.

int main()
{
	//You should write most of main, 
	//below are some loops that you can include in your selection statements
	/* LOOPS: (Copy and paste these into your code as you need them. These should be use in the selection statements
				that you are using!!)

	//this makes it to where the user can't enter negative days
	do
	{
		cout << "How many days were spent in the hospital? ";
		cin >> NumOfDays;

		if (NumOfDays < 0)
		{
			cout << "Number of days must be greater than 0.\n";
		}

	} while (NumOfDays < 0);

	//this makes it to where the user cannot enter a negative daily rate
	do
	{
		cout << "What was the daily rate? ";
		cin >> DailyRate;

		if (DailyRate < 0)
		{
			cout << "Daily rate must be greater than 0.\n";
		}

	} while (DailyRate < 0);

	//this makes it to where the user can't enter negative values for the hospital
	do
	{
		cout << "Enter the charges for hospital services "
			<< "(lab tests, etc.): ";
		cin >> ServChges;

		if (ServChges < 0)
		{
			cout << "Charges for hospital services must be "
				"greater than 0.\n";
		}

	} while (ServChges < 0);

	//this makes it to where the hospital charges cannot be negative
	do
	{
		cout << "Enter the hospital medication charges: ";
		cin >> MedChges;

		if (MedChges < 0)
		{
			cout << "Hospital medication charges must be greater"
				<< " than 0.\n";
		}

	} while (MedChges < 0); */

	system("PAUSE");
	return 0;
}
