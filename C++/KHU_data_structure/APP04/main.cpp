#include <iostream>
#include "ItemType.h"
#include "StackType.h"
using namespace std;

int main() {
	StackType stack;
	ItemType newitem, lastitem, item;
	int N, h, max;
	int count = 1;
	cout << "������� ���� N (2 <= N <= 100): ";
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cout << i << "��° ������� ���� h (1 <= h <= 100): ";
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
	cout << "���̴� ������� ����: " << count;
	return 0;
}