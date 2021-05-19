#include <iostream>
#include "SortedType.h"
using namespace std;

int main() {
	SortedType<int> list1, list2, result;
	list1.InsertItem(5);
	list1.InsertItem(3);
	list1.InsertItem(7);
	list1.InsertItem(1);
	list1.InsertItem(9);

	list2.InsertItem(8);
	list2.InsertItem(10);
	list2.InsertItem(2);
	list2.InsertItem(4);
	list2.InsertItem(6);

	list1.MergeLists(list2, result);

	int num;
	result.ResetList();
	for (int i = 0; i < result.LengthIs(); i++) {
		result.GetNextItem(num);
		cout << num << " ";
	}
	return 0;
}