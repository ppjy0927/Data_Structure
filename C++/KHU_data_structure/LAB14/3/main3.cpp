#include <iostream>
#include "Student.h"
#include "MergeSortPointer.h"
#include "QuickSortPointer.h"
using namespace std;

int main()
{
	Student stu[3];
	stu[0].InitValue(2003200111, (char*)"ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, (char*)"±Ç¿ÀÁØ", 3.2);
	stu[2].InitValue(2005200132, (char*)"±èÁøÀÏ", 2.7);
	Student* stuPtrs1[3];
	Student* stuPtrs2[3];

	for (int k = 0; k < 3; k++) {
		stuPtrs1[k] = &stu[k];
		stuPtrs2[k] = &stu[k];
	}

	QuickSortPointer(stuPtrs1, 0, 2);
	MergeSortPointer(stuPtrs2, 0, 2);

	PrintByPointer(cout, stuPtrs1, 3);
	cout << endl;
	PrintByPointer(cout, stuPtrs2, 3);

	return 0;
}