/************************************************************
 ------------------------------------------------------------
Sarah Bass
Linear Search
CS 41 Data Structures
Description: Search an un-ordered array an integers for a value, 
if the value is found return the index of its position in the array, if not found, return -1.
-------------------------------------------------------------
A linear search starts at position 0 to the end of an array. 
-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 
#include<string>
#include <array> 

using namespace std;

int linearSearch(int unorderedArray[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++){
        if (unorderedArray[i] == key){
            return i;}
    }
return -1;
    
}

int main() {
int key = 100;
int unorderedArray[] = {1, 3, 4, 88, 99, 1, 17, 2, 5, 10 };
int n = sizeof(unorderedArray) / sizeof(unorderedArray[0]);
int result;

//call function 
result = linearSearch( unorderedArray, n, key);

cout << "The function will return a -1 if number is not in Array." << endl;
cout << "Linear Search in array for the number : " << key <<endl;
if (result == -1){
    cout << "NOT FOUND IN ARRAY" << endl;}
else {
    cout << "The index position of the number in the array is " << result << endl;
}

return result;
}