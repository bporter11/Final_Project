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

#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

class CharacterType
{
public:
	// Default constructor
	CharacterType();		
	// Overloaded constructor
	CharacterType(const std::string &newFirstName,
		const std::string &newLastName, int newID);

	// setCharacterInfo
	void setCharacterInfo(const std::string& newFirstName,
		const std::string& newLastName, int newID);

	// getFirstName
	std::string getFirstName() const;
	// getLastName
	std::string getLastName() const;
	// getID
	int getID() const;

	// printName
	void printName() const;
	// printCharacterInfo
	void printCharacterInfo() const;
	// printID
	void printID() const;

	// Destructor
	~CharacterType();

private:
	std::string firstName;	
	std::string lastName;	
	int id;					
};

#endif 

