#include "MergeSortPointer.h"

void Merge(Student* values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	int arrSize = rightLast - leftFirst + 1;
	Student** tempArr = new Student*[arrSize];
	int i = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
	{
		if (strcmp(values[leftFirst]->getName(), values[rightFirst]->getName()) < 0)
		{
			tempArr[i] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			tempArr[i] = values[rightFirst];
			rightFirst++;
		}
		i++;
	}

	while (leftFirst <= leftLast)
	{
		tempArr[i] = values[leftFirst];
		leftFirst++;
		i++;
	}

	while (rightFirst <= rightLast)
	{
		tempArr[i] = values[rightFirst];
		rightFirst++;
		i++;
	}

	for (i = saveFirst; i <= rightLast; i++)
		values[i] = tempArr[i];
	delete[] tempArr;
}

void MergeSortPointer(Student* values[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSortPointer(values, first, middle);
		MergeSortPointer(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}