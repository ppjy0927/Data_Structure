#include "SelectionSort.h"

int MinIndex(Student values[], int startIndex, int endIndex)
{
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++)
	{
		if (strcmp(values[index].getName(), values[indexOfMin].getName()) < 0)
			indexOfMin = index;
	}
	return indexOfMin;
}

void SelectionSort(Student ary[], int numElems)
{
	int endIndex = numElems - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(ary[current], ary[MinIndex(ary, current, endIndex)]);
}