// Implementation file for Unsorted.h

#include <iostream>
#include "unsorted.h"
UnsortedType::UnsortedType()
{
  length = 0;
}

bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}

void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}

void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}

void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;

  info[location] = info[length - 1];
  length--;
}

void UnsortedType::DeleteItem_a(ItemType item) 
// Pre:  item's key has been initialized.
//	     At most one element in list has a key matching item's key.
// Post: If an element in list had a key matching item's key, the item has been removed.
//	     otherwise, the list is unchanged.
{
	bool deleted = false;
	int i = 0;
	for (i < 0; ((i < length) && !deleted); i++) {
		if (item.ComparedTo(info[i]) == EQUAL) {
			// 해당 아이템을 삭제
			info[i] = info[length - 1];
			length--;
			// deleted 플래그 값을 설정
			deleted = true;
		}
	}
}

void UnsortedType::DeleteItem_c(ItemType item) 
// Pre:  item's key has been initialized.
// Post: No element in list has a key matching item's key.
{
	int i = 0;
	while (i < length) {
		if (item.ComparedTo(info[i]) == EQUAL) {
			// 해당 아이템을 삭제
			info[i] = info[length - 1];
			// 삭제 후 현재 i 위치의 값이 변경되었으므로 나중에 다시 확인하도록 i 값 변경하지 않음. 추가로 length 값은 감소
			length--;
		}
		else {
			// 다음 아이템을 보기 위해서 i 값 변경
			i++;
		}
	}
}

void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

void UnsortedType::Print() {
	int i;
	for (i = 0; i < length; i++) {
		info[i].Print(std::cout);
	}
}

int main() { // 임의로 만든 테스트 코드입니다.
	UnsortedType info;
	ItemType a, b, c, d;
	a.Initialize(1);
	b.Initialize(2);
	c.Initialize(3);
	d.Initialize(1);
	info.InsertItem(a);
	info.InsertItem(b);
	info.InsertItem(c);
	info.InsertItem(d);
	info.Print(); // 1231 출력
	std::cout << std::endl;
	
	info.DeleteItem_a(b);
	info.Print(); // 113 출력
	std::cout << std::endl;

	info.DeleteItem_c(a);
	info.Print(); // 3 출력
	return 0;
}