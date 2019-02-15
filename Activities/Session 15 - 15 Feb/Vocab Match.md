# Vocab Match
###### Below is the sample program that you will use to fill out the corresponding worksheet. With each question, give the line of code that you can find that variable on.

### Code:
```
1   // This program uses a function that returns a value.
2   #include <iostream>
3   using namespace std;
4
5   // Function prototype
6   int sum(int, int);
7
8   int main()
9   {
10    int value1 = 20, // The first value
11    value2 = 40, // The second value
12    total; // To hold the total
13
14    // Call the sum function, passing the contents of
15    // value1 and value2 as arguments. Assign the return
16    // value to the total variable.
17    total = sum(value1, value2);
18
19    // Display the sum of the values.
20    cout << "The sum of " << value1 << " and "
21        << value2 << " is " << total << endl;
22    return 0;
23  }
24
25  //*****************************************************
26  // Definition of function sum. This function returns *
27  // the sum of its two parameters. *
28  //*****************************************************
29
30  int sum(int num1, int num2)
31  {
32    return num1 + num2;
33  }
```

### This program will output:
```
The sum of 20 and 40 is 60
```
