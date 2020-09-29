#include <iostream>

using namespace std;

struct Node {
	int data; // ������ ����
	struct Node* next; // ���� node�� �ּ� ����
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x) {
	// '�ּҸ� ������ ������' = new '�Ҵ��ϰ� ���� ũ���� �ڷ���';
	// node ���� / temp�� enqueue�� node�� ����Ű�� �ּ�
	struct Node* temp = new (struct Node);
	temp->data = x;
	temp->next = NULL;
	// queue�� element�� ������
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	// node�� ���� ������, �� �ּҸ� ������
	struct Node* temp = front;
	if (front == NULL) return;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	delete temp;
}