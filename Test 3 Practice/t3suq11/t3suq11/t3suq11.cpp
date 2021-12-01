#include <iostream>
#include <vector>

class ExpressionNode {

public:
	ExpressionNode(ExpressionNode* newLeft, ExpressionNode* newRight, char newData) : left(newLeft), right(newRight), data(newData) {};

	ExpressionNode* left;
	ExpressionNode* right;
	char data;
};

int calculateValue(ExpressionNode* currNode) {
	if (currNode == nullptr)
		return 0;
	else if (currNode->data - '0' <= 9 && currNode->data - '0' >= 0)
		return currNode->data - '0';
	else if (currNode->data == '*') {
		return calculateValue(currNode->left) * calculateValue(currNode->right);
	}
	else if (currNode->data == '+') {
		return calculateValue(currNode->left) + calculateValue(currNode->right);
	}
	else if (currNode->data == '/')
		return calculateValue(currNode->left) / calculateValue(currNode->right);
	else
		return calculateValue(currNode->left) - calculateValue(currNode->right);
}



int main() {
	ExpressionNode* root = new ExpressionNode(nullptr, nullptr, '*');
	root->left = new ExpressionNode(nullptr, nullptr, '+');
	root->left->left = new ExpressionNode(nullptr, nullptr, '2');
	root->left->right = new ExpressionNode(nullptr, nullptr, '3');
	root->right = new ExpressionNode(nullptr, nullptr, '7');

	std::cout << calculateValue(root);
	//root->left =
	return 0;
}