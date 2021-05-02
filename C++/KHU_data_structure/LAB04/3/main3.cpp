#include <iostream>
#include "doublestack.h"
using namespace std;

int main() {
	doublestack stack;
	
	for (int i = 0; i < 100; i++) {
		stack.Push(i);
	}
	for (int i = 1000; i < 1100; i++) {
		stack.Push(i);
	}

	stack.Print();
	return 0;
}