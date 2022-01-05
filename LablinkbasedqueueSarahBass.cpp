/************************************************************
 ------------------------------------------------------------
Sarah Bass
Link Based Queue
CS 41 Data Structures
-------------------------------------------------------------
Description: 
Members:
Node - a node that tracks the front of the queue.
Node - a node that tracks the end of the queue.
Count - indicates how many items are on the queue.

Methods:
En-queue
- Accepts a number and adds to the end of the queue.
De-queue
- Returns a number from the front of the queue.
- If the queueis empty, emit an error indicating the queueis empty.
IsEmpty
- Returns a boolean indicating if the queue is empty.

-------------------------------------------------------------
************************************************************/
#include <iostream>
using namespace std;

class IntSLLNode 
{
public:

    int info;				// Our data
    class IntSLLNode *next;	// Our Link
	
	//
	// Constructor
	//
	// Takes an integer to be stored in info
	// and a pointer if provided, it is an optional
	// parameter that defaults to zero
	//
    IntSLLNode(int data, IntSLLNode *ptr = 0) 
	{
        info = data; 
		next = ptr;
    }
};

class linkedQueue
{
private:
	IntSLLNode *front, *back;

public:
	linkedQueue()
	{
		front = back = 0;
	}

	bool isEmpty()
	{
		return front == 0;
	}

	void enqueue(int data)
	{
		//
		// Create our new node with its data
		IntSLLNode *temp = new IntSLLNode(data);
		//
		// Add the node to the back of the queue
		//
		// First check to see that there is a node first
		// if there isn't this is the first node
		// so set the back to it, otherwise, add it to the
		// back
		if (back == 0)
		{
			front = back = temp;
		}
		else
		{
			back->next = temp;
			//
			// Update the back to the new node
			back = temp;
		}
	}

	int dequeue()
	{
		//
		// check to see if the queue is empty
		if (isEmpty())
			return -999;

		//
		// create our empty node so that we can free up memory
		IntSLLNode *temp;
		//
		// get the data from the queue and hold onto it for a sec
		int intReturn = front->info;
		//
		// assign the temp to the front
		temp = front;
		//
		// reset the front to the next element in the queue 
		// (or null if there is no next element)
		front = front->next;
		//
		// return memory to the free store
		delete temp;

		return intReturn;
	}

	void print()
	{
		cout << "The queue, from front to back: ";
		for (IntSLLNode *temp = front; temp != 0; temp = temp->next)
			cout << temp->info << " ";
		cout << endl;
	}

}; // end linkedQueue