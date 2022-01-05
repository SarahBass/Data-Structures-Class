#include<iostream>

using namespace std;

int main (void)
{
	int i;	
	i = 5;

	cout << "i is initialized to " << i << endl;

	int *p;
	p = &i;
	cout << "p is initialized to " << p << endl;

	cout << "The value of i is " << i << endl;
	cout << "The value of i via *p is " << *p << endl;

	*p = 10;
	cout << "The value of i is " << i << endl;
	cout << "The value of i via *p is " << *p << endl;

	return 0;
}