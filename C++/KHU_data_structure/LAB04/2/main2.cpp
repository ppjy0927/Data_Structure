#include <iostream>
#include "MaxItem.h"
#include "StackTType.h"
using namespace std;

template<class ItemType>
void inverseStack(StackType<ItemType> &stack1, StackType<ItemType> &stack2) {
	while (!stack1.IsEmpty())
	{
		int result = stack1.Top();
		stack1.Pop();
		stack2.Push(result);
	}
}

template<class ItemType>
void stackPrint(StackType<ItemType> stack) {
	while (!stack.IsEmpty()) {
		int result = stack.Top();
		stack.Pop();
		cout << result << endl;
	}
}

int main() {
	StackType<int> stackA, stackB, stackC;
	stackA.Push(9);
	stackA.Push(8);
	stackA.Push(4);
	stackA.Push(7);
	stackA.Push(5);
	stackA.Push(3);

	cout << "stack A 최근에 넣은 값부터 출력" << endl;
	stackPrint(stackA);

	inverseStack(stackA, stackC);
	inverseStack(stackC, stackB);
	
	cout << "stack B 최근에 넣은 값부터 출력" << endl;
	stackPrint(stackB);
}