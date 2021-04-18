#define _CRT_SECURE_NO_WARNINGS
#include "TextEditor.h"
#include <iostream>
using namespace std;

TextEditor::TextEditor()  // Class constructor
{
	// B. Ŭ���� ������ ����
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
	// E. InsertItem �Լ� ����
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
	// C. GoToTop �Լ� ����
	while (currentLine->back != NULL) {
		currentLine = currentLine->back;
	}
	currentLine = currentLine->next;
	// D. �Լ��� O(1)�� �Ǵ� ���
	// currentLine->back == NULL�� ���, �� currentLine�� header�� ����Ű�� ���
}

void TextEditor::GoToBottom() {
	// C. GoToBottom �Լ� ����
	while (currentLine->next != NULL) {
		currentLine = currentLine->next;
	}
	currentLine = currentLine->back;
	// D. �Լ��� O(1)�� �Ǵ� ���
	// currentLine->next == NULL�� ���, �� currentLine�� trailer�� ����Ű�� ���
}