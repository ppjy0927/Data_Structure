#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
	StackType stack1, stack2;
	stack1.Push('Z');
	stack1.Push('Y');
	stack1.Push('X');
	
	stack1.Copy(stack2);

	ItemType item;
	while (!stack2.IsEmpty()) {
		item = stack2.Top();
		cout << item << ' ';
		stack2.Pop();
	}

	return 0;
}