#include <iostream>
#include "ItemType.h"
#include "unsorted.h"
#include "sorted.h"
using namespace std;

int main() {
	int n;
	cout << "N(10 이하의 자연수) : ";
	cin >> n;

	UnsortedType A;
	cout << "리스트 A에 들어갈 숫자(10이하의 자연수) N개 : ";
	for (int i = 0; i < n; i++) {
		ItemType item;
		int num[10];
		cin >> num[i];
		item.Initialize(num[i]);
		A.InsertItem(item);
	}
	
	UnsortedType B;
	cout << "리스트 B에 들어갈 숫자(10이하의 자연수) N개 : ";
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