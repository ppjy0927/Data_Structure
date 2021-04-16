#include <iostream>
#include "SortedType.h"
using namespace std;

int main() {
	SortedType<char> char_list;
	char_list.InsertItem('X');
	char_list.InsertItem('Y');
	char_list.InsertItem('Z');

	char_list.PrintReverse();
	return 0;
}