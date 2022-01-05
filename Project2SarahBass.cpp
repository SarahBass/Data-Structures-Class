/************************************************************
 ------------------------------------------------------------
Sarah Bass
Program 2
CS 41 Data Structures
Due: 10/3/2021
-------------------------------------------------------------
1. Read names & weights for 15 people from the console.
2. Creates a list for the data maintained in ascending order 
   based on both name and weight via a doubly linked list.
3. Use one pointer to keep weights in sorted order. 
4. Use the other link to keep names on sorted order.
5. You need to build the list as you go maintaining this 
ordering, so at any time a print method was called it would
print the related field in order.

(This means nodes are added to the list in sorted order, 
elements are not added to the list followed by a sort 
called on the list.)
-------------------------------------------------------------
************************************************************/
#include <stdio.h> 
#include <iostream> 
#include <string>
#include <sstream>
#include <iterator> 
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>


using namespace std;

class DoubleNode
{
public:
	float weight;
	string name;
	DoubleNode *last;	
    DoubleNode *next;	
	DoubleNode *lastname;	
    DoubleNode *nextname;		
	
	DoubleNode(string data, float data2, DoubleNode *lastPtr = 0, DoubleNode *nextPtr = 0, DoubleNode *lastPtrname = 0, DoubleNode *nextPtrname = 0)
	{
		weight = data2;
		name = data;
		last = lastPtr;
		next = nextPtr;
		lastname = lastPtrname;
		nextname = nextPtrname;
		
	}
};

class DoubleList
{
private:
DoubleNode *head, *tail;
DoubleNode *headname, *tailname;
public:
//Constructor
DoubleList()
	{
		head = tail = 0;
		headname = tailname = 0;
	}
//Deconstructor
~DoubleList()
	{
        for (DoubleNode *p; !isEmpty(); )
		{
			p = head->next;	
			delete head;	
			head = p;		
		}
	}

    bool isEmpty()
	{
		return head == 0;
	}

	bool isEmptyname()
	{
		return headname == 0;
	}

void Insert(string data, float data2)
	{
		DoubleNode *newNode = new DoubleNode(data, data2);		// create our new node
		DoubleNode *temp = head;						// start at the top and find where to stick it in
		DoubleNode *tempname = headname;
		if (head == 0)									// creating the head (and tail)
		{
			head = tail = newNode;						// the head and tail are the new element
			return;
		}

		while (temp->next != 0 && temp->weight <= data2)
			temp = temp->next;							// get into position


		if (head == tail)								// adding to a one element list
		{
			if (data2 < temp->weight)						// stick before head
			{
				newNode->next = head;
				head->last = newNode;					// also tail->last
				head = newNode;
			}
			else										// stick after head
			{
				head->next = newNode;
				newNode->last = head;
				tail = newNode;
			}
		}
		else if (temp == head)							// adding to the head of a list of more than one element
		{
			//
			// At this point, the data in the head is greater than the data in the new node
			// otherwise the while loop would have taken us out of the head, so we want to
			// stick the new node up front
			newNode->next = head;
			head->last = newNode;
			head = newNode;
		}
		else if (temp == tail)
		{
			//
			// Check to see if we want to put the newNode before or after the tail
			if (data2 > tail->weight)
			{
				tail->next = newNode;
				newNode->last = tail;
				tail = newNode;
			}
			else
			{
				newNode->next = tail;
				newNode->last = tail->last;
				tail->last->next = newNode;
				tail->last = newNode;
			}
		}
		else											// adding to the middle
		{
			//
			// Currently, the temp node is to the right of where the newNode is going
			// to fit in, 
			newNode->next = temp;
			newNode->last = temp->last;
			temp->last->next = newNode;
			temp->last = newNode;
		}
//---------------------------------------------------------------------------------------------
	char arr[data.length() + 1]; 
	char arr2[tempname->name.length() + 1]; 
 string copydata = data;
 string copynext = tempname->name;
    strcpy(arr, copydata.c_str()); 
	for (int y = 0; y < sizeof(arr); y++) { 
        arr[y] = copydata[y]; 
        
    } 
	strcpy(arr2, copynext.c_str()); 
	for (int x = 0; x < sizeof(arr2); x++) { 
        arr[x] = copynext[x];
    } 
while (tempname->nextname != 0 && arr2[0] <= arr[0])
			tempname = tempname->nextname;							// get into position


		if (headname == tailname)								// adding to a one element list
		{
			if (arr[0] < arr2[0])						// stick before head
			{
				newNode->nextname = headname;
				headname->lastname = newNode;					// also tail->last
				headname = newNode;
			}
			else										// stick after head
			{
				headname->nextname = newNode;
				newNode->lastname = headname;
				tailname = newNode;
			}
		}
		else if (tempname == headname)							// adding to the head of a list of more than one element
		{
			//
			// At this point, the data in the head is greater than the data in the new node
			// otherwise the while loop would have taken us out of the head, so we want to
			// stick the new node up front
			newNode->nextname = headname;
			headname->lastname = newNode;
			headname = newNode;
		}
		else if (tempname == tailname)
		{
			//
			// Check to see if we want to put the newNode before or after the tail
			if (arr[0] > arr2[0])
			{
				tailname->nextname = newNode;
				newNode->lastname = tailname;
				tailname = newNode;
			}
			else
			{
				newNode->nextname = tailname;
				newNode->lastname = tailname->lastname;
				tailname->lastname->nextname = newNode;
				tailname->lastname = newNode;
			}
		}
		else											// adding to the middle
		{
			//
			// Currently, the temp node is to the right of where the newNode is going
			// to fit in, 
			newNode->nextname = tempname;
			newNode->lastname = tempname->lastname;
			tempname->lastname->nextname = newNode;
			temp->lastname = newNode;
		}
//--------------------------------------------------------------------------------------------------------------
		
} // end insert

	
void printSortedWeights()
	{
		cout<< "Names & weights sorted(ascending) by weight. : ";
		for (DoubleNode *temp = head; temp != 0; temp = temp->next){
		    cout << temp->name <<  " - ";
			cout << temp->weight <<  ", ";
			}
			
		cout << endl;
	}
//temp->name.at(i)
	void printSortedNames() 
	{
		cout<< "Names & weights sorted(ascending) by name. : ";
		for (DoubleNode *tempname = tail; tempname != 0; tempname = tempname->last){
			cout << tempname->name <<  " - ";
			cout << tempname->weight <<  ", ";}
		cout << endl;
	}



};

int main()
{
	DoubleList *List = new DoubleList();
	string sentence;
    string word;
	float weight;
	
    //---------------------
	cout << endl;
    cout << "---------------------Start Name and Weight Sorter---------------------" << endl;
    cout<< "                       -----ENTER 15 VALUES-----" << endl; 

	cout << "         [Enter NAME followed by WEIGHT to create sorted list]" << endl;
    
    for (int i = 0; i < 4; i++){
    
        cin >> word >> weight;
		List->Insert(word, weight);
	}
	List->printSortedNames();
	List->printSortedWeights();
	//Clean Up Data with Deconstructor and Delete
	List->~DoubleList();
return 0;
}
/*Input:
Mark
150
Tina
115
Zach
55
Amy
140
Steve
220
Brian
250
Liz
125
Brian
220
Laura
115
Alex
175
Jason
210
Eric
175
Aaron
195
Kim
135
Brandon
78

Output:

Names & weights sorted(ascending) by name. : Brian - 250, Brian - 220, Steve - 220, Jason - 210, Aaron - 195, Eric - 175, Alex - 175, Mark - 150, Amy - 140, Kim - 135, Liz - 125, Laura - 115, Tina - 115, Brandon - 78, Zach - 55, 
Names & weights sorted(ascending) by weight. : Zach - 55, Brandon - 78, Tina - 115, Laura - 115, Liz - 125, Kim - 135, Amy - 140, Mark - 150, Alex - 175, Eric - 175, Aaron - 195, Jason - 210, Steve - 220, Brian - 220, Brian - 250, 
*/