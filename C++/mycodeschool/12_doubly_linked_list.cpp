// Doubly Linked List

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
};

Node* head; // global variable - pointer to head node

Node* GetNewNode(int x) {
	//// local variable
	//// Will be cleared from memory when function call with finish
	//Node myNode;
	//myNode.data = x;
	//myNode.next = NULL;
	//myNode.prev = NULL;

	// 포인터를 사용해 heap section의 노드를 참조
	Node* newNodePtr = new Node();
	newNodePtr->data = x;
	newNodePtr->prev = NULL;
	newNodePtr->next = NULL;
	return newNodePtr;
}

void InsertAtHead(int x) {
	Node* newNode = GetNewNode(x);
	if (head == NULL) { // list가 비어있을 때
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

Node* GetNewNode(int x) {
	Node newNode;
	newNode.data = x;
	newNode.prev = NULL;
	newNode.next = NULL;
	return &newNode; // prev와 next를 NULL로 만들기 위해 &연산자 사용
}

void Print() {
	Node* temp = head; // 노드에 대한 임시 포인터
	cout << "Forward : ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void ReversePrint() {
	Node* temp = head;
	if (temp == NULL) return; // empty list, exit
	// Going to last Node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	cout << "Reverse : ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
}

int main() {
	head = NULL; // empty list
	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
}