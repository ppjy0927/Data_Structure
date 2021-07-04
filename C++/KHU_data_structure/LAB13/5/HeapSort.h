#pragma once
#include <iostream>
using namespace std;

template<class ItemType>
void Swap(ItemType& item1, ItemType& item2)
{
	ItemType tempItem;

	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}

template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			ReheapDown(elements, maxChild, bottom);
		}
	}
}

template<class ItemType>
void HeapSort(ItemType values[], int numValues)
{
	int index;

	cout << "배열 입력을 출력하시오." << endl;
	for (int i = 0; i < numValues; i++)
		cout << values[i] << " ";
	cout << endl << endl;

	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);
	
	cout << "Heap으로 변경된 배열을 출력하시오." << endl;
	for (int i = 0; i < numValues; i++)
		cout << values[i] << " ";
	cout << endl << endl;

	for (index = numValues - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
		cout << "변경된 배열을 출력하시오." << endl;
		for (int i = 0; i < numValues; i++)
			cout << values[i] << " ";
		cout << endl << endl;
	}
}