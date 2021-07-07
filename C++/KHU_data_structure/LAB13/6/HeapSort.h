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

	for (index = numValues / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);

	for (index = numValues - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}

template<class ItemType>
int  GetHeight(ItemType values[], int start, int numValues)
{
	// start�� leaf�̰ų� tree �ۿ� �ִ� ���
	if (start > (numValues - 1) || (start * 2 + 1) > numValues) return 0;
	int l_height = GetHeight(values, start * 2 + 1, numValues); // left subtree�� height
	int r_height = GetHeight(values, start * 2 + 2, numValues); // right subtree�� height
	return (l_height > r_height) ? l_height + 1 : r_height + 1; // ��subtree height �� ū �� + 1�� �� ����
}

template<class ItemType>
int GetHeightSum(ItemType values[], int numValues)
{
	int  index, sum = 0;
	// non-leaf ��忡 ���� �� ��带 ��Ʈ�� �ϴ� subtree�� height ���
	for (index = 0; index < numValues; index++)
		sum += GetHeight(values, index, numValues - 1);

	cout << "sum of heights = " << sum << endl;
	return sum;
}