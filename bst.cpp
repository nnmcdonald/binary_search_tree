#include "bst.h"

BinarySearchNode::BinarySearchNode(int num)
{
	storedValue = num;
	childLeft = nullptr;
	childRight = nullptr;
}

void BinarySearchNode::setValue(int num)
{
	storedValue = num;
}

void BinarySearchNode::setLeft(BinarySearchNode* node)
{
	childLeft = node;
}

void BinarySearchNode::setRight(BinarySearchNode* node)
{
	childRight = node;
}

BinarySearchNode* BinarySearchNode::getLeft()
{
	return childLeft;
}

BinarySearchNode* BinarySearchNode::getRight()
{
	return childRight;
}

int BinarySearchNode::getValue()
{
	return storedValue;
}

BinarySearchTree::BinarySearchTree(int value)
{
	root = new BinarySearchNode(value);
}

void BinarySearchTree::insert(int num, BinarySearchNode* node)
{
	//value is less than current node, go to left child node
	if (num < (*node).getValue())
	{
		if ((*node).getLeft() != nullptr)
			insert(num, (*node).getLeft());
		else
		{
			BinarySearchNode* newNode = new BinarySearchNode(num);
			(*node).setLeft(newNode);
		}
	}
	//value is greater than current node, go to right child node
	else if (num > (*node).getValue())
	{
		if ((*node).getRight() != nullptr)
			insert(num, (*node).getRight());
		else
		{
			BinarySearchNode* newNode = new BinarySearchNode(num);
			(*node).setRight(newNode);
		}
	}
	//else the value is already in tree, do nothing
}

BinarySearchNode* BinarySearchTree::remove(int num, BinarySearchNode* node)
{
	if(node == nullptr) 
		return node; // Not Found
	if (num < (*node).getValue())
		(*node).setLeft(remove(num, (*node).getLeft()));
	else if (num > (*node).getValue())
		(*node).setRight(remove(num, (*node).getRight()));
	// Two children
	else if ((*node).getLeft() != nullptr && (*node).getRight() != nullptr)
	{ 
		(*node).setValue(findMin((*(*node).getRight()).getValue()));
		(*node).setRight(remove((*node).getValue(), (*node).getRight()));
	}
	// None or One child
	else 
		node = ((*node).getLeft() != nullptr) ? (*node).getLeft() : (*node).getRight();
	return node;
}

//Returns value if it is found or -1 if it is not in the tree
int BinarySearchTree::find(int value, BinarySearchNode* node)
{
	if (node == nullptr)
		return -1;
	else if (value < (*node).getValue())
		find(value, (*node).getLeft());
	else if (value > (*node).getValue())
		find(value, (*node).getRight());
	else
		return value;
}

int BinarySearchTree::getHeight(BinarySearchNode* node, int initialHeight)
{
	
	if (node == nullptr)
		return initialHeight;
	//Node has 2 children, compare the heights of each child and return greater value
	else if ((*node).getLeft() != nullptr && (*node).getRight() != nullptr)
	{
		initialHeight++;
		int temp1 = getHeight((*node).getLeft(), initialHeight);
		int temp2 = getHeight((*node).getRight(), initialHeight);
		return ((temp1 > temp2) ? temp1 : temp2);
	}
	//Node only has left child, return left child height
	else if ((*node).getLeft() != nullptr)
	{
		initialHeight++;
		int temp = getHeight((*node).getLeft(), initialHeight);
		return temp;
	}
	//node only has right child, return right child height
	else if ((*node).getRight() != nullptr)
	{
		initialHeight++;
		int temp = getHeight((*node).getRight(), initialHeight);
		return temp;
	}
	else
	{
		initialHeight++;
		return initialHeight;
	}
	
}

BinarySearchNode* BinarySearchTree::getRoot()
{
	return root;
}

int BinarySearchTree::findMin(BinarySearchNode current)
{
	if (current.getLeft() != nullptr)
	{
		current = *current.getLeft();
		findMin(current);
	}
	else
	{
		return current.getValue();
	}
}

int BinarySearchTree::findMax(BinarySearchNode current)
{
	if (current.getRight() != nullptr)
	{
		current = *current.getRight();
		findMax(current);
	}
	else
	{
		return current.getValue();
	}
}