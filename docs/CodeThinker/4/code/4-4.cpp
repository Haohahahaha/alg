/* LeetCode Question No.19
 * Given the head of a linked list, remove the nth node from the end of the list
 * and return its head.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;

		ListNode* slow = dummyhead;
		ListNode* fast = dummyhead;
		while (n-- && fast != nullptr) {
			fast = fast->next;
		}

		fast = fast->next;
		while (fast != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		slow->next = slow->next->next;

		return dummyhead->next;
	}
};

int main () {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2, l1);
	ListNode* l3 = new ListNode(3, l2);
	ListNode* l4 = new ListNode(4, l3);
	ListNode* l5 = new ListNode(5, l4);
	ListNode* head = new ListNode(6, l5);
	
	Solution sl;
	ListNode* ptr = sl.removeNthFromEnd(head, 3);

	while(ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;


	return 0;
}
