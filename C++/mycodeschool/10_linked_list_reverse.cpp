// recursive ���
// �̰ͺ��� iteration �̿��ϴ� ���� �� ȿ������
// ���� �Լ� ȣ���� ���� �޸��� stack ������ �̿��ϱ� ������ ���� �޸𸮸� ����ϱ� ����.
#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void Print(Node* p) {
	if (p == NULL) return; // Exit condition
	// Print�� ���߿� �ϸ� �������, Print�� ���� �ϸ� �������� ����Ʈ�� ��µ�
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







