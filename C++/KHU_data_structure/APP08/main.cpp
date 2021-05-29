#include <iostream>
#include "QueType.h"
#include "TreeType.h"
using namespace std;

int main() {
	int N;
	cin >> N;

	TreeType tree;
	ItemType M;
	for (int i = 0; i < N; i++) {
		cin >> M;
		tree.InsertItem(M);
	}

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		tree.DeleteMinNode();
	}
	cout << tree.LeafCount();

	return 0;
}