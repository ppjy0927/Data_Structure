// recursive 방법
// 이것보다 iteration 이용하는 것이 더 효율적임
// 많은 함수 호출을 위해 메모리의 stack 공간을 이용하기 때문에 많은 메모리를 사용하기 때문.
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void Print(Node* p) {
	if (p == NULL) return; // Exit condition
	// Print를 나중에 하면 원래대로, Print를 먼저 하면 역순으로 리스트가 출력됨
	cout << p->data << " "; // First print the value in the node
	Print(p->next); // Recursive call
}

void ReversePrint(Node* p) {
	if (p == NULL) return;
	ReversePrint(p->next);
	cout << p->data << " ";
}

Node* Insert(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (head == NULL) head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

int main() {
	Node* head = NULL; // local variable
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 5);
	Print(head);
}







