#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
	StackType left_stack; // 커서 왼쪽에 있는 문자를 관리
	StackType right_stack; // 커서 오른쪽에 있는 문자를 관리

	char *input = new char[100];
	cin >> input; // 문자열 입력

	for (int i = 0; i < 100; i++) {
		char c = input[i];
		if (c == NULL)
			break;
		switch (c) {
		case '<':
			if (!left_stack.IsEmpty()) {
				ItemType item;
				item = left_stack.Top();
				left_stack.Pop();
				right_stack.Push(item);
			}
			break;
		case '>':
			if (!right_stack.IsEmpty()) {
				ItemType item;
				item = right_stack.Top();
				right_stack.Pop();
				left_stack.Push(item);
			}
			break;
		case '-':
			if (!left_stack.IsEmpty()) {
				left_stack.Pop();
			}
			break;
		default:
			ItemType item = c;
			left_stack.Push(c);
			break;
		}
	}

	while (!left_stack.IsEmpty()) {
		ItemType item;
		item = left_stack.Top();
		right_stack.Push(item);
		left_stack.Pop();
	}

	while (!right_stack.IsEmpty()) {
		ItemType item;
		item = right_stack.Top();
		cout << item;
		right_stack.Pop();
	}

	return 0;
}