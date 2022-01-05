#include <iostream>

using namespace std;

class arrayStack
{
private:
	int topOfStack;	// used to indicate the entrance of the stack
	const static int MAX_STACK_SIZE = 100;	// a predetermined stack size
	int stack[MAX_STACK_SIZE];	// the stack

public:

	arrayStack()
	{
		//
		// Indicate that the stack starts at element 0
		topOfStack = 0;
	}

	bool isEmpty()
	{
		//
		// Checking to see if the stack is empty, note that
		// the stack pointer is pointing one above the last
		// position of data, so if it is pointing at the first
		// spot, then it is empty
		return topOfStack == 0;
	}

	bool push(int data)
	{
		//
		// Array bounds checking
		if (topOfStack + 1 >= MAX_STACK_SIZE)
			return false;

		//
		// push the data onto the top of the stack and
		// increment the pointer to point to the next spot
		stack[topOfStack++] = data;
		return true;
	}

	int pop()
	{
		//
		// Check that the stack has something to pop off
		if (isEmpty())
			return -999;

		//
		// Note that the stack pointer is pointing above
		// the last element in the stack, so we decrement
		// the pointer before we grab off the data.
		// Also note that the data still exists in the
		// array, but the stack is private, so there is
		// no outside access to these old values
		return stack[--topOfStack];
	}

	void print()
	{
		cout << "Top: ";
		for (int i = topOfStack - 1; i >= 0; i--)
			cout << stack[i] << " ";
		cout << endl;
	}

}; // end arrayStack

int main (void)
{
	//
	//			Stacks
	//
	// A stack is a linear data structure that can be accessed
	// only at one end. A stack is a LIFO structure, where the
	// the Last In First Out logic applies. So if we put in
	// item A, then B, then C, when we take an item out, it will be C
	//
	//
	// The basic stack operations are known as push and pop
	// Push: place an item onto the top of the stack
	// Pop: take an item from the top of the stack
	//
	//
	/*
			Example Stack (There is only one actual stack
			I am just showing the progression.


		|    |	|    |	|    |	|    |	|    |	|    |	|    |	
		|    |	|    |	|    |	|    |	|    |	|    |	|    |	
		|    |	|    |	|    |	|    |	|    |	|    |	|    |	
		|    |	|    |	|    |	|    |	|    |	|    |	|    |	
		|    |	|    |	|    |	|    |	|    |	|    |	|    |	
		|    |	| 25 |	|    |	| 20 |	|    |	|    |	|    |	
		| 10 |	| 10 |	| 10 |	| 10 |	| 10 |	|    |	| 35 |	
		+----+  +----+  +----+  +----+  +----+  +----+  +----+  
		  1		   2	  3		   4	   5	   6	  7	
							States:

		theStack.push(10);	// State 1  1 item on stack
		theStack.push(25);	// State 2	2 items on stack
		theStack.pop();		// State 3  1 item on stack
		theStack.push(20);	// State 4	2 items on stack
		theStack.pop();		// State 5  1 item on stack
		theStack.pop();		// State 6  0 items on stack
		theStack.push(35);	// State 7  1 item on stack

	*/

	/***********************************************************************
	*		Working with arrayStack
	***********************************************************************/

	arrayStack arrayImplementation;

	cout << "Working with the array implementation of the stack.\n";

	cout << "Is the stack empty? " << arrayImplementation.isEmpty() << endl;
	cout << "Pushing 10 onto the stack:\n";
	arrayImplementation.push(10);
	arrayImplementation.print();

	cout << "Pushing 25 onto the stack:\n";
	arrayImplementation.push(25);
	arrayImplementation.print();

	cout << "Popping from the stack: " << arrayImplementation.pop() << endl;
	arrayImplementation.print();

	cout << "Pushing 20 onto the stack:\n";
	arrayImplementation.push(20);
	arrayImplementation.print();

	cout << "Popping from the stack: " << arrayImplementation.pop() << endl;
	arrayImplementation.print();
	
	cout << "Popping from the stack: " << arrayImplementation.pop() << endl;
	arrayImplementation.print();

	cout << "Is the stack empty: " << arrayImplementation.isEmpty() << endl;
	
	cout << "Pushing 35 onto the stack:\n";
	arrayImplementation.push(35);
	arrayImplementation.print();

	cout << "Pushing lots of numbers onto the stack: ";
	for (int i = 0; ; i++)
		if (!arrayImplementation.push(i))
		{
			cout << "\nOh no, the stack is full.\n";  // ergo the problem with arrays
			break;									// of course there are ways around this
		}
		else
			cout << ".";

	cout << "\nPress 0<ENTER> to continue.";
	cin.get();
	return 0;
}