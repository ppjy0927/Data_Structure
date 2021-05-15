#include <iostream>
#include "QueType.h"
using namespace std;

template <class ItemType>
void ReplaceItem(QueType<ItemType> &queue, ItemType oldItem, ItemType newItem) {
	QueType<ItemType> temp_queue;
	ItemType item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		if (item == oldItem) {
			temp_queue.Enqueue(newItem);
		}
		else {
			temp_queue.Enqueue(item);
		}
	}
	while (!temp_queue.IsEmpty()) {
		temp_queue.Dequeue(item);
		queue.Enqueue(item);
	}
}

int main() {
	QueType<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(5);
	queue.Enqueue(6);
	queue.Enqueue(2);
	queue.Enqueue(6);

	ReplaceItem<int> (queue, 6, 1);

	int item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << ' ';
	}
	return 0;
}