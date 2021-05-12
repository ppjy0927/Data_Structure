#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
	QueType queue;
	ItemType item1, item2, item3, item4, item5, item6;
	item1 = 5;
	item2 = 4;
	item3 = 2;
	item4 = 3;
	item5 = 1;
	item6 = 8;

	queue.Enqueue(item1);
	queue.Enqueue(item2);
	queue.Enqueue(item3);
	queue.Enqueue(item4);
	queue.Enqueue(item5);
	queue.Enqueue(item6);
	cout << item1 << ' ' << item2 << ' ' << item3 << ' ' << item4 << ' ' << item5 << ' ' << item6 << endl;

	queue.MinDequeue(item5);
	ItemType item7 = 6;
	queue.Enqueue(item7);
	
	ItemType item;
	int i = 1;
	while (i < 7) {
		queue.Dequeue(item);
		cout << item << ' ';
		i++;
	}
	
	return 0;
}