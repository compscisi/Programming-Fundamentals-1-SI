/******************************
Programming Challenge: C6 isPrime Function
A prime number is a number that is only evenly divisible by itself and 1. For example,
the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6,
however, is not prime because it can be divided evenly by 1, 2, 3, and 6.
Write a function name isPrime , which takes an integer as an argument and returns
true if the argument is a prime number, or false otherwise. Demonstrate the function
in a complete program.
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
	int num;		//number being checked
	bool flag;		//to signal if prime or not

	cout << "This program will check if a number entered is prime or not.\n\n";
	cout << "Please enter a number: ";
	cin >> num;

	flag = isPrime(num);

	if (flag == true)
	{
		cout << "The number " << num << " is prime!";
	}

	else if (flag == false)
	{
		cout << "The number " << num << " is not prime!";
	}
	
	cout << "\n\nGood luck with your maths.";
	
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
