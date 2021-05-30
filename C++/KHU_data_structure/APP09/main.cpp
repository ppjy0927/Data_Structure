#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "TreeType.h"
using namespace std;

int main() {
	TreeType tree;
	QueType queue, temp_queue;
	char item;

	char bst[100]; 
	cin.getline(bst, 100);
	char *ptr = strtok(bst, " ");
	while (ptr != NULL) {
		tree.InsertItem(*ptr);
		while (*ptr != '-1' && !queue.IsEmpty()) {
			queue.Dequeue(item);
			if (*ptr == item) 
				tree.DeleteItem(*ptr);
		}
		temp_queue.Enqueue(*ptr);
		queue = temp_queue;

		if (*ptr == '-1')
			tree.LeafDelete();
		ptr = strtok(NULL, " ");
	}

	cout << tree.LeafCount();
	return 0;
}