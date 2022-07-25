/* LeetCode Question No.203
 *
 * Given the head of a linked list and an integer val, remove all the nodes of 
 * the linked list that has Node.val == val, and return the new head.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printh(ListNode* head);

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		// delete head node
		while (head != NULL && head->val == val) {
			ListNode* tmp = head;
			head = head->next;
			delete tmp;
		}

		// delete non-head node
		ListNode* cur = head;
		while (cur != NULL && cur->next != NULL) {
			if (cur->next->val == val) {
				ListNode* tmp = cur->next;
				cur->next = cur->next->next;
				delete tmp;
			} else {
				cur = cur->next;
			}
		}
		return head;
	}
};

int main() {
	ListNode* n1 = new ListNode(3);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(5);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution sl;
	ListNode* nhead = sl.removeElements(n1, 3);

	printh(nhead);

	return 0;
}

void printh(ListNode* head) {
	ListNode* tmp = head;
	while (1) {
		cout << tmp->val << " ";
		if (tmp->next != nullptr) {
			tmp = tmp->next;
		} else {
			break;
		}
	}
	delete tmp;
}
