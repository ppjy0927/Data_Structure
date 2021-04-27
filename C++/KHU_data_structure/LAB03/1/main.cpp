#include <iostream>
#include "ItemType.h"
#include "sorted.h"
using namespace std;


// �Լ� : 2���� ���� ����Ʈ�� Merge�ؼ� �� ��° ���� ����Ʈ�� �����.
// ���� : list1�� list2�� �ʱ�ȭ�Ǿ� �ְ� ComparedTo��� �Լ��� ����ؼ� Ű�� ���� ���ĵǾ� �ִ�.
//		  list1�� list2�� ���� Ű�� ���� �ʴ´�.
// ��� : ����� list1�� list2�� ��� ��Ҹ� ���� ���� ����Ʈ�̴�.
void MergeList(SortedType list1, SortedType list2, SortedType& result);


int main() {
	SortedType s_list1, s_list2, s_list3; // ����Ʈ ����
	ItemType item1, item2, item3, item4, item5, item6, item7, item8, item9, item10; // �ʿ��� ��ŭ ����
	
	item1.Initialize(1); // item�� �ʿ��� ��ŭ �ʱ�ȭ
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	item6.Initialize(6);
	item7.Initialize(7);
	item8.Initialize(8);
	item9.Initialize(9);
	item10.Initialize(11);
	
	s_list1.InsertItem(item3); // ����Ʈ�� ���� �ִ´�.
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
	// ����Ʈ�� current position�� �ʱ�ȭ�Ѵ�.
	list1.ResetList();
	list2.ResetList();
	result.ResetList();
	// list1�� list2�� ���̸� Lengthls()�Լ��� ���� ��´�.
	int length1 = list1.LengthIs();
	int length2 = list2.LengthIs();
	// ���� ����Ʈ�̹Ƿ� InsertItem(...)�Լ��� �����ϴ� ����� �ִ�.
	// ���� list1�� ���̸�ŭ �ݺ��Ͽ� GetNextItem(...)�� item�� �޾� result�� �ִ´�.
	int i1 = 0;
	int i2 = 0;
	ItemType item1, item2;
	while (i1 < length1) {
		list1.GetNextItem(item1);
		result.InsertItem(item1);
		i1++;
	}
	// list2 ���� ���̸�ŭ ������ ���� GetNextItem(...)�� item�� ���, result�� �ִ´�.
	while (i2 < length2) {
		list2.GetNextItem(item2);
		result.InsertItem(item2);
		i2++;
	}
}

////////////////////////////////////////////////////////////////////////////////
// b. Big-O ǥ������� �˰����� ǥ���Ͽ���.									  //
// MergeList �Լ��� ���� ������ ����Ʈ�� Sorted List�̱� ������					  //
// �ֵ� ������ InsertItem�� ���� �̷�����Ƿ� O(N)���� ��Ÿ�� �� �ִ�.			  //
////////////////////////////////////////////////////////////////////////////////