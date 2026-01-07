/* LeetCode Question No.206
 * Given the head of a singly linked list, reverse the list, and return the 
 * reversed list.
 */

#include <iostream>

using namespace std;
struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

class Solution {
public:
	ListNode* reverselist(ListNode* head) {
		ListNode* temp;
		ListNode* cur = head;
		ListNode* pre = nullptr;

		while (cur) {
			// save the next node of cur
			temp = cur->next;
			// REVERSE	
			cur->next = pre;
			// update pre and cur
			pre = cur;
			cur = temp;
		}
		return pre;
	}
};

int main() {
	ListNode* tail = new ListNode(1);
	ListNode* l4 = new ListNode(2, tail);
	ListNode* l3 = new ListNode(3, l4);
	ListNode* l2 = new ListNode(4, l3);
	ListNode* head = new ListNode(5, l2);

	Solution sl;
	ListNode* newHead = sl.reverselist(head);

	while (newHead) {
		cout << newHead->val << " ";
		newHead = newHead->next;
	}

	return 0;
}
