#define _CRT_SECURE_NO_WARNINGS
#include "TextEditor.h"
#include <iostream>
using namespace std;

TextEditor::TextEditor()  // Class constructor
{
	// B. 클래스 생성자 구현
	LineType *header = new LineType;
	LineType *trailer = new LineType;

	strcpy(header->info, "---Top of file---");
	strcpy(trailer->info, "---Bottom of file---");

	header->next = trailer;
	trailer->back = header;
	header->back = NULL;
	trailer->next = NULL;

	currentLine = header;
	length = 0;
	listData = header;
}

TextEditor::~TextEditor()
// Class destructor
{
	MakeEmpty();
}

bool TextEditor::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	LineType* location;
	try
	{
		location = new LineType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int TextEditor::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

void TextEditor::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	LineType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


void TextEditor::InsertItem(ItemType* newline)
// item is in the list; length has been incremented.
{
	// E. InsertItem 함수 구현
	GoToBottom();

	LineType *location = new LineType;
	strcpy(location->info, newline);
	
	location->back = currentLine;
	location->next = currentLine->next;
	currentLine->next->back = location;
	currentLine->next = location;

	length++;
}



void TextEditor::ResetList()
// Post: Current position has been initialized.
{
	currentLine = listData;
}


void TextEditor::GetNextItem(ItemType* item)
// Post:  Current position has been updated; item is current item.
{
	if (currentLine == NULL)
		currentLine = listData;
	else
		currentLine = currentLine->next;

	for (int i = 0; currentLine->info[i] != '\0'; i++)
		item[i] = currentLine->info[i];
}

void TextEditor::GoToTop() {
	// C. GoToTop 함수 구현
	while (currentLine->back != NULL) {
		currentLine = currentLine->back;
	}
	currentLine = currentLine->next;
	// D. 함수가 O(1)이 되는 경우
	// currentLine->back == NULL인 경우, 즉 currentLine이 header를 가리키는 경우
}

void TextEditor::GoToBottom() {
	// C. GoToBottom 함수 구현
	while (currentLine->next != NULL) {
		currentLine = currentLine->next;
	}
	currentLine = currentLine->back;
	// D. 함수가 O(1)이 되는 경우
	// currentLine->next == NULL인 경우, 즉 currentLine이 trailer를 가리키는 경우
}