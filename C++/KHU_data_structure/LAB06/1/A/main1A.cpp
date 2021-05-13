#include <iostream>
#include "StackType.h"
using namespace std;

void ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem);

int main() {
	StackType stack;
	stack.Push(3);
	stack.Push(5);
	stack.Push(6);
	stack.Push(2);
	stack.Push(6);
	ReplaceItem(stack, 6, 1);

	while (!stack.IsEmpty()) {
		cout << stack.Top() << ' ';
		stack.Pop();
	}
	return 0;
}

void ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem) {
	StackType temp_stack; // 백업용 스택
	ItemType temp_Item; // top을 받는 ItemType

	while (!stack.IsEmpty()) {
		temp_Item = stack.Top();
		stack.Pop();
		if (temp_Item == oldItem) {
			temp_stack.Push(newItem);
		}
		else {
			temp_stack.Push(temp_Item);
		}

	}
	while (!temp_stack.IsEmpty()) {
		temp_Item = temp_stack.Top();
		temp_stack.Pop();
		stack.Push(temp_Item);
	}
}