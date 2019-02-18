/******************************
Programming Challenge: Kinetic Energy
In physics, an object that is in motion is said to have kinetic energy. The following
formula can be used to determine a moving object’s kinetic energy:
KE = (1/2)(mv^2)
The variables in the formula are as follows: KE is the kinetic energy, m is the object’s
mass in kilograms, and v is the object’s velocity, in meters per second.
Write a function named kineticEnergy that accepts an object’s mass (in kilograms)
and velocity (in meters per second) as arguments. The function should return the
amount of kinetic energy that the object has. Demonstrate the function by calling it in
a program that asks the user to enter values for mass and velocity.
********************************/

// Headers
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

// Global variables

// Function declarations

int main()
{
	//main is already complete. Your function should work with the following code.
		//variables
	double mass,		//objects mass in kg
		velocity,		//objects velocity in m/s
		kineticE;		//object's kinetic energy

		//display beginning output
	cout << "This program will calculate the kinetic energy of a given object.";
	cout << "\n\nPlease enter the objects mass in kilograms: ";
	cin >> mass;
	cout << "Please enter the objects velocity in meters per second: ";
	cin >> velocity;

		//calculate kinetic energy
	kineticE = kineticEnergy(mass, velocity);

		//display results
	cout << "\n\nThe given object has a kinetic energy of " << kineticE << " Joules.";

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
