#include <iostream>
#include "QueType.h"
using namespace std;

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max;
  front = 0;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  minimum_pos = maxQue - 1;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 500;
  front = 0;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  minimum_pos = maxQue - 1;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = 0;
  rear = maxQue - 1;
  minimum_pos = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (Length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (Length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
	bool space_exist = false;
	int new_index;
	if (IsFull())
		throw FullQueue();
	else if (IsEmpty()) {
		rear = (rear + 1) % maxQue;
		items[rear] = newItem;
		Length++;
		minimum_pos = rear;
	}
	else {
		for (int i = front; i <= rear; i = (i + 1) % maxQue) {
			if (items[i] == -1) {
				items[i] = newItem;
				new_index = i;
				space_exist = true;
				break;
			}
		}

		if (space_exist == false) {
			rear = (rear + 1) % maxQue;
			items[rear] = newItem;
			Length++;
			new_index = rear;
		}

		if (items[new_index] < items[minimum_pos])
			minimum_pos = new_index;
	}
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
	item = items[front];
    front = (front + 1) % maxQue;
	Length--;
  }
}

void QueType::MinDequeue(ItemType& item) {
	item = items[minimum_pos];
	ItemType temp = -1;
	items[minimum_pos] = temp;
	
	minimum_pos = front;

	for (int i = front; i <= rear; i = (i + 1) % maxQue) {
		if (items[front] == -1) {
			if (minimum_pos != 5) {
				minimum_pos++;
			}
		}
		if (items[minimum_pos] > items[i] && items[i] > 0) {
			minimum_pos = i;
		}
	}
}