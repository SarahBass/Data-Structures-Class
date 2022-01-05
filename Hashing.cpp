#include <iostream>

using namespace std;

const int SIZE = 17;	// a good strong prime number	
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

	bool insert(int data)
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
	void SearchKey(int number){
		bool found = false;
		int count = 0;
		while (found != true || count < 28){
			if (number == table[count]){
				cout << "Number found in Hash Table at position " << count << endl;
				found = true;
			}else{
		count++;}
		}
	if (count > 27 && found  == false){
		cout << "Number not found in Hash Table" << endl;
	}
	}
};

int main (void)
{
	HashTable *data = new HashTable();
	data->insert(10);
	data->insert(20);
	data->insert(30);
	data->insert(40);
	data->insert(50);
	data->insert(10);
	data->insert(6);
	data->insert(60);
	data->insert(70);
	data->insert(80);
	data->insert(90);
	data->insert(100);
	data->insert(110);
	data->insert(120);
	data->insert(130);
	data->insert(140);
	data->insert(150);
	data->insert(160);
	data->insert(170);
	data->insert(180);
	data->insert(190);
	return 0;
}