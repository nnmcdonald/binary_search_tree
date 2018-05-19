#include "bst.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream input;
	input.open(argv[1]);
	int x;
	input >> x;
	BinarySearchTree tree(x);
	int dataPoints = 1;
	int treeNodes = 1;

	while (input >> x)
	{
		//Not already in tree
		if (tree.find(x, tree.getRoot()) == -1)
			treeNodes++;
		dataPoints++;
		tree.insert(x, tree.getRoot());
	}

	cout << "Number of Nodes: " << treeNodes << endl;
	cout << "Number of data points: " << dataPoints << endl;
	cout << "Generated tree has height: " << tree.getHeight(tree.getRoot(), 0) << endl;
}