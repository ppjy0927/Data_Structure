#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Node* head; // global
void Insert(int data); // insert an integer at end of list
void Print(); // print all elements in the list
void Delete(int n); // Delete node at position n

int main() {
	head = NULL; // empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); // List : 2, 4, 6, 5
	Print();
	int n;
	cout << "Enter a position" << endl;
	cin >> n;
	Delete(n);
	Print();
}

// Delete node at position n
void Delete(int n) {
	Node* temp1 = head; 
	if (n == 1) {
		// temp1�� 1��° node�� ����� ���� 1��°�� �ּҰ��� �ӽ÷� ������ �ִ� ����
		head = temp1->next; // head�� 2��° node�� ����Ű�� ��. head�� 1��° node�� ��ũ�� �����.
		delete temp1; // 1��° node �����
		return; // �޺κ��� �����ϸ� �� �Ǵϱ�
	}

	// n != 1 �� ��
	// temp1�� ����⸦ ���ϴ� n��° node�� ���� node(n-1��°)�� �ּҰ��� �ӽ÷� ������ ����
	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next; // temp1�� (n-1)��° node�� ����Ŵ.
	Node* temp2 = temp1->next; // temp2�� n��° node�� ����Ŵ.
	temp1->next = temp2->next; // (n-1)��° node�� ���� n��°�� �ƴ� (n+1)��° node�� �ּҰ��� ����Ű�� ��.
	delete temp2; // n��° node �����
}

void Insert(int data) {
	Node* temp = new Node(); // ���� �����ϴ� ����� �ּҰ� ����
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}