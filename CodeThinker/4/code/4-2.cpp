/* LeetCode Question No.707
 *
 * Design your implementation of the linked list. You can choose to use a singly
 * or doubly linked list.
 *
 * A node in a singly linked list should have two attributes: val and next. val
 * is the value of the current node, and next is a pointer/reference to the next
 * node.
 *
 * If you want to use the doubly linked list, you will need one more attribute
 * prev to indicate the previous node in the linked list. Assume all nodes in 
 * the linked list are 0-indexed.
 *
 * Implement the MyLinkedList class:
 *
 * MyLinkedList() Initializes the MyLinkedList object.
 *
 * int get(int index) Get the value of the indexth node in the linked list. If 
 * the index is invalid, return -1.
 *
 * void addAtHead(int val) Add a node of value val before the first element of 
 * the linked list. After the insertion, the new node will be the first node of
 * the linked list.
 *
 * void addAtTail(int val) Append a node of value val as the last element of the
 * linked list.
 * 
 * void addAtIndex(int index, int val) Add a node of value val before the 
 * index^th node in the linked list. If index equals the length of the linked 
 * list, the node will be appended to the end of the linked list. If index is 
 * greater than the length, the node will not be inserted.
 *
 * void deleteAtIndex(int index) Delete the indexth node in the linked list, if
 * the index is valid.
 */

#include <iostream>

using namespace std;

class MyLinkedList {
public:
	// define linkedlist node structure
	struct LinkedNode {
		int val;
		LinkedNode* next;
		LinkedNode(int val): val(val), next(nullptr){}
	};

	// initialize linkedlist
	MyLinkedList() {
		// define a virtual head node
		_dummyHead = new LinkedNode(0);
		_size = 0;
	}

	// get the nth node value: if index is invalid, return -1;
	// Only when index is bigger than the linkedlist size(_size) or smaller
	// than 0, the index is invalid.
	// ATTENTION: index is start from 0, the 0th node is the head node.
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
		LinkedNode* cur = _dummyHead->next;
		while (index--) {
			// if "--index", the last loop will let index to INT_32, then
			// the program will stuck in the loop.
			// cout << index << endl;
			cur = cur->next;
		}
		return cur->val;
	}

	// insert a node in the front of linkedlist, then the new node will be the
	// new headnode.
	void addAtHead(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		newNode->next = _dummyHead->next;
		_dummyHead->next = newNode;
		_size++;
	}
	
	// insert a node at the end of linkedlist.
	void addAtTail(int val) {
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		// we need O(n) time to traverse the whole linkedlist.
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		_size++;
	}

	// insert a node in front of the 'index'th node
	// if index is 0, the inserted node is the new headnode;
	// if index is equal to _size, the inserted node is the last node of 
	// the linkedlist;
	// and if index is bigger than the length of linkedlist, return nothing.
	void addAtIndex(int index, int val) {
		if (index > _size) {
			return;
		}
		LinkedNode* newNode = new LinkedNode(val);
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		_size++;
	}
	
	// delete the 'index'th node, if index bigger than or equal to length
	// of linkedlist, return nothing.
	void deleteAtIndex(int index) {
		if (index >= _size || index < 0) {
			return;
		}
		LinkedNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
		LinkedNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		_size--;
	}

	// print linkedlist
	void printLinkedList() {
		LinkedNode* cur = _dummyHead;
		while (cur->next != nullptr) {
			cout << cur->next->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}

private:
	int _size;
	LinkedNode* _dummyHead;

};

int main() {
	MyLinkedList *sl = new MyLinkedList();
	sl->addAtTail(5);
	sl->addAtHead(3);
	sl->addAtIndex(1,4);
	sl->addAtIndex(3,5);
	sl->deleteAtIndex(3);
	sl->printLinkedList();

	cout << "Now you can search any node:";
	int index = 0;
	cin >> index;
	cout << "the value is: " << sl->get(index) << endl;

	return 0;

}
