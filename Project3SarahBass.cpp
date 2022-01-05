/************************************************************
 ------------------------------------------------------------
Sarah Bass
Program 3
CS 41 Data Structures
Due: 10/23/2021
-------------------------------------------------------------
1.Build the tree from the unique set of names (add function)
2.Execute a preorder traversal
3.Execute an inorder traversal
4.Execute a postorder traversal
5.Find and print the height of the tree using recursion
6.Determine the number of leaves and print the result 
7.Search for a name and indicate the weight
8.Determine the lowest weight contained in the tree.
9.Find the first name in alphabetical order 
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
#include <cctype>
using namespace std;

class treeNode
{
public:
	float weight; 
    string name;
	treeNode *left, *right;

	treeNode()
	{
		left = right = 0;
	}

	treeNode(float weight, string name, treeNode *l = 0, treeNode *r = 0)
	{
		this->name = name;
		this->weight = weight;
		left = l;
		right = r;
	}
};

class BTS
{
    public:	
	treeNode *root;

	BTS()
	{
		root = 0;
	}
	

	void preorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			cout << temp->name << " , ";			// evaluate (print) current node
			inorderTraversal(temp->left);			// traverse left subtree
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	void inorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			cout << temp->name << " , ";				// evaluate (print) current node
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	void postorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			postorderTraversal(temp->left);			// traverse left subtree
			postorderTraversal(temp->right);			// traverse right subtree
			cout << temp->name << " , ";				// evaluate (print) current node
		}
	}



    bool add(float weight, string name)
	{
		int count = 0;
		treeNode *newNode = new treeNode(weight, name);
		if (root == 0)									
		{
			root = newNode;
			return true;
		}
		treeNode *temp = root;							
		while(true)
		{
			if (name == temp->name){
				return false;
			}
			else if (Alphabetical(name, count) == Alphabetical(temp->name, count)){
				count++;
			}
			else if (Alphabetical(name, count) < Alphabetical(temp->name, count))						
				if (temp->left == 0)					
				{
					temp->left = newNode;
					break;
					count = 0;
				}
				else{								
					temp = temp->left;
					count = 0;}
			else if (Alphabetical(name, count) > Alphabetical((temp->name), count))					
				if (temp->right == 0)					
				{
					temp->right = newNode;
					count = 0;
					break;
				}
				else{									
					temp = temp->right;
					count = 0;}
			else if (name == temp->name)				
				return false; 
		}
		return true;
	}   

	char Alphabetical (string name, int count){
		char firstletter;
		firstletter = name.at(count);
		return tolower(firstletter);
		
	}

	int maxDepth(treeNode *temp)
{
    if (temp == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(temp->left);
        int rDepth = maxDepth(temp->right);
     
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

string firstName(treeNode *temp)
{
treeNode* current = temp;
/* loop down to find the leftmost leaf */
while (current->left != NULL)
{
    current = current->left;
}
return(current->name);
}

void findMinWeight(treeNode *temp)
{
	string lightestName = temp-> name;
	float lightest = temp -> weight;
	temp = temp->left;
   if (temp->right != NULL){
            if (lightest > temp->weight){ 
				lightestName = temp->name;
				lightest = temp ->weight;
				temp = temp->right;}}
	if (temp->left  != NULL){
		
            if (lightest > temp->weight){ 
			lightestName = temp->name;
			lightest = temp ->weight;
			temp = temp-> left;}}
	
   cout << lightestName << " @ " << lightest;
   
}

void findName(treeNode *temp, string findname)
{
	int count = 0;
	while(temp != NULL) {
     
      if(temp->name == findname) {
        cout << "Person Found : " << temp-> name << " @ weight : " << temp-> weight;
         return;
	   } else if(Alphabetical(temp->name, count) == Alphabetical(findname, count)){
		   count++;
      } else if(Alphabetical(temp->name, count) > Alphabetical(findname, count)){
         temp = temp->left;
		 count = 0;}
         else
            temp = temp->right;
			count = 0;
   }
   cout << "Person Not Found in Tree ";
}

int getLeafCount(treeNode *temp)
{
    if(temp == NULL)    
        return 0;
    if(temp->left == NULL && temp->right == NULL)
        return 1;        
    else
        return getLeafCount(temp->left)+
            getLeafCount(temp->right);
}


	};


int main ()
{
    string names;
	float weights;
	string findname = "Eric";
	
    BTS tree;
	
	cout << endl;
    cout << "---------------------Start Name and Weight TREE---------------------" << endl;
    cout<< "                       -----ENTER 15 VALUES-----" << endl; 

	cout << "         [Enter NAME followed by WEIGHT to create trees]" << endl;
    
    for (int i = 0; i < 15; i++){
    
        cin >> names >> weights;
        
		tree.add(weights, names);
	}
    cout << endl;
    cout << "Characteristics - ";
	cout<< "Height: ";
	cout<< (tree.maxDepth(tree.root) -1);
	cout<< ", Leaves: ";
	cout<< tree.getLeafCount(tree.root);
	cout<< " , Lightest: ";
	tree.findMinWeight(tree.root);
	cout << " , First Name : ";
	cout << tree.firstName(tree.root);
    cout<< endl;
    cout << "PreOrder: ";
    tree.preorderTraversal(tree.root);
    cout<< endl;
    cout << "InOrder: ";
    tree.inorderTraversal(tree.root);
    cout<< endl;
    cout << "PostOrder: " ;
    tree.postorderTraversal(tree.root);
    cout << endl;
	cout << "Search tree for " << findname << " : " ;
	tree.findName(tree.root, findname);
	cout<<endl;
    return 0;
}
/*
Input:
Mike
220
Brianna
120
Karl
109
Chuck
145
Stephanie
130
Roger
199
Zelda
145

mark
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
alex
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

*/

//---------------------OUTPUT---------------------
/* 
Characteristics - Height: 3, Leaves: 3 , Lightest: Karl @ 109 , First Name : Brianna
PreOrder: Mike , Brianna , Chuck , Karl , Roger , Stephanie , Zelda , 
InOrder: Brianna , Chuck , Karl , Mike , Roger , Stephanie , Zelda , 
PostOrder: Chuck , Karl , Brianna , Roger , Zelda , Stephanie , Mike , 
Search tree for Eric : Person Not Found in Tree 

Characteristics - Height: 6, Leaves: 6 , Lightest: Amy @ 140 , First Name : Aaron
PreOrder: Mark , Aaron , Alex , Amy , Brandon , Brian , Eric , Jason , Kim , Laura , Liz , Steve , Tina , Zach , 
InOrder: Aaron , Alex , Amy , Brandon , Brian , Eric , Jason , Kim , Laura , Liz , Mark , Steve , Tina , Zach , 
PostOrder: Aaron , Alex , Brandon , Eric , Kim , Jason , Laura , Liz , Brian , Amy , Steve , Zach , Tina , Mark , 
Search tree for Eric : Person Found : Eric @ weight : 175
*/