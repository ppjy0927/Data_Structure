#include <iostream>
#include "SortedType.h"
using namespace std;

int main() {
	SortedType<int> list1;
	list1.InsertItem(1);
	list1.InsertItem(3);
	list1.InsertItem(2);
	list1.InsertItem(4);
	list1.InsertItem(2);

	list1.DeleteItem(2);

	int num;
	list1.ResetList();
	for (int i = 0; i < list1.LengthIs(); i++) {
		list1.GetNextItem(num);
		cout << num << " ";
	}
	return 0;
}