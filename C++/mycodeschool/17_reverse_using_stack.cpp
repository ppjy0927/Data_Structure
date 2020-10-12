// string reversal using stack
#include <iostream>
#include <stack> // stack from standard template library (STL)
using namespace std;

class Stack {
private:
	char A[101];
	int top; // 스택의 맨 위
public:
	void Push(int X);
	void Pop();
	int Top();
	bool IsEmpty();
};

//void Reverse(char C[], int n) {
//	stack<char> S;
//	// loop for push
//	for (int i = 0; i < n; i++) {
//		S.push(C[i]);
//	}
//	// loop for pop
//	for (int i = 0; i < n; i++) {
//		C[i] = S.top(); // overwrite the character at index i
//		S.pop(); // perform pop;
//	}
//}

void Reverse() {
	if (head == null) return;
	stack<Node*> S;
	Node* temp = head;
	while (temp != NULL) {
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty()) {
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = NULL;
}

int main() {
	char C[51];
	cout << "Enter a string: ";
	cin >> C;
	Reverse(C, strlen(C));
	cout << "Output = " << C;
}