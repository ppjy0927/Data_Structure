#include "HashTable.h"
#include "Student.h"

int main() {
	Student stu[100];

	stu[0].InitValue(2003200111, (char*)"a", 3.0);
	stu[1].InitValue(2004200121, (char*)"b", 3.2);
	stu[2].InitValue(2005200132, (char*)"c", 2.7);

	Student emptyItem;
	emptyItem.InitValue(0000000000, (char*)"empty", 0.0);
	HashTable<Student> ht(emptyItem);

	for (int i = 0; i < 3; i++)
		ht.InsertItem(stu[i]);
	
	bool found = false;
	ht.RetrieveItem(stu[0], found);
	if (found)
		cout << ht.Hash(stu[0].getName());
	return 0;
}