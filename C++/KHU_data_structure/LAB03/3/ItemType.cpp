// ItemType.cpp is the implementation file for data for the real 
//  estate manipulation program.

#include "ItemType.h"

void HouseType::GetFromFile(std::ifstream& file)
{
	lastName.GetStringFile(true, NOT_NEW, file);
	firstName.GetStringFile(true, NOT_NEW, file);
	address.GetStringFile(true, NOT_NEW, file);
	file >> price >> squareFeet >> bedRooms >> bathrooms;
}

void HouseType::WriteToFile(std::ofstream& file)
{
	using std::endl;
	lastName.PrintToFile(false, file);
	firstName.PrintToFile(true, file);
	address.PrintToFile(true, file);
	file << endl << price << endl;
	file << squareFeet << endl;
	file << bedRooms << endl;
	file << bathrooms << endl;
}

void HouseType::GetFromUser()
{
	using namespace std;
	cout << "Enter last name; press return." << endl;
	lastName.GetString(true, NOT_NEW);
	cout << "Enter first name; press return." << endl;
	firstName.GetString(true, NOT_NEW);
	cout << "Enter address; press return." << endl;
	address.GetString(true, NOT_NEW);
	cout << "Enter price, square feet, number of bedrooms, number of bedrooms;" << " press return." << endl;
	cin >> price >> squareFeet >> bedRooms >> bathrooms;
}

void HouseType::PrintHouseToScreen()
{
	using namespace std;
	firstName.PrintToScreen(false);
	cout << " ";
	lastName.PrintToScreen(false);
	address.PrintToScreen(true);
	cout << endl << "Price: " << price << endl;
	cout << "Square Feet: " << squareFeet << endl;
	cout << "Bedrooms: " << bedRooms << endl;
	cout << "Bathrooms: " << bathrooms << endl;
}

void HouseType::GetNameFromUser()
{
	using namespace std;
	cout << "Enter last name;  press return." << endl;
	lastName.GetString(true, NOT_NEW);
	cout << "Enter first name;  press return." << endl;
	firstName.GetString(true, NOT_NEW);
}

void HouseType::PrintNameToScreen()
{
	using namespace std;
	firstName.PrintToScreen(false);
	cout << " ";
	lastName.PrintToScreen(false);
	cout << endl;
}

/*
RelationType HouseType::ComparedTo(HouseType house)
{
	if (lastName < house.lastName)
		return LESS;
	else if (house.lastName < lastName)
		return GREATER;
	else if (firstName < house.firstName)
		return LESS;
	else if (house.firstName < firstName)
		return GREATER;
	else return EQUAL;
}
*/

RelationType HouseType::ComparedTo(HouseType house)
{
	if (*this == house)
		return EQUAL;
	else if (*this < house)
		return LESS;
	else
		return GREATER;
}


bool HouseType::operator<(const HouseType& other) {
	bool less;
	less = (lastName < other.lastName) or (firstName < other.firstName);

	if (less)
		return true;
	else
		return false;
}

bool HouseType::operator==(const HouseType& other) {
	bool equal;
	equal = (lastName == other.lastName) or (firstName == other.firstName);
	if (equal)
		return true;
	else
		return false;
}