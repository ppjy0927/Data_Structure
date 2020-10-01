// Linked List : Inserting a noed at beginning

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// Node�� ���� ������ �����
Node* head;

void Insert(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print() {
	Node* temp = head;
	cout << "List is : ";
	while (temp != NULL) {
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	// empty list �����
	head = NULL;
	cout << "How many numbers?\n";
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter the number: \n";
		cin >> x;
		Insert(x);
		Print();
	}
}

//int main() {
//	// empty list �����
//	head = NULL;
//	cout << "How many numbers?\n";
//	int n, x;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cout << "Enter the number\n";
//		cin >> x;
//		Insert(x);
//		Print();
//	}
//
//	//  ù��° ��� �߰�
//	Node* temp = new Node();
//
//	temp->data = 2; // (*temp).data = 2�� ���� ǥ��
//	temp->next = NULL;
//	head = temp;
//
//	// �� ��� ����, temp�� �� ����� �ּҸ� ������
//	temp = new Node();
//	temp->data = 4;
//	temp->next = NULL;
//
//	// Traversal(��ȸ)
//	Node* temp1 = A;
//	while (temp1->next != NULL) {
//		temp1 = temp1->next;
//	}
//	temp1->next = temp;
//}