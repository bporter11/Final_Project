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
#include <iomanip>
#include "CandidateType.h"

using namespace std;

// Implement all functions in the SAME order
// as listed in the interface file.

//default constructor
CandidateType::CandidateType() 
	: totalVotes(0), numOfKingdoms(NUM_OF_KINGDOMS)
{
	kingdomVotes = new int[numOfKingdoms] {0};
}

//copy constructor
CandidateType::CandidateType(const CandidateType& otherObj)
	: CharacterType(otherObj.getFirstName()
		,otherObj.getLastName()
		,otherObj.getID())
{
	totalVotes = otherObj.totalVotes;
	numOfKingdoms = otherObj.numOfKingdoms;

	kingdomVotes = new int[numOfKingdoms];
	
	for (int i = 0; i < numOfKingdoms; i++)
	{
		kingdomVotes[i] = otherObj.kingdomVotes[i];
	}
}

//copy assignment operator=
CandidateType& CandidateType::operator=(const CandidateType& otherObj)
{
	if (this == &otherObj)
	{
		cerr << "Assignment to self.";
	}
	else
	{
		if (numOfKingdoms != otherObj.numOfKingdoms)
		{
			delete[] kingdomVotes;
			kingdomVotes = new int[otherObj.numOfKingdoms];
		}
		CharacterType::setCharacterInfo(otherObj.getFirstName(),
			otherObj.getLastName(), otherObj.getID());

		for (int i = 0; i < numOfKingdoms; i++)
		{
			kingdomVotes[i] = otherObj.kingdomVotes[i];
		}
		totalVotes = otherObj.totalVotes;
	}
	return *this;
}


//updateVotesByKingdom function
void CandidateType::updateVotesByKingdom(int index, int numOfVotes)
{	
	int prevVote = kingdomVotes[index];
	kingdomVotes[index] = numOfVotes;
	totalVotes = totalVotes - prevVote + numOfVotes;
}

//getTotalVotes function
int CandidateType::getTotalVotes() const
{
	return totalVotes;
}

//getVotesBykingdom function
int CandidateType::getVotesByKingdom(int index) const
{
	return kingdomVotes[index];
}

//printCandidateInfo function
void CandidateType::printCandidateInfo() const
{
	printID();
	cout << " - ";
	printName();
}

//printCandidateTotalVotes function
void CandidateType::printCandidateTotalVotes() const
{
	printName();
	cout << "\n=> Total Votes (all kingdoms): " 
		 << getTotalVotes();
}

bool operator==(const CandidateType& type1, const CandidateType& type2)
{
	return (type1.getID() == type2.getID());
}

//destructor
CandidateType::~CandidateType()
{
	delete[] kingdomVotes;
	kingdomVotes = nullptr;
}