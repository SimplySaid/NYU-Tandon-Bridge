#include <iostream>
#include <iomanip>

template <typename T>
class AVLTree {
private:
	class Node {
	private:
		T data;
		int height;
		Node* left_child;
		Node* parent;
		Node* right_child;
	public:
		Node(T val);

		int getBalance();
		int getData() const { return data; }
		int getHeight() const { return height; }
		Node* getLeftChild() const { return left_child; }
		Node* getParent() const { return parent; }
		Node* getRightChild() const { return right_child; }
		void removeParent();
		Node* setLeftChild(Node* newLeft) {
			newLeft->parent = this;
			left_child = newLeft;
			newLeft->updateHeight();
			return newLeft;
		}

		Node* setRightChild(Node* newRight) {
			newRight->parent = this;
			right_child = newRight;
			newRight->updateHeight();
			return newRight;
		}

		int updateHeight();
	};

private:
	Node* root;
public:
	AVLTree() : root(nullptr) {};

	void insert(T e);
	void remove(T e);
	void printSubtree(Node* subtree, int depth, int level, bool first);
	void balanceNode(Node* n);
	int spacing(int level);
	void setRoot(Node* r) { root = r; }
	void print();

	void rotateLeft(Node* n);
	void rotateRight(Node* n);
};

template <typename T>
AVLTree<T>::Node::Node(T val) : data(val), height(0), left_child(nullptr), parent(nullptr), right_child(nullptr) {};

template <typename T>
int AVLTree<T>::Node::getBalance() {
	int left, right;
	if (getLeftChild() == nullptr)
		left = 0;
	else
		left = getLeftChild()->getHeight() + 1;
	if (getRightChild() == nullptr)
		right = 0;
	else
		right = getRightChild()->getHeight() + 1;
	return left - right;
}

template <typename T>
void AVLTree<T>::insert(T e) {
	if (root == nullptr)
		root = new Node(e);
	else {
		Node* currNodePtr = root;
		Node* insertedNode = nullptr;
		while (currNodePtr != nullptr && insertedNode == nullptr) {
			if (e <= currNodePtr->getData()) {
				if (currNodePtr->getLeftChild() == nullptr)
					insertedNode = currNodePtr->setLeftChild(new Node(e));
				else
					currNodePtr = currNodePtr->getLeftChild();
			}
			else if (e > currNodePtr->getData()) {
				if (currNodePtr->getRightChild() == nullptr)
					insertedNode = currNodePtr->setRightChild(new Node(e));
				else
					currNodePtr = currNodePtr->getRightChild();
			}
		}
		currNodePtr = insertedNode;
		while (currNodePtr != nullptr) {
			currNodePtr->updateHeight();
			balanceNode(currNodePtr);
			currNodePtr = currNodePtr->getParent();
		}
	}
}

template <typename T>
int AVLTree<T>::spacing(int level) {
	int result = 1;
	for (int i = 0; i < level; i++)
		result += result;
	return result;
}

template <typename T>
int AVLTree<T>::Node::updateHeight() {
	if (left_child == nullptr) {
		if (right_child == nullptr)
			height = 0;
		else
			height = right_child->getHeight() + 1;
	}
	else if (right_child == nullptr)
		height = left_child->getHeight() + 1;
	else
		height = std::max(left_child->getHeight() + 1, right_child->getHeight() + 1);
	return height;
}

template <typename T>
void AVLTree<T>::rotateLeft(Node* n) {
	Node* parent = n->getParent();
	enum {left, right} side;
	std::cout << "test1";
	if (parent != nullptr && parent->getLeftChild() == n)
		side = left;
	else
		side = right;

	Node* temp = n->getRightChild();
	n->setRightChild(temp->getLeftChild());;
	temp->setLeftChild(n);

	if (parent == nullptr)
		setRoot(temp);
	else if (side == left)
		parent->setLeftChild(temp);
	else
		parent->setRightChild(temp);
		
}

template <typename T>
void AVLTree<T>::balanceNode(Node* n) {
	if (n->getBalance() < -1 || n->getBalance() > 1)
		rotateLeft(n);
}

template <typename T>
void AVLTree<T>::printSubtree(Node* subtree, int depth, int level, bool first) {
	if (depth > 0) {
		if (subtree == nullptr) {
			printSubtree(subtree, depth - 1, level, first);
			printSubtree(subtree, depth - 1, level, false);
		}
		else {
			printSubtree(subtree->getLeftChild(), depth - 1, level, first);
			printSubtree(subtree->getRightChild(), depth - 1, level, false);
		}
	}
	else if (subtree == nullptr)
		std::cout << std::setw((first) ? spacing(level) / 2 : spacing(level)) << "-";
	else
		std::cout << std::setw((first) ? spacing(level) / 2 : spacing(level)) << subtree->getData();
}

template <typename T>
void AVLTree<T>::print() {
	if (root == nullptr)
		std::cout << "Tree is empty!\n";
	else {
		int max = root->getHeight();
		for (int depth = 0; depth <= max; depth++) {
			printSubtree(root, depth, max - depth + 1, true);
			std::cout << std::endl;
		} 
	} 
}

int main() {
	AVLTree<int>* testTree = new AVLTree<int>();
	
	testTree->insert(25);
	testTree->insert(20);
	testTree->insert(10);
	testTree->insert(22);
	testTree->insert(30);
	testTree->insert(40);
	testTree->insert(50);
	testTree->print();
	
	return 0;
}