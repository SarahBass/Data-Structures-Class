/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
					
class Matrix
{
	private:
	int** array;
	string* labels;
	
	public:
	int Size;
	
	Matrix(int size)
	{
		array = new int*[size];
		for(int i = 0; i < size; i++)
			array[i] = new int[size];
		Size = size;
	}
	
	void SetLabels()
	{
		labels = new string[Size];
		for (int i = 0; i < Size; i++)
		{
			cout << "Label " << i << ": ";
			cin >> labels[i];
		}
		
		//Array.Sort(labels);
	}
	
	int GetIndex(string label)
	{
	    for(int i = 0; i < Size; i++)
	        if (label == labels[i])
	            return i;
	       
	   return -1;
	}
	
	void AddEdge(string from, string to)
	{
		int row = GetIndex(from);
		int col = GetIndex(to);
		array[row][col] = 1;
		// array[col,row] = 1;
	}
	
	void Dump()
	{
		for (int row = 0; row < Size; row++)
		{
			for (int col = 0; col < Size; col++)
			{
				cout << array[row][col] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{		
	cout << "How many vertices for the graph?";
	int size;
	cin >> size;
	string* labels = new string[size];
	Matrix* m = new Matrix(size);		
	cout << m->Size;
	m->Dump();
	
	m->SetLabels();
	do
	{
		cout << "Enter two points to add an edge between. ";
		string fromVertex;
		cin >> fromVertex;
		if (fromVertex == "-1")
			break;
		string toVertex;
		cin >> toVertex;
		m->AddEdge(fromVertex, toVertex);
		m->Dump();
	}while(true);
	
}