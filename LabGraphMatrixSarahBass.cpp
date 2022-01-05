/************************************************************
 ------------------------------------------------------------
Sarah Bass
Graph Matrix Assignment
CS 41 Data Structures
Description: Graph Matrix
-------------------------------------------------------------
Ask the user how many points there are.
Ask the user to label those points, ie "A", "B", "C"...
Define the matrix as a square matrix 
Repeatedly ask the user to define edges 
Have a list method that will list out edges.
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
// stores adjacency list items
class adjNode {
    public:
    string val;
    
    adjNode* next;
};
// structure to store edges
class graphEdge {
    public:
    string start_ver, end_ver;
    
};
class DiaGraph{
     int N;  // number of nodes in the graph
    public:
    // insert new nodes into adjacency list from given graph
    adjNode* getAdjListNode(string value, adjNode* head)   {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        
         
        newNode->next = head;   // point new node to current head
        return newNode;
    }
   
    adjNode **head; // list as array of pointers
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N)  {
        // allocate new node
        head = new adjNode*[N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i][j] = nullptr;
        // construct directed graph by adding edges to it
        for (unsigned i = 0; i < n; i++)  {
            string start_ver = edges[i].start_ver;
            string end_ver = edges[i].end_ver;
            
            // insert in the beginning
            adjNode* newNode = getAdjListNode(head[start_ver], head[end_ver]);
             
            // point head pointer to new node
            head[start_ver], head[end_ver] = newNode;
             }
    }
      // Destructor
     ~DiaGraph() {
    for (int i = 0; i < N; i++)
        delete[] head[i];
        delete[] head;
     }
};
// print all adjacent vertices of given vertex
void display(adjNode* ptr, int i)
{
    while (ptr != nullptr) {
        cout << "Added Edge" << i << " - > " << ptr->val;
        ptr = ptr->next;
    }
}
// graph implementation
int main()
{
    DiaGraph graphMatrix;
    string label1 = "empty";
    string label2 = "empty";
  
    int N = 1; // number of vertices
    
    cout << "How many vertices?" << endl;
    cin >> N;
    int n = 0;
    for (int i =0; i<N; i++){
    cout << "What is the label for vertex " << i << ": " <<endl;
    cin >> label1;
    graphEdge edges[i][j] = (label1,label2);
    }
    // graph edges array.
    cout << "Define an edge by listing a pair of vertices, i.e. 'A B', or -1 to stop." << endl;
    while (label1 != "-1" || label2 != "-1"){
    cin >> label1;
    cin >>label2;
    cout << label1 " -> " << label2 <<endl;
    graphEdge edges[i][j] = (label1,label2);
    }
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
   graphEdge edges(edges, n, N);
    // print adjacency list representation of graph
    cout<<"Graph adjacency list "<<endl<<"(start_vertex, end_vertex, weight):"<<endl;
    for (int i = 0; i < n; i++)
    {
        // display adjacent vertices of vertex i
        graphMatrix.display();
    }
    return 0;
    }
     
