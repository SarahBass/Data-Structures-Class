/************************************************************
 ------------------------------------------------------------
Sarah Bass
LAB : Binary Search Tree
CS 41 Data Structures
-------------------------------------------------------------
Create a node class/struct

-Data field
-2 self referential pointers
Create a BST class/struct
-Node field
Methods:
Add (data)
-Adds the data to the tree in sorted order.
Print()
-Prints all the nodes using inorder traversal

-------------------------------------------------------------
************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class treeNode
{
public:
	int data;
	treeNode *left, *right;

	treeNode()
	{
		left = right = 0;
	}

	treeNode(int data, treeNode *l = 0, treeNode *r = 0)
	{
		this->data = data;
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

    bool add(int data)
	{
		treeNode *newNode = new treeNode(data);
		if (root == 0)									
		{
			root = newNode;
			return true;
		}
		treeNode *temp = root;							
		while(true)
		{
			if (data < temp->data)						
				if (temp->left == 0)					
				{
					temp->left = newNode;
					break;
				}
				else									
					temp = temp->left;
			else if (data > temp->data)					
				if (temp->right == 0)					
				{
					temp->right = newNode;
					break;
				}
				else									
					temp = temp->right;
			else if (data == temp->data)				
				return false; 
		}
		return true;
	}

    void print(treeNode *temp) //in order traversal 
	{
		if (temp != 0)
		{
			print(temp->left);			
			cout << temp->data << " ";				
			print(temp->right);			
		}
	}
    };

int main ()
{
    BTS tree;
    cout << "Numbers entered:[7, 6, 3, 2, 1, 5, 4]" << endl;
    cout << "Binary Tree : " << endl; 
    tree.add(7);
    tree.add(6);
    tree.add(3);
    tree.add(2);
    tree.add(1);
    tree.add(5);
    tree.add(4);
    tree.print(tree.root);
    cout << endl;

    return 0;
}