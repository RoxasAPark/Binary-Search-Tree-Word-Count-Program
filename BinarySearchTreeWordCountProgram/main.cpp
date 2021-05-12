#include "binarySearchTree.h"
#include <fstream>
#include <stack>

int main()
{
	BST *tree = new BST();

	fstream file;
	string word, filename;

	// text file to read 
	filename = "FireBobbyValentine.txt";

	stack<string> s;

	int count = 0;
	
	file.open(filename.c_str());

	// while the file is open, push each word to the stack
	// and eventually get the total word count
	while (file >> word)
	{
		s.push(word);
		count++;
	}

	// for each word, add it to the binary search tree
	// and pop the word from the stack
	while (s.empty() == false)
	{
		tree->insert(s.top());
		s.pop();
	}

	// output the tree and the word count to verify 
	tree->outputTree();

	cout << endl;
	cout << "Total word count: " << count << " words" << endl;

	cout << endl;
	cout << endl;

	Node *tmp = tree->lookup("Valentine");

	cout << tmp->word << " " << tmp->count << " " << endl;

	system("pause");
	return 0;
}