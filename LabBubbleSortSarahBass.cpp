/************************************************************
 ------------------------------------------------------------
Sarah Bass
Lab Sort
CS 41 Data Structures
-------------------------------------------------------------
Description: Using O(n^2) logic to sort - bubble sort
Objective:  Write a sort function that takes an array 
and sorts the values. 
-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 

using namespace std;
//Sort Functions--------------------------
void bubbleSort(int *array, int length);
void swapping(int &a, int &b);
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

bubbleSort(arr, n);

return 0;
}
//----------Function Bubble Sort------------
void bubbleSort(int *array, int size) {
   for(int i = 0; i<size; i++) {
      int swaps = 0;         
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {       
            swapping(array[j], array[j+1]);
            swaps = 1;    
         }
      }
      if(!swaps){
        cout << "Sorted Array   : [";
        for (int x = 0; x < size; x++){
        cout <<  " " << array[x] << ","; }
        cout <<  " ] " << endl;  
         break;       
   }
}
}  

//----------Function Swapping----------

void swapping(int &a, int &b) {      
   int temp;
   temp = a;
   a = b;
   b = temp;
}