
class BinarySearchNode
{
public:
	BinarySearchNode(int value);
	void setValue(int value);
	void setLeft(BinarySearchNode* node);
	void setRight(BinarySearchNode* node);
	int getValue();
	BinarySearchNode* getLeft();
	BinarySearchNode* getRight();
private:
	int storedValue;
	BinarySearchNode* childLeft;
	BinarySearchNode* childRight;
};


class BinarySearchTree
{
public:
	BinarySearchTree(int value);
	void insert(int value, BinarySearchNode* node);
	BinarySearchNode* remove(int value, BinarySearchNode* t);
	BinarySearchNode* getRoot();
	int findMin(BinarySearchNode current);
	int findMax(BinarySearchNode current);
	int find(int value, BinarySearchNode* node);
	int getHeight(BinarySearchNode* node, int initialHeight);
private:
	BinarySearchNode* root;
};


