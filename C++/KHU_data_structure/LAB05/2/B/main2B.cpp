#include <iostream>
#include "QueType.h"
using namespace std;

// b. 멤버 함수

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
	queue.ReplaceItem(6, 20);

	ItemType item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << ' ';
	}
	return 0;
}