#include <iostream>

using namespace std;

void bubbleSort(int *array, int length);
void print(int *array);
int SelectionExample();
void insertion_sort( int *array);

const int SIZE	=	5;

int main()
{
	int arr[5] = {3, 6, 2, 4, 9};
	
	SelectionExample();
	print(arr);
	insertion_sort(arr);
	print(arr);
	/*print(arr);
	bubbleSort(arr, SIZE);
	print(arr);*/
	return 0;
}

void print(int *array)
{
	cout << "The List: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << array[i] << endl;
}

void bubbleSort(int *array, int length)
{ 
	int i, j, temp;
	int test; /*use this only if unsure whether the list is already sorted or not*/
	for(i = length - 1; i > 0; i--)
	{
		test=0;
		for(j = 0; j < i; j++)
		{
			if(array[j] > array[j+1]) /* compare neighboring elements */
			{
				temp = array[j];    /* swap array[j] and array[j+1] */
				array[j] = array[j+1];
				array[j+1] = temp;
				test=1;
			}
		} /*end for j*/
	if(test==0) 
		break; /*will exit if the list is sorted!*/
	} /*end for i*/
      
}/*end bubbleSort*/

// Declaration of swap function
void swap(int &m, int &n);

int SelectionExample() 
{
    int N = 10;
    int a[10] = {52, 1, 12, 16, 99, 1002,
        2001, 0, 79, 99};

    // Selection Sort
    for (int i = 0; i < (N - 1); i++)
    {
        int minIndex = i;

        // Find the index of the minimum element
        for (int j = i + 1; j < N; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap if i-th element not already smallest
        if (minIndex > i) 
        {
            swap(a[i], a[minIndex]);
        }
    }


    // Print sorted results
    for (int i = 0; i < N; i++)
    {
        cout << i << " " << a[i] << endl;
    }

    return 0;
}

void swap(int &x, int &y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
} 


void insertion_sort( int *array)
{
     int i, j, key, array_length= SIZE;
     for(j = 1; j < array_length; j++)    //Notice starting with 1 (not 0)
    {
           key = array[j];
           for(i = j - 1; (i >= 0) && (array[i] > key); i--)   //Move smaller values up one position
          {
                 array[i+1] = array[i];
          }
         array[i+1] = key;    //Insert key into proper position
     }
     return;
}