#include <iostream>
#include "TreeType.h"
#include "SortedType.h"
using namespace std;

void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int> &list);

int main() {
	SortedType<int> list;
	TreeType tree;
	ofstream result("result.txt");
	for (int i = 1; i <= 7; i++) {
		list.InsertItem(i);
	}
	MakeTree(tree, list);
	tree.Print(result);
	result.close();
}

void MakeTree(TreeType& tree, SortedType<int> &list)
{
	int length = list.LengthIs();
	int *array = new int[length];
	int item_info;
	int i;

	list.ResetList();

	for (i = 0; i < length; i++)
	{
		list.GetNextItem(item_info);
		array[i] = item_info;
	}
	AddElement(tree, array, 0, length - 1);
	delete[] array;
}

void AddElement(TreeType& tree, int Array[], int from, int to)
{
	int mid;
	if (from > to) {
		mid = (from + to) / 2;
		tree.InsertItem(Array[mid]);
		AddElement(tree, Array, mid + 1, to);
		AddElement(tree, Array, from, mid - 1);
	}
}