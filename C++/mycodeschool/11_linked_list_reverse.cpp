#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

void Reverse(Node* p) {
	if (p->next == NULL) {
		head = p;
		return;
	}
	Reverse(p->next);
	// 재귀 호출 후, 그 다음 노드를 reverse하는 것
	Node* q = p->next;
	q->next = p;
	// 위의 두줄을 p->next->next = p로 나타낼 수 있음
	p->next = NULL;
}

void ReversePrint(Node* p) {
	if (p == NULL) {
		return;
	}
	ReversePrint(p->next);
	cout << p->data << " ";
}