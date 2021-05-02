#include <iostream>
#include "doublestack.h"

class FullStack {};
// Exception class thrown by Push when stack is full.

doublestack::doublestack()
{
	top_small = -1;
	top_big = MAX_ITEMS;
}

bool doublestack::IsFull() const
{
	return (top_small + 1 == top_big);
}

void doublestack::Push(int item)
{
	if (IsFull())
		throw FullStack();
	if (item <= 1000) {
		top_small++;
		items[top_small] = item;
	}
	else {
		top_big--;
		items[top_big] = item;
	}
}

void doublestack::Print()
{
	std::cout << "1000 이하 스택" << std::endl;
	for (int i = top_small; i > 0; i--) {
		std::cout << items[i] << " ";
	}

	std::cout << std::endl << std::endl;
	std::cout << "1000 초과 스택" << std::endl;
	for (int i = top_big; i < MAX_ITEMS; i++) {
		std::cout << items[i] << " ";
	}
}