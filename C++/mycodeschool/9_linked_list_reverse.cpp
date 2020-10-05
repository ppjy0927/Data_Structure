// Reverse 함수
// 루프를 사용하는 반복적인 접근 방식

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head;

Node* Reverse(Node* head) {
	Node *current, *prev, *next;
	current = head; // current가 첫번째 node를 가리킴
	prev = NULL;
	while (current != NULL) {
		// current가 NULL이 아니면(첫번째 node가 마지막 node가 아니면) 1번째 node의 next에 해당하는 2번째 node의 주소값을 next가 가리킴
		// next, current, prev 순으로 포인터 이동!
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev; // 원래 list의 마지막 요소(바뀐 list의 첫 요소)의 주소값을 prev가 갖고 있으니까 head에 넣어줌
	return head;
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

void Print(Node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head = NULL; // 지역 변수
	head = Insert(head, 2); // Insert : struct Node* Insert(Node* head, int data)
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	head = Reverse(head);
	Print(head);
}