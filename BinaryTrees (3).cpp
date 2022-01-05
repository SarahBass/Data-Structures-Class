#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
	Trees

	Trees operate under a simlar structure as linked lists, where
	the trees consist of nodes as before, as well as links, also as before
	the difference between our lists and trees are how we structure the
	nodes together.

	Trees consist of nodes as I have mentioned, while structurally
	the same, these nodes can be referred to differently. One node in the
	tree is considered the root, from this node all other nodes can be
	reached. We reach these other nodes through the children of the root.
	Children are the nodes that are pointed to by the node that we are in.
	If a child node (or root) has no children itself, it is considered a leaf.

	Tree properties:
	Each node in a tree must be reachable by a unique path (sequence of links).
	The number of links in a path is the length of that path.
	The level of a node is is the length of its path + 1.
		Therefore, the level of the root is 1
	The height of a tree is the maximum level of of any node in the tree.
		Therefore, the height of a single node tree is 1

	Binary Trees

	Binary trees look just like a real world tree, except when we depict
	a binary tree, it will be inverted, also, as its name suggests, binary
	trees will only branch with at most two nodes at a time, so each tree
	node can have as many as two children, like your typical family tree.

	As we have already seen, linked lists suffer when it comes time to search
	them as we have degraded to a linear search as a result of no random access.
	This is where we take the concept of a tree and apply it to our list
*/
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
	
/*
	Binary Search Tree

	A Binary search tree is just a binary tree, except that when we add
	nodes to the tree we apply some ordering. For all nodes, the value
	in that node determines its position relative to its parent. If the
	value of a node is less than that of its parent, it will exist in
	the parents left subtree, if the value of the node is greater than
	the parent, then it exists in the right subtree. We only allow unique
	values in our binary search tree, as such any duplicate nodes can
	be discarded or otherwise dealt with. If we must allow duplicate
	nodes then the implementation needs to decide which subtree to place
	the duplicates under, whichever we decide, we must be consistent, such
	that we don't lose track of the duplicates.
*/
class binarySearchTree
{
	/*
							Method Headers
							
			void rebuildBalance(int array[], int first, int last)
			bool addNode(int data)
			bool insert(int data)
			void inorderTraversal(treeNode *temp)
			void preorderTraversal(treeNode *temp)
			void postorderTraversal(treeNode *temp)
			void rightToLeftInorderTraversal(treeNode *temp)
			void deleteByCopying(treeNode*& node)
			void findAndDeleteByCopying(int data)
			void rebuildBalance(int array[], int first, int last)
	*/
public:	
	treeNode *root;

	binarySearchTree()
	{
		root = 0;
	}

	//
	// Adding nodes to the tree.
	// In order to maintain the searchability of the tree, when we add
	// nodes we need to maintain the binary search tree structure, this is
	// achieved by adding a node onto an available leaf node (or a node with
	// only one child), and adding it to the correct node, such that the
	// rules of the tree are maintained.
	// We do this by evaluating the tree, starting at the root, and we then
	// traverse the nodes subtrees, moving in the direction that our new
	// node should go.

	bool addNode(int data)
	{
		treeNode *newNode = new treeNode(data);			// our  new node
		if (root == 0)									// check for an empty root
		{
			root = newNode;
			return true;
		}
		treeNode *temp = root;							// create a temp node to traverse the list
		while(true)
		{
			if (data < temp->data)						// check to see if we will traverse to the left
				if (temp->left == 0)					// check to see if we have found newNode's position
				{
					temp->left = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->left;
			else if (data > temp->data)					// check to see if we will traverse to the right
				if (temp->right == 0)					// check to see if we have found newNode's position
				{
					temp->right = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->right;
			else if (data == temp->data)				// For this implementation, we will not allow duplicates
				return false; // no dupes
		}
		return true;
	}

	//
	// Alternatively
	bool insert(int data)
	{
		treeNode *temp = root, *prev = 0;
		while (temp != 0)
		{
			prev = temp;								// keep track of parent
			if (data < temp->data)						// traverse the left
				temp = temp->left;
			else										// traverse the right
				temp = temp->right;
		}

		//
		// At this point we have found an opening for our new node,
		// as temp is pointing nowhere, as such it has no usefull
		// information, which is why we kept track of its parent.

		if (root == 0)									// check for an empty tree
			root = new treeNode(data);
		else if (data < prev->data)						// see if our position is on the left
			prev->left = new treeNode(data);
		else if (data > prev->data)						// see if our position is on the right
			prev->right = new treeNode(data);
		else											// disallow duplicate data
			return false; // no dupes allowed
		return true;
	}

	bool recurseInsert(treeNode *temp, int data)
	{
		if (data < temp->data)
		{
			if (temp->left != 0)
				recurseInsert(temp->left, data);
			else
			{
				treeNode *newNode = new treeNode(data);
				temp->left = newNode;
				return true;
			}
		}
		else if (data > temp->data)
		{
			if (temp->right != 0)
				recurseInsert(temp->right, data);
			else
			{
				treeNode *newNode = new treeNode(data);
				temp->right = newNode;
				return true;
			}
		}
		else
			return false;
	}

	void recIns(treeNode *temp, int data)
	{
		if (temp == 0)
		{
			treeNode *newNode = new treeNode(data);
			temp = newNode;
		}
		else
		{
			if (data < temp->data)
				recIns(temp->left, data);
			else if (data > temp->data)
				recIns(temp->right, data);
		}
	}




	
	//
	// Tree traversals
	//
	// The following three traversals implement some depth first traversals
	// of our binary tree. We start things off by passing in the root of
	// the tree we are traversing. From there we start processing subtrees
	// using a left to right style of traversal.
	//
	// Inorder:
	// So named because if we do an inorder traversal on a binary search
	// tree, the nodes will be visited (printed) in numerically ascending
	// order. This traversal works by first visiting the left subtree of
	// a node, it will then continue to visit the left subtrees of the
	// subtrees, continuing on until no left child can be found. As soon
	// as no left child is found it will visit the data in the current node
	// then it will visit the right subtree. Note, that each time a node
	// is first passed in, it will check the left subtree. So once we go
	// to a right subtree, for that subtree we will then again try to go
	// to the left.


	void inorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			cout << temp->data << " ";				// evaluate (print) current node
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	//
	// Preorder:
	// This is the same as inorder, except we evaluate each node first, before
	// we traverse its subtrees.
	//
	void preorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			cout << temp->data << " ";				// evaluate (print) current node
			inorderTraversal(temp->left);			// traverse left subtree
			inorderTraversal(temp->right);			// traverse right subtree
		}
	}

	//
	// Postorder:
	// Same as the previous two except that we will traverse both subtrees of a node
	// before we will evaluate the node.
	//
	void postorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			inorderTraversal(temp->right);			// traverse right subtree
			cout << temp->data << " ";				// evaluate (print) current node
		}
	}
	
	//
	// This traversal uses the inorder semantics, except this time, instead of
	// traversing to the left first, we will traverse to the right first, so
	// everything is the same except we are doing it in reverse, so we end up
	// printing the data in reverse.
	//
	void rightToLeftInorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			rightToLeftInorderTraversal(temp->right);
			cout << temp->data << " ";
			rightToLeftInorderTraversal(temp->left);
		}
	}

	//
	// Deleting a node:
	//
	// There are three cases that need to be dealt with when deleting a node from our
	// tree.
	//
	// Case 1: Deleting a leaf. All we have to do here is tell the parent not to point
	// to the soon to be deleted node, and then delete the node, the tree is still
	// connected.
	//
	// Case 2: Deleting a node with one child. All we do here is bridge over the node
	// that is going to be deleted. The tree will remain connected and still retain
	// its binary search tree properties.
	//
	// Case 3: Deleting a node that has two children. This case requires a great deal
	// more work, and decisions on how to rebuild the tree. If we delete a node with
	// two children, we are creating three, or two trees (if deleting root) from the
	// original tree. This is a situation we want to avoid, because if all we did
	// was merge our three trees by adding two of the trees into one (the biggest
	// optimally) we will have a lot of work to do. Alternatively, we can delete by 
	// merging or delete by copying. Delete by merging can leave the tree worse off,
	// as such we will not discuss that in this program. This leaves us with delete
	// by copying.
	//
	// Delete by copying:
	//
	// What we do in this algorithm is find a node in the tree to take the place
	// of the node that we are deleting (via copying the data and deleting the 
	// replacement node). The way we find this node is by looking at one of the
	// subtrees of the node that is being deleted. If we look at the left subtree
	// we will want to take its rightmost node, if we look at the right subtree, we
	// will take its leftmost node, as either of these nodes can serve as a middle
	// value between the two subtrees. We will want to alternate between using the
	// left and right subtrees, so that our tree overall will maintain a better
	// shape.
	// Once we have our node, we will then copy its value into the node that was
	// slated for deletion. From above the copied node, through the rest of the
	// tree we have a connected tree, in proper form. Now we have to look down
	// from our copied node. There are two situations we can have here, either the
	// node was a leaf, in which case we simply delete it, or it has one subtree.
	// In which case we just bridge it. So you can see by implementing this algorithm
	// we can take advantage of the simplicity of the first two cases.
	// 

	// findAndDeleteByCopying() searches the tree to locate the node containing
	// data. If the node is located, the function DeleteByCopying() is called.

	void findAndDeleteByCopying(int data)
	{    
		treeNode *p = root, *prev = 0;
		//
		// Search for the data in the tree, keeping track of its parent as
		// we traverse through the list.
		//
		while (p != 0 && !(p->data == data)) 
		{
			prev = p;
			if (p->data < data)
				p = p->right;
			else p = p->left;
		}
		//
		// If we found it, remove the node.
		if (p != 0 && p->data == data)
			if (p == root)
				deleteByCopying(root);
			else if (prev->left == p)
				deleteByCopying(prev->left);	// pass the parent's link to the node being deleted
			else 
				deleteByCopying(prev->right);	// pass the parent's link to the node being deleted
		else if (root != 0)
			cout << "key " << data << " is not in the tree\n";
		else 
			cout << "the tree is empty\n";
	}
	
	
	void deleteByCopying(treeNode*& node) 
	{   
		//
		// Input: The link from the parent node to the node being deleted.
		//
		treeNode *previous, *tmp = node;
		//
		// node has no right child;
		// Set the parent's link (node) to the child of the node being
		// deleted, bridging over the soon to be deleted node.
		// Case 2:
		if (node->right == 0)                  
			node = node->left;   
		//
		// node has no left child;
		// Same as above, just to the right node.
		// Still Case 2:
		else if (node->left == 0)              
			node = node->right;
		//
		// The node has two subtrees, implement the copy algorithm
		//
		else // case 3:
		{
			//
			// First step into the left subtree
			tmp = node->left;
			//
			// Start keeping track of the parent
			previous = node;                  
			//
			// Move as far right in the subtree as we can, moving
			// the parent along with us (so we know where to bridge).
			while (tmp->right != 0) 
			{         
				previous = tmp;
				tmp = tmp->right;
			}
			//
			// Now that we have the rightmost node, we can copy its
			// data into the node that was slated for deletion
			node->data = tmp->data;             
			//
			// If the previous node is the same as the node that
			// was slated for deletion, then the rightmost element of
			// the subtree was the first node that we found in the subtree,
			// this means that we are currently being pointed to by the
			// previous->left pointer, otherwise, we are being pointed to
			// by the previous->right pointer.
			if (previous == node)
				previous->left  = tmp->left;		// bridge the gap
			else 
				previous->right = tmp->left;		// bridge the gap
		}
		delete tmp;                            

		//
		// Case 1:
		// This was covered by the first if statement. If there is no right
		// subtree, the parent's node pointer was set to the value at the
		// deleted nodes left subtree, which would also be empty, thereby
		// the value of zero.
	}

	//
	// Balanced tree:
	// A tree is balanced if the difference in the height of both subtrees of any node
	// in the tree is zero or one.
	//
	// Perfectly balanced tree: A balanced tree with all of its leaves on only one
	// or two levels (lowest).
	//
	// Building a balanced tree can require a fair bit of work. The simplest approach
	// is to completely rebuild the tree by extracting the data out of the tree and
	// then rebuilding the tree from the data. To do this we will need an array to
	// hold onto the data. We also want the data in the array to be ordered, otherwise
	// we cannot guarantee that it would be balanced. A simple way to achieve this
	// ordering is to go ahead and use a inorder traversal.
	// This can provide us with the array. Now that we have the array, we can
	// start at its middle and then divide the left and right sides recursively to
	// rebuild the tree. This will result in a balanced tree, because the ordering
	// of the arrival of the data was optimized for the tree building.
	//
	// The code:
	//
	// Preconditions:
	//		array is sorted
	//		the tree has been deleted
	//
	// Postconditions:
	//		A balanced tree with data nodes holding array.Size nodes
	//
	void rebuildBalance(int array[], int first, int last)
	{
		if (first <= last)
		{
			int middle = (first + last) / 2;
			insert(array[middle]);
			rebuildBalance(array, first, middle-1);
			rebuildBalance(array, middle+1, last);
		}
	}
};

int main (void)
{
	//
	// Demonstrating addNode method
	binarySearchTree bst;
	bst.recIns(bst.root, 10);
	bst.recIns(bst.root, 5);
	bst.recIns(bst.root, 15);
	bst.recIns(bst.root, 12);
	bst.recIns(bst.root, 17);
	bst.recIns(bst.root, 19);

	bst.addNode(50);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(75);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(25);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(100);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(62);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(37);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(12);
	bst.inorderTraversal(bst.root);
	cout << endl;
	bst.addNode(70);
	bst.inorderTraversal(bst.root);
	cout << endl;

	/*bst.findAndDeleteByCopying(62);
	bst.findAndDeleteByCopying(12);*/
	bst.findAndDeleteByCopying(75);

	//
	// Demonstrating insertion method
	binarySearchTree myTree;
	myTree.insert(50);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(75);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(25);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(100);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(62);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(37);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	myTree.insert(12);
	myTree.inorderTraversal(myTree.root);
	cout << endl;
	cout << endl;
	cout << endl;
	myTree.rightToLeftInorderTraversal(myTree.root);
	cout << endl;

	//
	// Same results either way
	//
	return 0;
}
/*
	Complete binary tree:
		When all the nodes in the tree, except for those on the last level,
		have two children.

	"For all the nonempty binary trees whose nonterminal nodes have exactly
	two nonempty children, the number of leaves m is greater than the number
	of nonterminal nodes k and m = k + 1" - a complete binary tree.

	For example:
					Root		Level 1
					/  \
				Leaf	Leaf	Level 2
		nonterminal nodes = 1 (the root)
		leafs = 2 = k + 1 = 1 + 1
	
							Root			Level 1
						   /	\
					   Node		 Node		Level 2
				      /    \    /    \
				  Leaf  Leaf  Leaf   Leaf	Level 3
		nonterminal nodes = 3 (the root + the 2 nodes)
		leafs = 4 = k + 1

		generically:
			nonterminal nodes = n^(level - 1) - 1
			leafs = n^(level - 1)
			total nodes = n^(level) - 1
			
*/