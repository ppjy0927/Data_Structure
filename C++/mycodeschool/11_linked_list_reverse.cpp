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
	// ��� ȣ�� ��, �� ���� ��带 reverse�ϴ� ��
	Node* q = p->next;
	q->next = p;
	// ���� ������ p->next->next = p�� ��Ÿ�� �� ����
	p->next = NULL;
}

void ReversePrint(Node* p) {
	if (p == NULL) {
		return;
	}
	ReversePrint(p->next);
	cout << p->data << " ";
}