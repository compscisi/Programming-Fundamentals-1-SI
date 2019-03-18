/****************************************************************************************************************
Areas of Rectangles

The area of a rectangle is the rectangle’s length times its width. Write a program that
asks for the length and width of two rectangles. The program should tell the user which
rectangle has the greater area, or if the areas are the same.
********************************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototype
double calcArea(double length, double width);			//calculates the area of a given rectangle
void displayGreater(double area1, double area2);		//displays the greater area

int main()
{
	//variables
	double tempLength, tempWidth;	  //length of rectangle 1 and rectangle 2
	double area1, area2;	        	//area of rectangle 1 and rectangle 2

	//get user to input values
	cout << "----- GREATER AREA FINDER -----"
		<< "\nThis program will find the greater area given the dimmensions of two rectangles."
		<< "Please input the values below to determine rectangle with the greatest area.";

	cout << endl << endl;
	system("PAUSE");
	return 0;
}
