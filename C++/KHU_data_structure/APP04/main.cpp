#include <iostream>
#include "ItemType.h"
#include "StackType.h"
using namespace std;

int main() {
	StackType stack;
	ItemType newitem, lastitem, item;
	int N, h, max;
	int count = 1;
	cout << "막대기의 개수 N (2 <= N <= 100): ";
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cout << i << "번째 막대기의 높이 h (1 <= h <= 100): ";
		cin >> h;
		newitem = h;
		stack.Push(newitem);
	}
	
	lastitem = stack.Top();
	stack.Pop();
	max = lastitem;

	while (!stack.IsEmpty()) {
		item = stack.Top();
		if (lastitem < item && max < item) {
			count++;
		}
		if (max < item) {
			max = item;
		}
		stack.Pop();
	}
	cout << "보이는 막대기의 개수: " << count;
	return 0;
}