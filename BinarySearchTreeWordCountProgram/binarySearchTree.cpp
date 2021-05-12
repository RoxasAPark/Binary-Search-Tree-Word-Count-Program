#include "binarySearchTree.h"

// Function to delete all the nodes in a binary search tree.
// Needed for the destructor to clear a binary search tree of
// all nodes to clear up space in memory
// **************************************************************
void BST::deleteTree(Node * node)
{
	if (node == NULL)
		return;

	// Delete both subtrees (left then right)
	deleteTree(node->left);
	deleteTree(node->right);

	delete node;
}

// Constructor to start the binary search tree with an empty root
// **************************************************************
BST::BST()
{
	root = NULL;
}

// Copy constructor that basically makes a copy of a BST object
// **************************************************************
BST::BST(const BST &copy)
{
	root = copy.root;
}

// Destructor to clear the binary search tree
// **************************************************************
BST::~BST()
{
	deleteTree(root);
}

// Outputs the entire binary search tree via inorder traversal
// **************************************************************
void BST::outputTree()
{
	outputTreeHelper(root);
}

// Search for a node in a binary search tree based on the word
// **************************************************************
Node * BST::lookup(string target)
{
	root = lookupHelper(root, target);
	return root;
}

// Function to insert a node into the binary search tree
// **************************************************************
void BST::insert(string value)
{
	root = insertHelper(root, value);
}

// Helper function to insert a node into the binary search tree
// **************************************************************
Node* BST::insertHelper(Node * node, string value)
{
	if (node == NULL)
	{
		node = new Node(value);
		node->count++;
		return node;
	}

	if (value == node->word)
	{
		node->count++;
		return node;
	}

	if (value < node->word)
		node->left = insertHelper(node->left, value);
	else
		node->right = insertHelper(node->right, value);

	return node;
}

Node* BST::lookupHelper(Node* node, string target)
{
	if (node == NULL || target == node->word)
		return node;

	if (node->word < target)
		return lookupHelper(node->right, target);

	return lookupHelper(node->left, target);
}

// Helper function to output values of every node 
// inside the binary search tree via an inorder traversal
// **************************************************************
void BST::outputTreeHelper(Node * node)
{
	if (node == NULL)
		return;

	outputTreeHelper(node->left);
	cout << node->word << " " << node->count << " " << endl;
	outputTreeHelper(node->right);
}

// Constructor for a node object
// **************************************************************
Node::Node(string value)
{
	word = value;
	left = NULL;
	right = NULL;
}
