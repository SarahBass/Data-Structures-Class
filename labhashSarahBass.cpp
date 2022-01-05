/************************************************************
 ------------------------------------------------------------
Sarah Bass
Hash Table Lab
CS 41 Data Structures
Due: 10/28/2021
-------------------------------------------------------------
Define an array that holds 27 elements.
Define a function called Hash(int)
Define an add function that takes an integer.
Define a function that looks up a value.
Create a main to add and lookup items in the table.
-------------------------------------------------------------
************************************************************/
#include <iostream>

using namespace std;

const int SIZE = 27;	// a good strong prime number	
const int EMPTY = -1;	// -1 indicates that the cell is empty
#define DISPLAY true	// remove to disable debugging output

class HashTable
{
	int data;
	int table[SIZE];	// where our data will be held

	bool probe(int data) // linear probing function
	{
		int index = data % SIZE;
		int probeFcn = (index + 1) % SIZE; // start of the linear probing

		while (index != probeFcn)
		{
			#ifdef DISPLAY 
				cout << "Probing at " << probeFcn << ". ";
			#endif
			if (table[probeFcn] == EMPTY)
			{
				#ifdef DISPLAY 
					cout << "Inserted.\n";
				#endif
				table[probeFcn] = data;
				return true;
			}
			
			probeFcn = ++probeFcn % SIZE; // continuation of linear probing
		}
		#ifdef DISPLAY 
			cout << "===== TABLE FULL =====\n";
		#endif
		return false; // to get here index == probeFcn, which means we looped all the way around,
		// therefore the table is full
	}

public:
	HashTable()
	{
		#ifdef DISPLAY 
			cout << "Building hash table.\n";
		#endif
		for (int i = 0; i < SIZE; i++)
			table[i] = EMPTY;
	}

	bool add(int data)
	{
		#ifdef DISPLAY 
			cout << "Inserting " << data << " at ";
		#endif
		if (table[data % SIZE] == EMPTY) // apply the hash function first
		{
			#ifdef DISPLAY 
				cout << "at " << data % SIZE << endl;
			#endif
			table[data % SIZE] = data;
			return true;
		}
		else //otherwise we need to probe
			return probe(data);
	}

	int Hash(int data){
		return data % SIZE;
	}

	int SearchKey(int number){
		bool found = false;
		int count = 0;
		while (found == false && count < 27){
			if (number == (table[count])){
				cout << "Number found in Hash Table at position " << count << endl;
				found = true;
				count++;
			}else{count++;}
		}
	if (found  == false){
		cout << "Number not found in Hash Table" << endl;
		number = -1;
	}
	return number;
	}

};

int main (void)
{
    int number;
	HashTable *data = new HashTable();

   cout << endl;
    cout << "---------------------Start Hash Table---------------------" << endl;
    cout<< "                 -----ENTER 27 VALUES-----" << endl; 

	
for (int i = 0; i < 27; i++){
    
        cin >> number;
		data->add(number);
	}

cout << "Search for a number, Enter -999 to stop" << endl;
while (number != -999){
	cin >> number;
	if (number != -999){
		cout << "Searching for " << number << endl;
		data->SearchKey(number);
	}else {
		cout << "End of Search" << endl;
	}
}
	return 0;
}