/* Given the head of a linked list, return the node where the cycle begins. If
 * there is no cycle, return null.
 *
 * There is a cycle in a linked list if there is some node in the list that can 
 * be reached again by continuously following the next pointer. Internally, 
 * `pos` is used to denote the index of the node that tail's next pointer is 
 * connected to (0-indexed). It is -1 if there is no cycle. Note that `pos` not
 * passed as a parameter.
 *
 * Do not modify the linked list.
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* NEXT) : val(x), next(NEXT) {}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				ListNode* index1 = fast;
				ListNode* index2 = head;
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;
				}
				return index2;
			}
		}
		return nullptr;
	}
};

int main() {
	ListNode* n5 = new ListNode(5);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(2, n3);
	n5->next = n2;
	ListNode* n1 = new ListNode(1, n2);

	Solution sl;
	ListNode* res = sl.detectCycle(n1);
	cout << res->val << endl;
	return 0;
}
