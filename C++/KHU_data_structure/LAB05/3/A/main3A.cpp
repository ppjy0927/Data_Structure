#include <iostream>
#include "QueType.h"
using namespace std;

// a. Client 함수로 작성
bool Identical(QueType& queue1, QueType& queue2);

int main() {
	QueType queue1, queue2;
	ItemType item1a, item2a, item3a, item4a, item5a, item6a,
			 item1b, item2b, item3b, item4b, item5b, item6b;
	item1a = 2;
	item2a = 6;
	item3a = 7;
	item4a = 4;
	item5a = 5;
	item6a = 6;

	item1b = 2;
	item2b = 6;
	item3b = 7;
	item4b = 4;
	item5b = 5;
	item6b = 7;

	queue1.Enqueue(item1a);
	queue1.Enqueue(item2a);
	queue1.Enqueue(item3a);
	queue1.Enqueue(item4a);
	queue1.Enqueue(item5a);
	queue1.Enqueue(item6a);

	queue2.Enqueue(item1b);
	queue2.Enqueue(item2b);
	queue2.Enqueue(item3b);
	queue2.Enqueue(item4b);
	queue2.Enqueue(item5b);
	queue2.Enqueue(item6b);

	cout << Identical(queue1, queue2);
	return 0;
}

bool Identical(QueType& queue1, QueType& queue2) {
	QueType temp1, temp2;
	ItemType temp_item1, temp_item2;
	bool identical = true;
	while (!queue1.IsEmpty()) {
		queue1.Dequeue(temp_item1);
		queue2.Dequeue(temp_item2);
		temp1.Enqueue(temp_item1);
		temp2.Enqueue(temp_item2);
		if (temp_item1 != temp_item2) {
			identical = false;
		}
	}
	while (!temp1.IsEmpty()) {
		temp1.Dequeue(temp_item1);
		queue1.Enqueue(temp_item1);
	}
	while (!temp2.IsEmpty()) {
		temp2.Dequeue(temp_item2);
		queue2.Enqueue(temp_item2);
	}
	return identical;
}