#include <iostream>
#include "QueType.h"
using namespace std;

// b. 멤버함수로 작성

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

	cout << "큐에 저장된 아이템 수: " << queue.Length();

	return 0;
}