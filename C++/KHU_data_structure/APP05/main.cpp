#include <iostream>
#include "QueType.h"
using namespace std;

void top_discard(QueType& queue) {
	QueType temp;
	ItemType item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		temp.Enqueue(item);
		if (!queue.IsEmpty()) {
			queue.Dequeue(item);
			queue.Enqueue(item);
		}
	}
	while (!temp.IsEmpty()) {
		temp.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main() {
	int N;
	cout << "정수 N(1 <= N <= 1,000) 입력: ";
	cin >> N;

	QueType queue(N);
	for (int i = 1; i <= N; i++) {
		queue.Enqueue(i);
	}

	top_discard(queue);

	ItemType item;
	for (int i = 0; i < N; i++) {
		queue.Dequeue(item);
		cout << item << " ";
	}
	return 0;
}