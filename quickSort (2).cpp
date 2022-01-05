#include <iostream>		// input output classes
#include <time.h>		// gives us access to the system clock, needed for randomization
#include <stdlib.h>		// gives us access to srand and rand, allowing different data for each run

using namespace std;
const int SIZE = 10;	// the size of our array, feel free to change it, but don't make it too big
						// as there is alot of output for this, and output is a bit slow

void swap(int *first, int *second) // pointers, so we want the actual variable, not a copy of it
{
	int temp = *first;	// temp variable equals the value of first, the * dereferences the pointer
	*first = *second;	// the value held at first = the value held at second;
	*second = temp;		// finish the swap
}

void printArray(int array[], int arraySize)
{
	cout << "The array: ";
	for (int i = 0; i < arraySize; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void quickSort(int array[], int beg, int end)
{
	//
	// This implementation is based of the one in the book on page 495
	// Here we choose the middle of the array as the pivot, in hopes
	// of avoiding bad partitioning in the case of the data already being sorted
	//
	int left = beg + 1, right = end;
	
	cout << "Choose the middle element of the array as the pivot: " << array[(beg+end)/2] << endl;
	swap(array[beg], array[(beg+end)/2]);

	cout << "Swap the pivot into the first position\n";
	int pivot = array[beg];

	printArray(array, SIZE);

	while (left <= right)
	{
	cout << "Pivot: " << pivot << " left: " << left << " right: " << right << endl;
		while (left < end && array[left] < pivot)
		{
			left++; // moving to the right until we find someone out of place
			cout << "left++: " << left << endl;
		}

		while (right > beg && array[right] >= pivot)
		{
			right--; // moving to the left until we find someone out of place
			cout << "right-- " << right << endl;
		}

		if (left < right)
		{
			cout << "Swap " << array[left] << " with " << array[right] << endl;
			swap(&array[left++], &array[right--]);
			printArray(array, SIZE);
		}
		else
			left++;
	}

	printArray(array, SIZE);
	cout << "Swapping pivot value into place at: " << right << endl;
	swap (&array[right], &array[beg]);
	printArray(array, SIZE);

	if (beg < right - 1)
	{
		cout << "\nRecursive call for the left side\n";
		quickSort(array, beg, right-1);
	}

	if (right + 1 < end)
	{
		cout << "\nRecursive call for the right side\n";
		quickSort(array, right + 1, end);
	}
}


void loadArray(int array[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
		array[i] = rand() % 1000;
}

int main (void)
{
	srand((unsigned)time(NULL));
	int array[SIZE];

	loadArray(array, SIZE);
	printArray(array, SIZE);

	quickSort(array, 0, SIZE - 1);


	return 0;
}
