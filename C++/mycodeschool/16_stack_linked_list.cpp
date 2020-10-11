// linked list implementation of stacks

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* link;
};

Node* top = NULL;

void Push(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop() {
	Node* temp;
	if (top == NULL) return;
	temp = top;
	top = top->link;
	delete temp;
}