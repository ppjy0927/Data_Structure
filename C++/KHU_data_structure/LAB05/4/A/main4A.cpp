#include <iostream>
#include "QueType.h"
using namespace std;

// a. Client 함수로 작성
int Length(QueType& queue);

int main() {
	QueType queue;
	ItemType item1, item2, item3, item4, item5;
	item1 = 7;
	item2 = 4;
	item3 = 5;
	item4 = 6;
	item5 = 9;

	queue.Enqueue(item1);
	queue.Enqueue(item2);
	queue.Enqueue(item3);
	queue.Enqueue(item4);
	queue.Enqueue(item5);

	cout << "큐에 저장된 아이템 수: " << Length(queue);

	return 0;
}

int Length(QueType& queue) {
	QueType temp;
	ItemType item;
	int count = 0;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		temp.Enqueue(item);
		count++;
	}
	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
	return count;
}