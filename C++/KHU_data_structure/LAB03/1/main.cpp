#include <iostream>
#include "ItemType.h"
#include "sorted.h"
using namespace std;


// 함수 : 2개의 정렬 리스트를 Merge해서 세 번째 정렬 리스트를 만든다.
// 조건 : list1과 list2는 초기화되어 있고 ComparedTo라는 함수를 사용해서 키에 의해 정렬되어 있다.
//		  list1과 list2는 같은 키를 갖지 않는다.
// 결과 : 결과는 list1과 list2의 모든 요소를 가진 정렬 리스트이다.
void MergeList(SortedType list1, SortedType list2, SortedType& result);


int main() {
	SortedType s_list1, s_list2, s_list3; // 리스트 선언
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10; // 필요한 만큼 선언
	
	item1.Initialize(1); // item을 필요한 만큼 초기화
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	item6.Initialize(6);
	item7.Initialize(7);
	item8.Initialize(8);
	item9.Initialize(9);
	item10.Initialize(11);
	
	s_list1.InsertItem(item3); // 리스트에 값을 넣는다.
	s_list1.InsertItem(item5);
	s_list1.InsertItem(item6);
	s_list1.InsertItem(item8);
	s_list1.InsertItem(item9);
	s_list2.InsertItem(item1);
	s_list2.InsertItem(item2);
	s_list2.InsertItem(item4);
	s_list2.InsertItem(item7);
	s_list2.InsertItem(item10);
	
	MergeList(s_list1, s_list2, s_list3);
	s_list1.Print();
	cout << endl;
	s_list2.Print();
	cout << endl;
	s_list3.Print();
	return 0;
}


void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	// 리스트의 current position을 초기화한다.
	list1.ResetList();
	list2.ResetList();
	result.ResetList();
	// list1과 list2의 길이를 Lengthls()함수를 통해 얻는다.
	int length1 = list1.LengthIs();
	int length2 = list2.LengthIs();
	// 정렬 리스트이므로 InsertItem(...)함수에 정렬하는 기능이 있다.
	// 따라서 list1의 길이만큼 반복하여 GetNextItem(...)로 item을 받아 result에 넣는다.
	int i1 = 0;
	int i2 = 0;
	ItemType item1, item2;
	while (i1 < length1) {
		list1.GetNextItem(item1);
		result.InsertItem(item1);
		i1++;
	}
	// list2 역시 길이만큼 루프를 돌며 GetNextItem(...)로 item을 얻고, result에 넣는다.
	while (i2 < length2) {
		list2.GetNextItem(item2);
		result.InsertItem(item2);
		i2++;
	}
}

////////////////////////////////////////////////////////////////////////////////
// b. Big-O 표기법으로 알고리즘을 표현하여라.									  //
// MergeList 함수를 통해 합쳐진 리스트도 Sorted List이기 때문에					  //
// 주된 연산은 InsertItem을 통해 이루어지므로 O(N)으로 나타낼 수 있다.			  //
////////////////////////////////////////////////////////////////////////////////