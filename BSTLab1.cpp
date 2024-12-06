#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		// 	- a pointer to each child possible child node ("right" and "left")
		int data;
    	Node * left;
    	Node * right;

		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null
		Node(int val): data(val), left(nullptr), right(nullptr) {}
};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	// root
	Node *root = nullptr;
	root = new Node(13);
	// level 1 (children of root)
	root->left = new Node(0);
	root->right = new Node(21);
	// level 2 (children of 0)
	root->left->right = new Node(7);
	root->left->left = new Node(-2);
	// level 2 (children of 21)
	root->right->left = new Node(15);
	root->right->right = new Node(99);
	// level 3 (children of -2)
	root->left->left->right = new Node(-1);
	// level 3 (children of 7)
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(12);
	// level 3 (children of 15)
	root->right->left->right = new Node(18);
	// level 3 (children of 99)
	
	// level 4 (children of 18)
	root->right->left->right->right = new Node(19);
	return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	// Base cases
	if (root == nullptr) return false;
	// Base case: target is found 
	if (root->data == target) return true; 
	// General case: recursively search the left or right subtree 
	if (target < root->data) 
	{
		return searchTree(target, root->left);
	} 
	else 
	{
		return searchTree(target, root->right);
	}
	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
	// base case
	if(root == nullptr) return -1;

	// General case
	return 1 + treeSize(root->left) + treeSize(root->right);

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	// base case
	if(root == nullptr) return -1;
	int leftHeight = treeHeight(root->left);
	int rightHeight = treeHeight(root->right);
	// General Case
	if(leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}
