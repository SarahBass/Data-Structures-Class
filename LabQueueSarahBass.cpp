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
#include <stdio.h> 
#include <iostream> 
#include <string>
#include <sstream>
#include <iterator> 
#include <cstring>
#include <stdlib.h>
using namespace std;

class IntSLLNode 
{
public:

    int info;				// Our data
    class IntSLLNode *next;	// Our Link
	

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
static int count;
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

		IntSLLNode *temp = new IntSLLNode(data);

		if (back == 0)
		{
			front = back = temp;
            
		}
		else
		{
			back->next = temp;

			back = temp;
		}
        count++;
	}

	int dequeue()
	{
	
		if (isEmpty()){
            cout << "ERROR : Empty Queue" << endl;
			return 0;
        }else{
		IntSLLNode *temp;
	
		int intReturn = front->info;
		
		temp = front;
		
		front = front->next;
		
		delete temp;

         count--;
        if (count < 0 ){
        count = 0;    
        }
		return intReturn;}
	}

	void print()
	{
		cout << "The queue, from front to back: ";
		for (IntSLLNode *temp = front; temp != 0; temp = temp->next)
			cout << temp->info << " ";
		cout << endl;
	}

    int Count(){
	return count;}

}; 

int linkedQueue::count = 0;

int main (void)
{
    linkedQueue linkedImplemenation;
    cout << "-----------------start------------------------" << endl;
	cout << "The count of the queue is : " << linkedImplemenation.Count() <<endl;
    cout << "----------------------------------------------" << endl;
	

	cout << "\nEnqueue 10\n";
	linkedImplemenation.enqueue(10);
	linkedImplemenation.print();

	cout << "\nEnqueue 20\n";
	linkedImplemenation.enqueue(20);
	linkedImplemenation.print();

	cout << "\nEnqueue 15\n";
	linkedImplemenation.enqueue(30);
	linkedImplemenation.print();

    cout << "----------------------------------------------" << endl;
    cout << "The count of the queue is : " << linkedImplemenation.Count() <<endl;
    cout << "----------------------------------------------" << endl;

	cout << "Dequeing " << linkedImplemenation.dequeue() << endl;
  	linkedImplemenation.print();
    cout <<endl;
	cout << "Dequeing " << linkedImplemenation.dequeue() << endl;
   	linkedImplemenation.print();
    cout <<endl;
	cout << "Dequeing " << linkedImplemenation.dequeue() << endl;
   	linkedImplemenation.print();
    cout<<endl;
    cout << endl;
	cout << "Dequeing " << linkedImplemenation.dequeue() << endl;
	cout << "Dequeing " << linkedImplemenation.dequeue() << endl;
	

    cout << "----------------------------------------------" << endl;
    cout << "The count of the queue is : " << linkedImplemenation.Count() <<endl;
    cout << "----------------------------------------------" << endl;
	
	return 0;
}
