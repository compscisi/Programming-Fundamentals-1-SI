/******************************
   Mr. Class Example
   2 April 2019
   4-2-2019(HighTemps).cpp
   Displays average, max, min for high temps of various months.
********************************/

// Headers
#include <iostream>		//cout, cin
#include <cstdlib>		//exit, system
#include <string>		//strings, duh
#include <fstream>		//file processing
#include <iomanip>		//text formatting
using namespace std;

// Global variables
const int MAX_MONTHS = 12;						//max months we will process
const int MAX_DAYS = 30;						//max days per month we will process
const string FILENAME = "HighTemps2014.txt";	//file to process

// Function declarations
int loadMonthsTemps(string months[], int temps[][MAX_DAYS], string fileName, int maxMonths);
void displayAvgTemp(string months[], int temps[][MAX_DAYS], int monthCount);
void displayMaxTemp(string months[], int temps[][MAX_DAYS], int monthCount);
void displayMinTemp(string months[], int temps[][MAX_DAYS], int monthCount);
string getTempCondition(int temp);
int getLongestNameLength(string months[], int monthCount);
int displayHeading(string reportTitle, string secondColumnName, 
					int secondColumnWidth, int thirdColumnWidth,
					string months[], int monthCount);

int main()
{
	int monthCount = 0;					//number of months we are processing
	int temps[MAX_MONTHS][MAX_DAYS];	//table of temperatures
	string months[MAX_MONTHS];			//list of month names
	char choice;						//lady's choice

	//get months and temps
	try
	{
		monthCount = loadMonthsTemps(months, temps, FILENAME, MAX_MONTHS);
	}
	catch (const char* errorMessage)
	{
		cout << errorMessage << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
    
	//loop until the user says to quit
	do
	{
		//present the menu
		cout << "\nTemperature Report Program\n\n"
			<< "\t1. Display Average Temperature\n"
			<< "\t2. Display Maximum Temperature\n"
			<< "\t3. Display Minimum Temperature\n"
			<< "\t4. Quit Program\n\n";
		cout << "Enter your choice (1-4): ";
		cin >> choice;

		while (getchar() != '\n');	//flush

		//process the choice
		switch (choice)
		{
		case '1':	//average
			displayAvgTemp(months, temps, monthCount);
			break;
		case '2':	//maximum
			displayMaxTemp(months, temps, monthCount);
			break;	
		case '3':	//minimum
			displayMinTemp(months, temps, monthCount);
			break;
		case '4':	//quit
			break;
		default:
			cout << "Invalid option. Please try again.\n\n";
		}
	
		//clean up screen
		if (choice != '4')
		{
			cout << endl;
			system("PAUSE");
			system("CLS");
		}
		
	} while (choice != '4');		//notice this represents the CHARACTER 4, not the number 4
    
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

//load the file contents into months array and temps array
int loadMonthsTemps(string months[], int temps[][MAX_DAYS], string fileName, int maxMonths)
{
	ifstream inFile;		//input file stream
	string monthName,		//name of the month
		seasonName;			//name of the season
	int numMonths = 0;		//number of months actually read

	//open the file
	inFile.open(fileName);
	if (!inFile)
	{
		throw "File could not be opened";
	}

	//loop through each row of the file
	for (int i = 0; i < MAX_MONTHS && (inFile >> monthName >> seasonName); i++, numMonths++)
	{
		//combine the month name with the season name
		months[i] = monthName + " " + seasonName;
		//loop through all the temps of each row
		for (int j = 0; j < MAX_DAYS; j++)
		{
			inFile >> temps[i][j];
		}
	}

	//close the door, were you born in a barn?
	inFile.close();

	//test
	/*for (int i = 0; i < numMonths; i++)
	{
		cout << months[i] << " ";
		for (int j = 0; j < MAX_DAYS; j++)
		{
			cout << temps[i][j] << " ";
		}
		cout << endl;
	}*/
	return numMonths;
}

void displayAvgTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
}

void displayMaxTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
}

void displayMinTemp(string months[], int temps[][MAX_DAYS], int monthCount)
{
}

string getTempCondition(int temp)
{
	return string();
}

int getLongestNameLength(string months[], int monthCount)
{
	return 0;
}

int displayHeading(string reportTitle, string secondColumnName, int secondColumnWidth, int thirdColumnWidth, string months[], int monthCount)
{
	return 0;
}
