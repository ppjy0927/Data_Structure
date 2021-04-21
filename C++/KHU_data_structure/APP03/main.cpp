#include <iostream>
#include "sorted.h"
#include "ItemType.h"
using namespace std;

int main()
{
	SortedType list1;
	int N;
	cout << "Input N: ";
	cin >> N;
	cout << "Input list Item: ";
	for (int i = 0; i < N; i++)
	{
		//list1에 Item 삽입
		ItemType item;
		int num[10];
		cin >> num[i];
		item.Initialize(num[i]);
		list1.InsertItem(item);
	}
	cout << endl;
	while (1)
	{
		int X;
		cout << "Input X: ";
		cin >> X;
		if (X == 0)
		{
			//list1의 모든 요소 출력
			list1.Print();
			break;
		}
		int Y;
		cout << "Input Y: ";
		cin >> Y;
		//list1에 X가 존재하는지 찾고 존재하면 Y로 바꾸기
		//위 연산이 실행된 뒤 list1은 정렬된 상태여야 함
		ItemType item1, item2;
		item1.Initialize(X);
		item2.Initialize(Y);
		bool found = false;
		list1.RetrieveItem(item1, found);
		if (found == true) {
			list1.DeleteItem(item1);
			list1.InsertItem(item2);
		}
		cout << "Operation completed." << endl << endl;
	}
	return 0;
}