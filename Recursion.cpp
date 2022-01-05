#include<iostream>
using namespace std;

int Summation(int n)
{
	if (n < 1)
		return 0;
	return Summation(n - 1) + n;
}
int Fibo(int n)
{
	if (n < 2)
		return 1;
	return Fibo(n - 1) + Fibo(n - 2);
}

int SummationIterative(int n)
{
	int total = 0;
	for (int i = 0; i <= n; i++)
	{
		total += i;
	}
	return total;
}

int SummationMath(int n)
{
	return n * (n + 1) / 2;
}//

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
// k = lower bound
// m = upper bound
void permutate(int list[], int k, int m)
{
	int i;
	if (k == m)
	{
		for (i = 0; i <= m; i++)
			cout << list[i];
		cout << " ";
	}
	else
		for (i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutate(list, k + 1, m);
			swap(list[k], list[i]);
		}
}

int main()
{
	cout << Summation(5) << endl;
	cout << SummationIterative(5) << endl;
	cout << SummationMath(5) << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "Fibonacci of " << i << " is " << Fibo(i) << endl;
	}

	int *numbers = new int[5] { 1, 2, 3, 4, 5 };
	permutate(numbers, 0, 4);

	system("pause");
	return 0;
}
