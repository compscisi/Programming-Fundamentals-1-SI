/******************************
   Mr. Class Example
   February 28, 2019
   GeomCalc.cpp
   Calculate the area of various shapes.
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class InvalidDimensionException {};

// Global variables
const double PI = 3.14159;		//PI are round

// Function declarations
template <typename T>
T getValidatedInput();

double areaCircle(double radius);
double areaRectangle(double width, double length);
double areaTriangle(double base, double height);

int main()
{
	//	Your code goes here
	double width, height, radius, area;	//hold out dimensions
										//for shapes
	char choice;						//lady's choice

	do
	{
		//display the menu and get the choice
		cout << "Geometry Calculator\n\n"
			<< "\t1. Calculate the Area of a Circle\n"
			<< "\t2. Calculate the Area of a Rectangle\n"
			<< "\t3. Calculate the Area of a Triangle\n"
			<< "\t4. Quit\n\n";

		cout << "Enter your choice (1-4): ";
		cin >> choice;

		while (getchar() != '\n');	//empty the buffer

		//process the choice and display the results
		switch (choice)
		{
		case '1':	//circle
			try
			{
				cout << "\nEnter the radius of the circle: ";
				radius = getValidatedInput<double>();			//throw exception if it's not a real num
				area = areaCircle(radius);						//still throws exception if negative
				cout << "The area of a circle with radius "
					<< radius << " is " << area << endl;
			}
			//need to catch the throw if exceptionb thrown
			catch (ios_base::failure e)
			{
				cout << e.what() << endl;		//outputs invalid input
			}
			catch (InvalidDimensionException)
			{
				cout << "Invalide radius\n";
			}
			break;

		case '2':	//rectangle
			try
			{
				cout << "\nEnter the width of the rectangle: ";
				width = getValidatedInput<double>();			//making sure it's a real num!!!!
				cout << "\nEnter the length of the rectangle: ";
				height = getValidatedInput<double>();			//making sure it's a real num!!!!

				area = areaRectangle(width, height);
				cout << "The area of a rectangle with width of "
					<< width << " and length of " << height
					<< " is " << area << endl;
			}
			catch (ios_base::failure e)
			{
				cout << e.what() << endl;		//outputs invalid input
			}
			catch (InvalidDimensionException)
			{
				cout << "Invalide length or width\n";
			}
			break;

		case '3':		//triangle
			try
			{
				cout << "\nEnter the base of the triangle: ";
				width = getValidatedInput<double>();
				cout << "\nEnter the height of the triangle: ";
				height = getValidatedInput<double>();

				area = areaTriangle(width, height);
				cout << "The area of a triangle with base "
					<< width << " and height of : " << height
					<< " is " << area << endl;

			}
			catch (ios_base::failure e)
			{
				cout << e.what() << endl;		//outputs invalid input
			}
			catch (InvalidDimensionException)
			{
				cout << "Invalide base or height\n";
			}
			break;

			case '4':	// quit
				cout << "\nQuitter!\n";
				break;

			default:
				cout << endl << choice << " is not a valid choice\n";
			}
	
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

template <typename T>
T getValidatedInput()
{
	// Get input of type T
	T result;
	cin >> result;

	// Check if the failbit has been set, meaning the beginning of the input
	// was not type T. Also make sure the result is the only thing in the input
	// stream, otherwise things like 2b would be a valid int.
	if (cin.fail() || cin.get() != '\n')
	{
		// Set the error state flag back to goodbit. If you need to get the input
		// again (e.g. this is in a while loop), this is essential. Otherwise, the
		// failbit will stay set.
		cin.clear();

		// Clear the input stream using and empty while loop.
		while (cin.get() != '\n');

		// Throw an exception. Allows the caller to handle it any way you see fit
		// (exit, ask for input again, etc.)
		throw ios_base::failure("Invalid input.");
	}

	return result;
}

//calculates the area of a circle from the radius
double areaCircle(double radius)
{
	if (radius < 0.0)
	{
		throw InvalidDimensionException();
	}
	return PI * radius * radius;
}


//calculate area of rectangle from width and length
double areaRectangle(double width, double length)
{
	if (width < 0.0 || length < 0.0)
	{
		throw InvalidDimensionException();
	}
	return width * length;
}

//calculate the area of a triangle using base and height
double areaTriangle(double base, double height)
{
	if (base < 0.0 || height < 0.0)
	{
		throw InvalidDimensionException();
	}
	return .5 * base * height;
}
