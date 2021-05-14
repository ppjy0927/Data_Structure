#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
	StackType stack;
	stack.Push(3);
	stack.Push(5);
	stack.Push(6);
	stack.Push(2);
	stack.Push(6);
	stack.ReplaceItem(6, 1);

	while (!stack.IsEmpty()) {
		cout << stack.Top() << ' ';
		stack.Pop();
	}
	return 0;
}