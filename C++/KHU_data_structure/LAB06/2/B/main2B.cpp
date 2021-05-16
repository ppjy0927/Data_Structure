#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
	QueType<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(5);
	queue.Enqueue(6);
	queue.Enqueue(2);
	queue.Enqueue(6);

	queue.ReplaceItem(6, 1);

	int item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << ' ';
	}
	return 0;
}