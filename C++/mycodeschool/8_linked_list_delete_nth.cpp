#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

struct Node* head; // global
void Insert(int data); // insert an integer at end of list
void Print(); // print all elements in the list
void Delete(int n); // Delete node at position n

int main() {
	head = NULL; // empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); // List : 2, 4, 6, 5
	Print();
	int n;
	cout << "Enter a position" << endl;
	cin >> n;
	Delete(n);
	Print();
}

// Delete node at position n
void Delete(int n) {
	Node* temp1 = head; 
	if (n == 1) {
		// temp1은 1번째 node를 지우기 위해 1번째의 주소값을 임시로 가지고 있는 변수
		head = temp1->next; // head가 2번째 node를 가리키게 됨. head와 1번째 node의 링크는 사라짐.
		delete temp1; // 1번째 node 지우기
		return; // 뒷부분을 실행하면 안 되니까
	}

	// n != 1 일 때
	// temp1은 지우기를 원하는 n번째 node의 이전 node(n-1번째)의 주소값을 임시로 가지는 변수
	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next; // temp1은 (n-1)번째 node를 가리킴.
	Node* temp2 = temp1->next; // temp2는 n번째 node를 가리킴.
	temp1->next = temp2->next; // (n-1)번째 node가 이제 n번째가 아닌 (n+1)번째 node의 주소값을 가리키게 됨.
	delete temp2; // n번째 node 지우기
}

void Insert(int data) {
	Node* temp = new Node(); // 새로 생성하는 노드의 주소값 저장
	temp->data = data;
	temp->next = head;
	head = temp;
}

void Print() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}