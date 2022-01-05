#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Our Doubly Linked List Node object, that holds an integer as its Data

+-----------+---------------+-----------+
|			|				|			|
|	LINK	|  DATA			|	LINK	|
|			|				|			|
+-----------+---------------+-----------+

*/
class IntDLLNode
{
public:

	int info;				// Our data
	IntDLLNode *last;		// Our Back Link
	IntDLLNode *next;		// Our Forward Link

							//
							// Constructor
							//
							// Takes an integer to be stored in info
							// and a pointer if provided, it is an optional
							// parameter that defaults to zero
							//
	IntDLLNode(int data, IntDLLNode *lastPtr = 0, IntDLLNode *nextPtr = 0)
	{
		info = data;
		last = lastPtr;
		next = nextPtr;
	}
};

/*

Our Un-Ordered Doubly Linked List Class

This object handles the adding of nodes to either the front or back
of the list. The deleting from the front, back, or middle of the list.
It can also print out the list and check to see if an element is in
the list

*/
class IntDLList
{
private:
	//
	// Our two special nodes that we will use to quickly acess
	// the front and back of the list (the two fronts really)
	//
	IntDLLNode *head, *tail;
public:

	//
	// Default Constructor
	//
	// Initializes its two memebers, head and tail to point to nothing
	//
	IntDLList()
	{
		head = tail = 0;
	}

	//
	// Our Deconstructor
	//
	// This will make sure the list elements are freed when we no
	// longer need the list
	//
	~IntDLList()
	{
		//
		// Create a node pointer
		// While the list isn't empty
		// start deleting nodess starting at the head
		for (IntDLLNode *p; !isEmpty(); )
		{
			p = head->next;	// set our temporary pointer to the next element
			delete head;	// delete the memory allocated to the head (note this doesn't kill our pointer)
			head = p;		// set the head to the new head (or nothing if this is the last node)
		}
	}

	//
	// Checks to see if the head is pointing nowhere (0)
	// if it does, then it is empty, otherwise the list is not empty
	//
	bool isEmpty()
	{
		return head == 0;
	}

	void addToHead(int data)
	{
		//
		// Add the new node to the front of the list at the head
		//
		// The node constructor handles the linking of the two
		// nodes together
		IntDLLNode *temp = new IntDLLNode(data, 0, head);
		if (head != 0)
			head->last = temp;
		head = temp;

		//
		// Make tail also the head if it isn't already something else
		// 
		if (tail == 0)
			tail = head;
	}

	void addToTail(int data)
	{
		if (tail != 0) // if list not empty;
		{
			//
			// Create the node and Link the last link to the tail
			//
			IntDLLNode *temp = new IntDLLNode(data, tail);
			//
			// Link the current tail to a new node
			//
			tail->next = temp;
			//
			// Make the tail the new node
			//
			tail = tail->next;
		}
		else
			head = tail = new IntDLLNode(data);
	}

	// delete the head and return its info;
	int  deleteFromHead()
	{
		int data = head->info;	// save the data to local variable
		IntDLLNode *tmp = head;	// create a pointer to head

		if (head == tail)		// if only one node on the list;
			head = tail = 0;	// set the head and tail pointers to nothing
		else
		{
			head = head->next;	// set the new head
			head->last = 0;		// fix the head pointer
		}

		delete tmp;				// free up the memory that was used by the old head
		return data;			// return the former heads data
	}

	// delete the tail and return its info;
	int  deleteFromTail()
	{
		int data = tail->info;	// get data from the tail node into local variable
		if (head == tail)		// if only one node on the list;
		{
			delete head;		// free up memory
			head = tail = 0;	// head and tail pointers point nowhere
		}
		else					// if more than one node in the list,
		{
			IntDLLNode *temp = tail;
			tail = tail->last;	// back the tail up
			tail->next = 0;		// set tail pointer to nothing
			delete temp;		// free up the memory at tail
		}
		return data;
	}

	void deleteNode(int data)
	{
		//
		// check to see that the list isn't empty list
		//
		if (head != 0)
		{
			//
			// if only one element in the list, head will equal tail
			// then we also check to see if this one node has the
			// data we are looking for
			//
			if (head == tail && data == head->info)
			{
				//
				// Free up the memory at the head, aka tail,
				// and set the head and tail to point nowhere
				delete head;
				head = tail = 0;
			}
			else if (data == head->info)
			{
				//
				// if more than one node on the list
				// check to see if the data is at the head
				// and delete the head if it is
				IntDLLNode *temp = head;
				head = head->next;		// make the new head at the next node
				head->last = 0;
				delete temp;             // and delete the old head
			}
			else
			{
				//
				// if more than one node in the list and data is not in the head
				//
				IntDLLNode *temp;

				//
				// An empty for loop that will get us to the node
				// we are looking for, and keeps track of the previous
				// node so that we can do some re-linking
				//
				// Step 1 (Keep track of the node we will be deleting)
				for (temp = head->next;						// start at the second node
					temp != 0 && !(temp->info == data);		// check the node for data
					temp = temp->next);						// move node one down the list


				if (temp != 0)					// make sure that we are pointing somewhere
				{
					//
					// At this point we have found the node to delete
					// So we need to update the links around it
					// 
					// Re linking the previous node to the next node / or null
					temp->last->next = temp->next;
					//
					// Re linking the next node to the last node
					if (temp->next != 0)
						temp->next->last = temp->last; /// BUGGG

					if (temp == tail)			// watch for the tail
						tail = temp->last;

					delete temp;					// delete the node (Step 3)
				}
			}
		}
	}

	bool isInList(int data) const
	{
		//
		// Ascertain if the data is in our list at this point in time
		//
		IntDLLNode *tmp;
		//
		// Our empty for loop again, starting at the head
		// traversing the list until it reaches the end
		// or finds the data we are looking for
		//
		for (tmp = head; tmp != 0 && !(tmp->info == data); tmp = tmp->next);
		//
		// A logical test to see if we found the element, or
		// went off the list
		//
		return tmp != 0;
	}

	void printAll() const
	{
		//
		// Print the list
		for (IntDLLNode *tmp = head; tmp != 0; tmp = tmp->next)
			cout << tmp->info << " ";
		cout << endl;
	}
}; // end Doubly Linked List - IntDLList

   /*////////////////////////////////////////////////////////////////////////////////////////////////////////

   Sorted Doubly Linked List
   ---------------------------------------------------------------------------------------------------------
   Methods:
   ---------------------------------------------------------------------------------------------------------
   Insert:			adds an element to the list in its sorted position
   printAll:		prints the list in the forward direction
   printBackwards:	prints the list in the reverse direction
   Delete:			not implemented
   ---------------------------------------------------------------------------------------------------------
   Members:
   ---------------------------------------------------------------------------------------------------------
   *head:			pointer to the front end of the list
   *tail:			pointer to the back end of the list
   *********************************************************************************************************/
class IntSortedDLList
{
private:
	IntDLLNode *head, *tail;
public:
	IntSortedDLList()
	{
		head = tail = 0;
	}

	void Insert(int data)
	{
		IntDLLNode *newNode = new IntDLLNode(data);		// create our new node
		IntDLLNode *temp = head;						// start at the top and find where to stick it in

		if (head == 0)									// creating the head (and tail)
		{
			head = tail = newNode;						// the head and tail are the new element
			return;
		}

		while (temp->next != 0 && temp->info <= data)
			temp = temp->next;							// get into position


		if (head == tail)								// adding to a one element list
		{
			if (data < temp->info)						// stick before head
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
			if (data > tail->info)
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
	} // end insert

	void printAll() const
	{
		//
		// Print the list
		cout << "DLL: ";
		for (IntDLLNode *temp = head; temp != 0; temp = temp->next)
			cout << temp->info << " ";
		cout << endl;
	}

	void printBackwards() const
	{
		//
		// Print the list
		cout << "From the tail DLL: ";
		for (IntDLLNode *temp = tail; temp != 0; temp = temp->last)
			cout << temp->info << " ";
		cout << endl;
	}
}; // end Sorted Doubly Linked List - IntSortedDLList
int main(void)
{
	IntDLList *theList = new IntDLList();
	//cout << theList->deleteFromHead();

	cout << "Adding 10" << endl;
	theList->addToHead(10);
	cout << "Adding 25" << endl;
	theList->addToHead(25);
	cout << "Adding 15" << endl;
	theList->addToHead(15);
	cout << "Adding 20" << endl;
	theList->addToHead(20);
	cout << "Adding 100" << endl;
	theList->addToHead(100);

	theList->deleteNode(10);

	cout << "The list: ";
	theList->printAll();

	cout << "Adding 99" << endl;
	theList->addToTail(99);
	cout << "Adding 54" << endl;
	theList->addToTail(54);
	cout << "Adding 33" << endl;
	theList->addToTail(33);

	cout << "The list: ";
	theList->printAll();

	if (theList->isInList(33))
		cout << "Found 33" << endl;

	cout << "Deleting from head: " << theList->deleteFromHead() << endl;
	cout << "Deleting from the tail: " << theList->deleteFromTail() << endl;

	cout << "Deleting 100" << endl;
	theList->deleteNode(100);
	cout << "Deleting 100 again" << endl;
	theList->deleteNode(100);

	cout << "Is the list empty?? " << theList->isEmpty() << endl;
	cout << "Is 100 in the list?? " << theList->isInList(100) << endl;

	cout << "The list: ";
	theList->printAll();

	IntSortedDLList sortedDLL;
	srand((unsigned)time(0));
	for (int i = 0; i < 10; i++)
	{
		int data = rand() % 100;
		cout << "Adding " << data << endl;
		sortedDLL.Insert(data);
		sortedDLL.printAll();
		sortedDLL.printBackwards();
	}

	return 0;
}

