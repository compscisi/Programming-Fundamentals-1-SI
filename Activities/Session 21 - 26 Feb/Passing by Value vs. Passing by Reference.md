# Passing by Value vs. Passing by Reference
###### NOTE: This is not planned to be worked on in session, but it may help you if you're feeling lost.
1. [Check out this website!](https://www.mathwarehouse.com/programming/passing-by-value-vs-by-reference-visual-explanation.php) This has a neat graphic visual.
2. Look at some of the responses [on this forum](https://stackoverflow.com/questions/373419/whats-the-difference-between-passing-by-reference-vs-passing-by-value) to see different explanations. If one response doesn't make sense, look at a different response!
3. Check yourself with the following bits of code to see if you can predict the output:
#### Snippet 1:
```
#include <iostream>
using namespace std;
void test(int = 2, int = 4, int = 6);
int main()
{
  test();
  test(6);
  test(3, 9);
  test(1, 5, 7);
  return 0;
}
void test (int first, int second, int third)
{
  first += 3;
  second += 6;
  third += 9;
  cout << first << " " << second << " " << third << endl;
}
```
#### Snippet 2:
```
#include <iostream>
using namespace std;
void func1(int &, int &);
void func2(int &, int &, int &);
void func3(int, int, int);
int main()
{
  int x = 0, y = 0, z = 0;
  cout << x << " " << y << " " << z << endl;
  func1(x, y);
  cout << x << " " << y << " " << z << endl;
  func2(x, y, z);
  cout << x << " " << y << " " << z << endl;
  func3(x, y, z);
  cout << x << " " << y << " " << z << endl;
  return 0;
}
void func1(int &a, int &b)
{
  cout << "Enter two numbers: ";
  cin >> a >> b;
}
void func2(int &a, int &b, int &c)
{
  b++;
  c−−;
  a = b + c;
}
void func3(int a, int b, int c)
{
  a = b − c;
}
```
#### Output to check yourself:
Snippet 1 ouputs:
```
5 10 15
9 10 15
6 15 15
4 11 16
```
Snippet 2 outputs:
```
0 00
Enter two numbers: 12 14
12 140
14 15-1
14 15-1
```
