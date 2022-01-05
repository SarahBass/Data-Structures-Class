#include <iostream>

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

class linkedStack
{
private:
	IntSLLNode *top;
	

public:
	static int count;

	
	linkedStack()
	{
		top = 0;
		
	}

	bool isEmpty()
	{
		return top == false;
	}

	void push(int data)
	{
		
		IntSLLNode *temp = new IntSLLNode(data);
		count++;
		if (isEmpty())
			top = temp;
		else
		{
			temp->next = top;
			top = temp;
		}
	}

	int pop()
	{
			if (isEmpty()){
			cout << "ERROR: EMPTY STACK" << endl;
			return -999;
			}else{
				
		int intReturn = top->info;
		
		
		IntSLLNode *temp;
		temp = top;

		top = top->next;
		
		delete temp;
		count--;
			
		return intReturn;}
	}

	void print()
	{for(IntSLLNode *temp = top; temp != 0;
	 temp=temp->next)cout << temp->info << " ";cout << endl;}

	int Count(){
	return count;}
	 
};
int linkedStack::count = 0;
	
int main (void)
{
linkedStack linkedImplementation;
cout << "--------------start---------------------" << endl;
cout << "The count is: " << linkedImplementation.Count() << endl;
cout << "----------------------------------------" << endl;

cout << "Pushing 10 onto the stack.\n";
linkedImplementation.push(10);	
cout << "Pushing 20 onto the stack.\n";
linkedImplementation.push(20);	
cout << "Pushing 30 onto the stack.\n";
linkedImplementation.push(30);
cout << "Pushing 40 onto the stack.\n";
linkedImplementation.push(40);


cout << "----------------------------------------" << endl;
cout << "Stack: " << endl;
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;
cout << "----------------------------------------" << endl;


cout << "Popping from the stack: " << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;

linkedImplementation.pop();
linkedImplementation.print();
cout << "The count is: " << linkedImplementation.Count() << endl;
cout << "--------------end-----------------------" << endl;
return 0;
}