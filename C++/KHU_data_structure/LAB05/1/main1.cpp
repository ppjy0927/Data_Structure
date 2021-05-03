#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10;
	QueType queue;
	item1 = 1;
	item2 = 2;
	item3 = 3;
	item4 = 4;
	item5 = 5;
	item6 = 6;
	item7 = 7;
	item8 = 8;
	item9 = 9;
	item10 = 10;
	cout << "queue에 아이템을 넣기 전 아이템" << endl;
	cout << item1 << ' ' << item2 << ' ' << item3 << ' ' << item4 << ' ' << item5
		<< ' ' << item6 << ' ' << item7 << ' ' << item8 << ' ' << item9 << ' ' << item10 << endl;

	queue.Enqueue(item1);
	queue.Enqueue(item2);
	queue.Enqueue(item3);
	queue.Enqueue(item4);
	queue.Enqueue(item5);
	queue.Enqueue(item6);
	queue.Enqueue(item7);
	queue.Enqueue(item8);
	queue.Enqueue(item9);
	queue.Enqueue(item10);

	cout << "queue에 저장된 아이템" << endl;
	ItemType item;
	while (!queue.IsEmpty()) {
		queue.Dequeue(item);
		cout << item << ' ';
	}
	return 0;
}