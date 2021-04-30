#include <iostream>
#include "MaxItem.h"
#include "StackTType.h"
using namespace std;

int main() {
	StackType<int> stack;
	stack.Push(1); // 1�� ���ÿ� �ִ´�.
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6); // �������� ���ÿ� ���� �ִ´�.
	while (!stack.IsEmpty()) // ���ÿ� ���Ұ� ���� ������ �ݺ��Ѵ�
	{
		int result = stack.Top(); // ���� �ֱٿ� ���� ������ ���� ������
		stack.Pop(); // ���� �ֱٿ� ���� �������� ����
		cout << result << endl;
	}
}