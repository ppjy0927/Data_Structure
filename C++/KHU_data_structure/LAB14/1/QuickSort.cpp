#include "QuickSort.h"

void Split(Student values[], int first, int last, int& splitPoint)
{
	Student splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do
	{
		onCorrectSide = true;
		// 비교 대상을 인덱스가 더 큰쪽으로 이동하며 학생들을 비교함
		while (onCorrectSide) 
		{
			if (strcmp(values[first].getName(), splitVal.getName()) > 0)
				onCorrectSide = false;
			else
			{
				first++;
				onCorrectSide = (first <= last);
			}
		}
		onCorrectSide = (first <= last);
		while (onCorrectSide)
		{
			if (strcmp(values[last].getName(), splitVal.getName()) <= 0)
				onCorrectSide = false;
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last)
		{
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);

	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}

void QuickSort(Student values[], int first, int last)
{
	if (first < last)
	{
		int splitPoint;
		Split(values, first, last, splitPoint);

		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);
	}
}