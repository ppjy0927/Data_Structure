#include <iostream>

using namespace std;

struct Node {
	int data; // 데이터 저장
	struct Node* next; // 다음 node의 주소 저장
};

struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue(int x) {
	// '주소를 저장할 포인터' = new '할당하고 싶은 크기의 자료형';
	// node 생성 / temp는 enqueue할 node를 가르키는 주소
	struct Node* temp = new (struct Node);
	temp->data = x;
	temp->next = NULL;
	// queue에 element가 없으면
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	// node에 대한 포인터, 앞 주소를 저장함
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