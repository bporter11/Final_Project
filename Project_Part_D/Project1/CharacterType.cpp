/*
	Litcode
	Porter, Brian (TTh 2:20)
	Vu, Gia Thuan(TTh 2:20)
	Vy, Mai (TTh 2:20)
	Do, Kenny (TTh 2:20)
	Cao, Song (TTh 2:20)

	May 16th, 2020

	CS A250
	Project 2 STL LIST
*/

#include <string>
#include <iostream>
#include "CharacterType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

CharacterType::CharacterType() 
	: id(0)
	  ,firstName("no first name yet")
	  ,lastName("no last name yet")
{}

CharacterType::CharacterType(const string &newFirstName, 
					const string &newLastName, int newID)
	: id(newID), firstName(newFirstName), lastName(newLastName)
{}

void CharacterType::setCharacterInfo(const string& newFirstName,
	const string& newLastName, int newID)
{
	firstName = newFirstName;
	lastName = newLastName;
	id = newID;

}

string CharacterType::getFirstName() const
{
	return firstName;
}

string CharacterType::getLastName() const
{
	return lastName;
}

int CharacterType::getID() const
{
	return id;
}

void CharacterType::printName() const
{
	cout << lastName << ", " << firstName;
}

void CharacterType::printCharacterInfo() const
{
	printID();
	cout << " " << firstName << " " << lastName;
}

void CharacterType::printID() const
{
	cout << "ID# " << id;
}


CharacterType::~CharacterType() {}