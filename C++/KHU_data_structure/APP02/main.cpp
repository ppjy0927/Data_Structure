#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
#include "sorted.h"
using namespace std;

int main() {
	int n;
	cout << "N(10 ������ �ڿ���) : ";
	cin >> n;

	UnsortedType A;
	cout << "����Ʈ A�� �� ����(10������ �ڿ���) N�� : ";
	for (int i = 0; i < n; i++) {
		ItemType item;
		int num[10];
		cin >> num[i];
		item.Initialize(num[i]);
		A.InsertItem(item);
	}
	
	UnsortedType B;
	cout << "����Ʈ B�� �� ����(10������ �ڿ���) N�� : ";
	for (int i = 0; i < n; i++) {
		ItemType item;
		int num[10];
		cin >> num[i];
		item.Initialize(num[i]);
		B.InsertItem(item);
	}

	SortedType C;
	A.ResetList();
	B.ResetList();
	for (int i = 0; i < n; i++) {
		ItemType item1, item2, item3;
		A.GetNextItem(item1);
		B.GetNextItem(item2);
		int num;
		num = item1.getVal() + item2.getVal();
		item3.Initialize(num);
		C.InsertItem(item3);
	}
	C.Print();

	return 0;
}