#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

void Print(ostream& out, Student stu[], int numelement)
{
	for(int i=0; i<numelement; i++)
	{
		stu[i].Print(out);
	}
}
void Student::Print(ostream& out)
{
	out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, char* _name, float _gpa)
{
	id = _id;
	strcpy(name,_name);
	gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
	strcpy(_name,name);
	_gpa = gpa;	
}
char* Student::getName()
{
	return name;
}

void Student::operator = (Student stu)
{
	id = stu.id;
	strcpy(name,stu.name);
	gpa = stu.gpa;
}

bool Student::operator == (Student stu)
{
	return (strcmp(name, stu.name) == 0);
}

bool Student::operator != (Student stu) 
{
	return !(strcmp(name, stu.name) == 0);
}

char* Student::Key()
{
	return name;
}

Student Student::EmptyKey()
{
	Student emptyStu;

	emptyStu.id = 0000000000;
	strcpy_s(emptyStu.name, sizeof(emptyStu.name), "None");
	emptyStu.gpa = 0.0;

	return emptyStu;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
	for(int i=0; i<numValues; i++)
	{
		(*values[i]).Print(out);
	}
}