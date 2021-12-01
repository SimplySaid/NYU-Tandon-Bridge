#include <iostream>
#include <list>
#include <queue>

struct BSTNode {
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;
	int data;
};

const int MAX_VAL = 7;

int main() {
	BSTNode* root = new BSTNode{nullptr, nullptr, nullptr, 0};
	root->left = new BSTNode{ nullptr, nullptr, root, 3 };
	root->right = new BSTNode{ nullptr, nullptr, root, 10 };
	root->left->left = new BSTNode{ nullptr, nullptr, root->left, 7 };
	root->right->left = new BSTNode{ nullptr, nullptr, root->right, 6 };
	root->right->left->left = new BSTNode{ nullptr, nullptr, root->right->left, -1 };
	std::queue<BSTNode*> bst;

	BSTNode* currNode = root;
	bst.push(currNode);
	std::list<int> res;

	while (!bst.empty()) {
		if (bst.front()->left != nullptr)
			bst.push(bst.front()->left);
		if (bst.front()->right != nullptr)
			bst.push(bst.front()->right);
		
		if (bst.front()->data <= MAX_VAL)
			res.push_back(bst.front()->data);
		bst.pop();
	}

	for (const auto i : res)
		std::cout << i << "\n";
}