#pragma once
class FullPQLL {};
class EmptyPQLL {};
#include "Heap.h"
#include "SortedType.h"
template<class ItemType>
class PQLLType
{
public:
	PQLLType();
	~PQLLType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void Print();
private:
	int length;
	SortedType<ItemType> linkedlist;
	//int maxItems;
};

template<class ItemType>
PQLLType<ItemType>::PQLLType()
{
	length = linkedList.LengthIs();
}

template<class ItemType>
void PQLLType<ItemType>::MakeEmpty()
{
	length = 0;
}

template<class ItemType>
PQLLType<ItemType>::~PQLLType()
{
	linkedList.MakeEmpty();
}

template<class ItemType>
bool PQLLType<ItemType>::IsEmpty() const
{
	return length == 0;
}

template<class ItemType>
bool PQLLType<ItemType>::IsFull() const 
{
	return linkedList.IsFull();
}


template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem);
	}
}

template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedList.ResetList();
		linkedList.GetNextItem(item);
		linkedList.DeleteItem(item);
		length--;
	}
}