#include <iostream>
#include "QueType.h"
using namespace std;

int main() {
	QueType queue(5);
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

	cout << queue.IsFull();

	return 0;
}