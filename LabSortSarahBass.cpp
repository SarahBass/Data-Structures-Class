/************************************************************
 ------------------------------------------------------------
Sarah Bass
Lab Sort
CS 41 Data Structures
-------------------------------------------------------------
Description: write a program, which will calculate the 
results of Reverse Polish expressions that are provided by 
the user.

-----------Objectives------------------------ 
-linked list to maintain stack
-Handles Errors:
                Too many operators (+ - / *)
                Too many operands (doubles)
                Division by zero
-No array implementations of stack allowed
----------------------------------------------
Program logic: 
The program will take in a Polish expression
that separates the operators and operands by a single space, 
and terminates the expression with an equals sign.

The program will continue to take and evaluate expressions 
until the user enters a zero (0) on a line by itself 
followed by a new line.
-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 

using namespace std;
//------------Sort Function---------------
void insertionSort(int arr[], int n);
//----------------------------------------

int main() {

	int x, n;
	cout << "Enter the Array Length:" << "\n";
	cin >>n;
	int *arr = new int(n);
	cout << "Enter " << n << " items to the array or type -1 to stop . " << endl;
	for (x = 0; x < n; x++) {
		cin >> arr[x];
		if (arr[x] == -1){
		arr[x] = 0;
		x = n;
		}    
		}
	    
cout << "Original Array : [";
for (int i = 0; i < n; i++){
cout <<  " " << arr[i] << ","; }
cout <<  " ] " << endl;

insertionSort(arr, n);

return 0;
}
//----------Function Bubble Sort------------
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted Array   : [";
        for (int x = 0; x < n; x++){
        cout <<  " " << arr[x] << ","; }
        cout <<  " ] " << endl;  
}