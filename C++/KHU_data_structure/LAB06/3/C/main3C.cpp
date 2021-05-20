#include <iostream>
#include "UnsortedType.h"
using namespace std;

template <class ItemType>
void MergeLists(UnsortedType<ItemType> &l_a, UnsortedType<ItemType> &l_b, UnsortedType<ItemType> &result) {
	ItemType temp;
	l_a.ResetList();
	for (int i = 0; i < l_a.LengthIs(); i++) {
		l_a.GetNextItem(temp);
		result.InsertItem(temp);
	}
	l_b.ResetList();
	for (int i = 0; i < l_b.LengthIs(); i++) {
		l_b.GetNextItem(temp);
		result.InsertItem(temp);
	}
}

int main() {
	UnsortedType<int> list1, list2, result;
	list1.InsertItem(1);
	list1.InsertItem(6);
	list1.InsertItem(5);
	list1.InsertItem(2);
	list1.InsertItem(3);

	list2.InsertItem(10);
	list2.InsertItem(8);
	list2.InsertItem(9);
	list2.InsertItem(4);
	list2.InsertItem(7);

	MergeLists(list1, list2, result);

	int num;
	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(num);
		cout << num << " ";
	}
	return 0;
}