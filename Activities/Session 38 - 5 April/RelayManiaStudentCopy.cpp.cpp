/**************************************************************
Relay Mania
Write a menu driven program that displays the contents of a file!
***************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>			//so we can use files
#include <cctype>			//for toupper() method
using namespace std;

// Global constants
const int MAX_SIZE = 80;	//max size of array

// Function prototype
int loadFile(string fileStuff[]);			//asks user for file to load then loads into 
											//array of strings
void displayFile(string lines[], int size);	//displays the file that is loaded

int main()
{
	//variables
	int choice;						//the users choice
	string fileContents[MAX_SIZE];	//the files contents with max lines to load set at 80
	int size;						//size of array

	//using a do-while loop so user can view multiple files
	do
	{
		//display menu and get input from user
		cout << "-------- FILE VIEWER --------\n";
		cout << "\t1. Load a File\n"
			<< "\t2. View the Loaded File\n"
			<< "\t3. Exit Program\n";
		cout << "\nEnter a choice from the menu above: ";
		cin >> choice;

		//flush the stream

		//process the users choice
		switch (choice)
		{
		case 1:	//load the file into an array of strings
			size = loadFile(fileContents);
			break;
		case 2:	//view the file currently loaded
			displayFile(fileContents, size);
			break;
		case 3:	//quit program
			break;
		default:
			cout << "Invaild option. Please try again.\n\n";
		}

		//if we arent quitting the program, flush the screen before looping again
		if (choice != 3)
		{
			cout << endl;
			system("PAUSE");
			system("CLS");
		}
	} while (choice != 3);


	cout << endl << endl;
	system("PAUSE");
	return 0;
}

int loadFile(string fileStuff[])
{
	//clear the current array
	
	//variables
	string fileName;		//name of the file
	string fileContent;		//what's in the file
	int count = 1;			//how many lines read in

	//ask user for file name
	cout << "Enter a file name: ";
	cin >> fileName;

	//open file
	ifstream inFile;
	inFile.open(fileName);

	if (!inFile)
		cout << "File did not load correctly. Please try again";
	else
		cout << "File loaded successfully!";

	//use file
	
	//CLOSE the file!!!
	inFile.close();
	//return size of array
	return count;
}

void displayFile(string lines[], int size)
{
	
}
