/**************************************************************
PASS THE KEYBOARD
Using the template below, write a program that asks
the user to enter the name of file and then displays
the contents of the file. There are a few text files that
need to be included in the project folder for this program:
	- FileOne.txt
	- FileTwo.txt
	- FileThree.txt
The goal is that the user should be able to view any given text 
file using this program.
THE CATCH IS: One person may write a section of code at a time.
***************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>			//so we can use files
#include <cctype>			//for toupper() method
using namespace std;

// Function prototype
void displayFile(string fileName);		//function to display file

int main()
{
	//variables
	string fileName;		//the files name!
	char choice;			

	//using a do-while loop so user can view multiple files
	do
	{
		//get input from user
		cout << "\nEnter the name of the file you would like to display: ";
		cin >> fileName;
		cout << endl ;
		//display file
		displayFile(fileName);
		//ask if user wants to continue
		cout << "\n\nWould you like to load a different file(y/n): ";
		cin >> choice;
		//make sure the choice is upper case
		choice = toupper(choice);
		if (choice == 'Y')
		{
			system("PAUSE");
			system("CLS");
		}
	} while (choice == 'Y');
	

	cout << endl << endl;
	system("PAUSE");
	return 0;
}

void displayFile(string fileName)
{
	ifstream inFile;
	string fileStuff;

	inFile.open(fileName);
	//validate the input
	if (inFile.fail())
	{
		cout << "File did not load correctly!";
	}
	else
	{
		//header to make it look pretty if the file loads
		cout << "\n----- FILE CONTENTS -----\n";
	}
	//using the while look to read a line of the file into a string variable
	while (getline(inFile, fileStuff))
	{
		//output the line to the screen
		cout << fileStuff << endl;
	}

	inFile.close();
}
