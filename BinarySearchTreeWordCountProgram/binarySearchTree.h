// File Name: binarySearchTree.h
// Author: Andrew Park
// Purpose: Maintain a file that defines the following structs and classes:

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// struct Node: Represents a node object inside a binary search tree
// Each node has a pointer to the left child (node) and the right child (node).
// Each node also contains a string value representing a word and a count (int)
// that determines how many times a word appears in a .txt file

class Node {
	public: 
		string word;
		int count;
		Node *left;
		Node *right;
		Node(string value);
};

// class BST: Represents the binary search tree
// Each binary search tree has a root node.

class BST {
	private:
		Node *root;
		void deleteTree(Node *node);
		Node* insertHelper(Node *node, string value);
		Node* lookupHelper(Node *node, string target);
		void outputTreeHelper(Node *node);
	public:
		BST(); // Constructor (basically starts with an empty binary search tree)
		BST(const BST &copy); // Copy constructor
		~BST(); // destructor to delete an entire binary search tree to clear up space in memory
		void outputTree();
		Node* lookup(string target);
		void insert(string value);
};
