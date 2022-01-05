#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define DISPLAY true

//
// Binary Search
//
// Binary Search has a O(lg n)
// The algorihtm reduces the possible solution set by approximately one half
// each time it iterates.
// In order for the search to work, the data that it operates on needs to 
// be ordered, the typical sense of this ordering is to have a ascendingly
// sorted list. There is another method to order our data, we will talk about
// that here as well.
//
// We are going to look at 3 different implementations of the binary search,
// two iterative and one recursive (The third method we will get into after
// we talk about trees)

class iterativeBinarySearch
{
private:
	int data[100];

public:
	iterativeBinarySearch()
	{
		load();
	};

	void load()
	{
		for (int i = 0; i < 100; i++)
		{
			data[i] = rand() % 100;
		}
		sort();
	}

	void sort()
	{
		for (int i = 0; i < 100; i++)
			for (int j = i + 1; j < 100; j++)
				if (data[i] > data[j])
				{
					int temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
	}

	void print()
	{
		cout << "The data\n";
		for (int i = 0; i < 100; i++)
			cout << data[i] << "\t";
	}

	int search(int key)
	{
		int lowerBound = 0, middle, upperBound = 99;
		while (lowerBound <= upperBound)
		{
			middle = (lowerBound + upperBound) / 2; // floored due to int nature
			#ifdef DISPLAY 
			cout << "Middle: " << middle << ". "; 
			#endif
			if (key < data[middle])
			{
				upperBound = middle - 1;			// eliminate the top half of the array
				#ifdef DISPLAY 
				cout << "Chopping off the top.\t";
				#endif
			}
			else if (key > data[middle])
			{
				lowerBound = middle + 1;
				#ifdef DISPLAY 
				cout << "Chopping off the bottom.\t";
				#endif
			}
			else
				return middle;						// send back the index
			
			#ifdef DISPLAY 
			cout << "New bounds: " << lowerBound << " - " << upperBound << endl;
			#endif
			
		}
		return -1;									// indicate that the element is not in the list
	}// end search
};

class recursiveBinarySearch
{
private:
	int data[100];

public:
	recursiveBinarySearch()
	{
		load();
		cout << "Index at: " << search(data[0], 0, 99) << endl;
	};

	void load()
	{
		for (int i = 0; i < 100; i++)
		{
			data[i] = rand() % 100;
		}
		sort();
	}

	void sort()
	{
		for (int i = 0; i < 100; i++)
			for (int j = i + 1; j < 100; j++)
				if (data[i] > data[j])
				{
					int temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
	}

	void print()
	{
		cout << "The data\n";
		for (int i = 0; i < 100; i++)
			cout << data[i] << "\t";
	}

	int search(int key, int lowerBound, int upperBound)
	{
		int middle = (lowerBound + upperBound) / 2;

		cout << "\nlowerBound = " << lowerBound << 
			" upperBound = " << upperBound << 
			" middle = " << middle << 
			" data[middle] = " << data[middle];
		if (lowerBound > upperBound)
			return -1;

		if (key < data[middle])
		{
			#ifdef DISPLAY 
			cout << " <=- left.";
			#endif
			search(key, lowerBound, middle - 1);
		}
		else if (key > data[middle])
		{
			#ifdef DISPLAY 
			cout << " right. -=>";
			#endif
			search(key, middle + 1, upperBound);
		}
		else
			return middle;
	}
}; //
int main (void)
{
	srand((unsigned)time(0));
	iterativeBinarySearch ibs;
	ibs.print();

	cout << "*******************************\n" <<
		    "*    Iterative Example 1      *\n" <<
			"*******************************\n" ;

	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 100;
		cout << "Searching for " << key << endl;
		int index = ibs.search(key);
		cout << " its index is " << index << endl;
	}


	cout << endl <<
			"*******************************\n" <<
		    "*    Recursive Example 1      *\n" <<
			"*******************************\n" ;

	recursiveBinarySearch rbs;
	rbs.print();

	for (int i = 0; i < 10; i++)
	{
		int key = rand() % 100;
		cout << "Searching for " << key << endl;
		int index = rbs.search(key, 0, 99);
		cout << " its index is " << index << endl;
	}

	return 0;
}