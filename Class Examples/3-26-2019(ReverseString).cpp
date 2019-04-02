/******************************
   Mr. Class Example
   26 March 2019
   3-26-2019(ReverseString).cpp
   Takes a string from the user and outputs it in
   reverse order then determines if it is a palindrome.

   def.	A palindrom is a word, phrase, or sequence that
		reads the same backward as forward
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>		//character manipulation
using namespace std;

// Function declarations
string reverseString(string word,
	bool caseLower = false);	//second parameter is a DEFAULT parameter
bool isPalindrome(string word);


int main()
{
	//variables
	string theWord;		//string from the user
	string reverseWord;	//the reverse string from the user
	char choice;		//choice for user


	do
	{
		cout << "Enter a word that you would like to reverse: ";
		getline(cin, theWord);

		try
		{
			//reverse the word
			reverseWord = reverseString(theWord);
		}
		catch (const char* errorMessage)
		{
			cout << errorMessage << endl;
			cout << endl;
			choice = 'Y';
			continue;
		}

		//output reversed word
		cout << theWord << " reversed is " << reverseWord << endl;

		//check if palindrome
		cout << theWord << " is ";
		if (!isPalindrome(theWord))
		{
			cout << "not ";
		}
		cout << "a palindrome\n";

		//see if user wants to enter another word
		cout << "\nDo you want to enter another word? (y/n): ";
		cin >> choice;

		while (getchar() != '\n');	//flush the stream
		cout << endl;

		choice = toupper(choice);

	} while (choice == 'Y');


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

//takes a string, optionally changes each letter to lower 
//case, and then reverses the string
string reverseString(string word, bool caseLower)
{
	//NEW TOPIC:
	//looking at a data structure (a way of organizing data):
	//a stack - a last in, first out structure (for example, a stack of books).
	//stacks add and remove from the top. To add an item, you PUSH an item. To remove
	//and item, you POP the item from the top of the stack
	//we will look at an array with a top index

	const int STACK_SIZE = 80;	//max size of stack
	char stack[STACK_SIZE];		//holds a stack of characters
	char reversed[STACK_SIZE];	//cstring, holds chars after reversing
	int top = -1;				//point to top of stack, -1 means the stack is empty
	int length = word.length();	//how many letters to process

	//make sure the word is not too long
	if (length > STACK_SIZE - 1)
	{
		throw "Word too long";
	}

	//put letters in the stack
	for (int i = 0; i < length; i++)
	{
		//push
		stack[++top] = word.at(i);		//word[i]
	}

	//pop the stack into reversed
	for (int i = 0; top >= 0; top--, i++)
	{
		reversed[i] = stack[top];
	}

	//see if we need to make case lower
	if (caseLower)
	{
		for (int i = 0; i < length; i++)
		{
			reversed[i] = tolower(reversed[i]);
		}
	}

	//add the null terminator
	reversed[length] = '\0';

	return string(reversed);
}

bool isPalindrome(string word)
{
	//reversed is all lower case
	string reversed = reverseString(word, true);

	//make the word all lower case
	for (int i = 0; i < word.length(); i++)
	{
		word.at(i) = tolower(word.at(i));
	}

	//loop throuhg half the letters in word and reversed
	for (int i = 0; i < (word.length() / 2) + 1; i++)
	{
		//are the two letters in same position different
		if (word.at(i) != reversed.at(i))
		{
			return false;
		}
	}
	return true;
}
