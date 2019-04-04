/**************************************************************
This is the copy worked out in the SI Session.
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
	string fileName;



	cout << "Enter name of file: ";
	getline(cin, fileName);



	displayFile(fileName);



	//loop to get user input and display file
	

	cout << endl << endl;
	system("PAUSE");
	return 0;
}

void displayFile(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);



	if (!inFile)
	{
		cout << "File could not open." << endl;
	}


	string fileRead;
	while (getline(inFile, fileRead))
	{
		cout << fileRead << endl;
	}
}
