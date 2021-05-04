#include <iostream>
#include "QueType.h"
using namespace std;

// a. 클라이언트 함수
void ReplaceItem(QueType& queue, int oldItem, int newItem);

int main() {
	QueType queue;
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9;
	item1 = 2;
	item2 = 6;
	item3 = 7;
	item4 = 4;
	item5 = 5;
	item6 = 6;
	item7 = 10;
	item8 = 15;
	item9 = 6;
	queue.Enqueue(item1);
	queue.Enqueue(item2);
	queue.Enqueue(item3);
	queue.Enqueue(item4);
	queue.Enqueue(item5);
	queue.Enqueue(item6);
	queue.Enqueue(item7);
	queue.Enqueue(item8);
	queue.Enqueue(item9);
	cout << "변경 전 queue" << endl;
	cout << item1 << ' ' << item2 << ' ' << item3 << ' ' << item4 << ' ' << item5 << ' '
		<< item6 << ' ' << item7 << ' ' << item8 << ' ' << item9 << endl;
	cout << "변경 후 queue" << endl;
	ReplaceItem(queue, 6, 20);
	
	ItemType item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << ' ';
	}
	return 0;
}

void ReplaceItem(QueType& queue, int oldItem, int newItem) {
	QueType temp;
	ItemType temp_item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(temp_item);
		if (oldItem == temp_item)
			temp.Enqueue(newItem);
		else
			temp.Enqueue(temp_item);
	}
	while (!temp.IsEmpty()) {
		temp.Dequeue(temp_item);
		queue.Enqueue(temp_item);
	}
}