#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr) {}
};
ListNode* reverse_linked_list(ListNode* head) {
	std::vector<int> temp;
	ListNode* currNode = head;
	while (currNode!= nullptr) {
		temp.push_back(currNode->val);
		currNode = currNode->next;
	}

	ListNode* newList = new ListNode(temp[temp.size() - 1]);
	currNode = newList;
	for (int i = temp.size()-2; i >= 0; --i) {
		currNode->next = new ListNode(temp[i]);
		currNode = currNode->next;
	}
	return newList;
}
bool is_target_in_list(ListNode* head, int target) {
	// check if the linked list contains the target
	return true;
}
int find_max(ListNode* head) {
	// find the largest value in the node
	return 0;
}

int main() {
	ListNode* head = new ListNode(5);
	head->next = new ListNode(3);
	head->next->next = new ListNode(-1);
	head->next->next->next = new ListNode(-1);

	head = reverse_linked_list(head);

	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}


	return 0;
}