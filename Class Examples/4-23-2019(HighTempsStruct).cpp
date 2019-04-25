/******************************
   Mr. Class Example
   23 April 2019
   HighTempsStruct.cpp
   Display average, min, max for high temps
   of various months sorted
   
   NOTE: You will need the correct text file (Hightemps2014.txt) loaded into your 
   project folder, just like you have a .cpp file loaded in your project folder.
   This text file can be found in the Class Examples folder.
********************************/

// Headers
#include <iostream>	//cout, cin
#include <cstdlib>	//exit
#include <string>	//strings, duh
#include <fstream>	//file processing
#include <iomanip>	//output formatting
#include <vector>	//so we can use a vector
using namespace std;

//structure for month-temperatures
struct MonthTemps
{
	string name;		//name of month
	string season;		//name of season month is in
	double average;		//average of all temps for month
	int max;			//maximum temp for month
	int min;			//minimum temp for month
};

// Global variables
const string FILENAME = "HighTemps2014.txt";		//file to read

// Function declarations
void loadMonthsTemps(vector<MonthTemps>& months, string fileName);
void displayAvgTemp(vector<MonthTemps>& months);
void displayMaxTemp(vector<MonthTemps>& months);
void displayMinTemp(vector<MonthTemps>& months);
string getTempCondition(int temp);
int getLongestNameLength(const vector<MonthTemps>& months);
void swap(MonthTemps& a, MonthTemps &b);
void bubbleSort(vector<MonthTemps>& months,
	bool(*doSwapTest)(MonthTemps&, MonthTemps&));
bool doAvgSwapTest(MonthTemps& first, MonthTemps& second);
bool doMaxSwapTest(MonthTemps& first, MonthTemps& second);
bool doMinSwapTest(MonthTemps& first, MonthTemps& second);

int main()
{
	//	Your code goes here
	vector<MonthTemps> months;	//MonthTemps collection
	char choice;				//lady's choice

	//get months and temps from file
	try
	{
		loadMonthsTemps(months, FILENAME);
	}
	catch (const char* message)
	{
		cout << message << endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
    
	//loop until user says to quit
	do
	{
		//present the menu
		cout << "\nTemperature Report Program\n\n";
		cout << "\t1. Display Average Temperature\n"
			<< "\t2. Display Maximum Temperature\n"
			<< "\t3. Display Minimum Temperature\n"
			<< "\t4. Quit Program\n\n";
		cout << "Enter your choice(1-4): ";
		cin >> choice;

		while (getchar() != '\n');	//flush the stream

		//process the choice
		switch (choice)
		{
		case '1':	//average
			displayAvgTemp(months);
			break;
		case '2':	//maximum
			displayMaxTemp(months);
			break;
		case '3':	//minimum
			displayMinTemp(months);
			break;
		case '4':	//quit
			break;
		default:
			cout << "Invalud option. Please try again.\n\n";
		}	//end switch

		//clean up screen
		if (choice != '4')
		{
			cout << endl;
			system("PAUSE");
			system("CLS");
		}

	} while (choice != '4');
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

//load data from file into vector of MonthTemps
//calculate average, minimum, and maximum for each month
//assumes each month has at least one temp
void loadMonthsTemps(vector<MonthTemps>& months, string fileName)
{
	ifstream iFile;		//input file stream
	int total = 0;		//accumulator for total of temps
	int max;			//max temp for month
	int min;			//min temp for month
	int currentTemp;	//current temp for day
	MonthTemps month;	//temporary MonthTemp for getting MonthTemp data
	int numTemps = 0;	//how many temps for the current months


	//open the file
	iFile.open(fileName);

	if (!iFile)
	{
		throw "Cannot open file " + fileName;
	}

	//read file info
	while (iFile >> month.name >> month.season)
	{
		//get the first temp and place in total, max, and min
		iFile >> total;
		max = min = total;
		numTemps = 1;

		while (iFile >> currentTemp)
		{
			numTemps++;
			total += currentTemp;
			if (currentTemp > max) max = currentTemp;
			if (currentTemp < min) min = currentTemp;
		}//end
		iFile.clear();	//removes the fail

		month.average = static_cast<double>(total) / numTemps;
		month.max = max;
		month.min = min;
		months.push_back(month);
	}//end of outer while loop

	iFile.close();

	//test
	/*for (int i = 0; i < months.size(); i++)
	{
		cout << months[i].name << " "
			<< months[i].season << " "
			<< months[i].average << " "
			<< months[i].max << " "
			<< months[i].min << endl;
	}*/
}

//display average temp with descending sort
void displayAvgTemp(vector<MonthTemps>& months)
{
	//get the length of the longest name
	int maxLength = getLongestNameLength(months) + 1;

	cout << setprecision(1) << fixed << showpoint;

	//show the table header
	cout << "\n\nTemperature Averages\n";
	cout << setw(maxLength) << left << "Month"
		<< setw(8) << right << "Average"
		<< setw(10) << "Condition" << endl;

	//sort months by average
	bubbleSort(months, doAvgSwapTest);

	//display the table
	for (int i = 0; i < months.size(); i++)
	{
		cout << setw(maxLength) << left
			<< (months[i].name + " " + months[i].season);
		cout << setw(8) << right << months[i].average
			<< setw(10) << getTempCondition(months[i].average)
			<< endl;
	}
}

void displayMaxTemp(vector<MonthTemps>& months)
{
	//get the length of the longest name
	int maxLength = getLongestNameLength(months) + 1;

	//show the table header
	cout << "\n\nTemperature Maximums\n";
	cout << setw(maxLength) << left << "Month"
		<< setw(8) << right << "Maximum"
		<< setw(10) << "Condition" << endl;

	//sort months by average
	bubbleSort(months, doMaxSwapTest);

	//display the table
	for (int i = 0; i < months.size(); i++)
	{
		cout << setw(maxLength) << left
			<< (months[i].name + " " + months[i].season);
		cout << setw(8) << right << months[i].max
			<< setw(10) << getTempCondition(months[i].max)
			<< endl;
	}
}

void displayMinTemp(vector<MonthTemps>& months)
{
	//get the length of the longest name
	int maxLength = getLongestNameLength(months) + 1;

	//show the table header
	cout << "\n\nTemperature Minimums\n";
	cout << setw(maxLength) << left << "Month"
		<< setw(8) << right << "Minimum"
		<< setw(10) << "Condition" << endl;

	//sort months by average
	bubbleSort(months, doMinSwapTest);

	//display the table
	for (int i = 0; i < months.size(); i++)
	{
		cout << setw(maxLength) << left
			<< (months[i].name + " " + months[i].season);
		cout << setw(8) << right << months[i].min
			<< setw(10) << getTempCondition(months[i].min)
			<< endl;
	}
}

//get the condition according to temperature
string getTempCondition(int temp)
{
	if (temp > 110)
		return "Heck";
	else if (temp > 100)
		return "Scorching";
	else if (temp > 90)
		return "Hot";
	else if (temp > 80)
		return "Warm";
	else if (temp > 70)
		return "Mild";
	else if (temp > 60)
		return "Cool";
	else
		return "Cold";
}

//return the length of the longest string in months
int getLongestNameLength(const vector<MonthTemps>& months)
{
	int maxLength = 0;
	for (int i = 0; i < months.size(); i++)
	{
		int length = months[i].name.length() + months[i].season.length() + 1;
		if (length > maxLength)
		{
			maxLength = length;
		}
	}
	return maxLength;
}

//swap a with b
void swap(MonthTemps & a, MonthTemps & b)
{
	MonthTemps temp;
	temp = a;
	a = b;
	b = temp;
}

//sort months based on attribute of doSwapTest
//descending sort
void bubbleSort(vector<MonthTemps>& months, bool(*doSwapTest)(MonthTemps &, MonthTemps &))
{
	bool didSwap = false;

	for (int i = months.size() - 1; i > 0; i--)
	{
		didSwap = false;		//assume no swaps
		for (int j = 0; j < i; j++)
		{
			if ((*doSwapTest)(months[j], months[j + 1]))
			{
				swap(months[j], months[j + 1]);
				didSwap = true;
			}
		}//end of inner loop
		if (!didSwap) break;
	} //end of outer loop
}

//compares averages of MonthTemps
bool doAvgSwapTest(MonthTemps & first, MonthTemps & second)
{
	return first.average < second.average;
}

//compare maximums of MonthTemps
bool doMaxSwapTest(MonthTemps & first, MonthTemps & second)
{
	return first.max < second.max;
}

//compare minimums of MonthTemps
bool doMinSwapTest(MonthTemps & first, MonthTemps & second)
{
	return first.min < second.min;
}
