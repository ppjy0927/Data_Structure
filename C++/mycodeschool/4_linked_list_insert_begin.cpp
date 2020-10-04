// Linked List : Inserting a node at beginning

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// Node에 대한 포인터 만들기
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
	// empty list 만들기
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
//	// empty list 만들기
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
//	//  첫번째 노드 추가
//	Node* temp = new Node();
//
//	temp->data = 2; // (*temp).data = 2와 같은 표현
//	temp->next = NULL;
//	head = temp;
//
//	// 새 노드 생성, temp는 새 노드의 주소를 저장함
//	temp = new Node();
//	temp->data = 4;
//	temp->next = NULL;
//
//	// Traversal(순회)
//	Node* temp1 = A;
//	while (temp1->next != NULL) {
//		temp1 = temp1->next;
//	}
//	temp1->next = temp;
//}
