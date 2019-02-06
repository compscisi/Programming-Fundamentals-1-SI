/*******************************************************************************]
This is the solution to the problem presented in staticcast.cpp

This program should be able to tell you the ASCII value of any character you 
enter into the program.
********************************************************************************/

#include <iostream>
using namespace std;
int main()
{
  char letter;
  
  //prompt user to enter a character
  cout << "Please enter a charact: ";
  cin >> letter;
  
  //display the letter that the user entered as an ASCII value
  cout << "The ASCII value for " << letter << " is " << static_cast<int>(letter);
  
  //EXPLANATION: remember that an ASCII value is the integer value of a symbol or character!
  //So, we used static cast to turn a char into an integer. This is the ASCII value.
  
  system("PAUSE");
  
  return 0;
}
