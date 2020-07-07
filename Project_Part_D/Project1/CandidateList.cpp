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

#include <iomanip>
#include <list>
#include <iostream>
#include <string>
#include "CandidateList.h"

using namespace std;

// Function declarations
// Same order as in class definition

// Default constructor
CandidateList::CandidateList()
{}

// addCandidate
void CandidateList::addCandidate(const CandidateType& newCandidate)
{
	candidates.push_back(newCandidate);
}

// getWinner
int CandidateList::getWinner() const
{
	int max = 0;
	int id = 0;
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	list<CandidateType>::const_iterator end = candidates.cend();

	while (iter != end) 
	{
		if (iter->getTotalVotes() > max) 
		{
			id = iter->getID();
			max = iter->getTotalVotes();
		}
		iter++;
	}
	return id;
}

// isEmpty
bool CandidateList::isEmpty() const
{
	return candidates.empty();
}

// searchCandidate
bool CandidateList::searchCandidate(int id) const
{
	list<CandidateType>::const_iterator iter = candidates.cbegin();
	searchCandidate(id, iter);
	return iter != candidates.cend();
}

// printCandidateName
void CandidateList::printCandidateName(int id) const
{
	auto iter = candidates.cbegin();

	if (searchCandidate(id, iter)) 
	{
		cout << iter->getLastName() << ',' << iter->getFirstName();
	}
}

bool operator==(const CandidateType& candidate, int id) 
{
	return candidate.getID() == id;
}

// printAllCandidates
void CandidateList::printAllCandidates() const
{
	auto iter = candidates.cbegin();

	for (auto const& iter : candidates)
	{
		iter.printCandidateInfo();
		cout << endl;
	}
}

// printKingdomVotes
void CandidateList::printKingdomVotes(int id, int index) const
{
	auto iter = candidates.cbegin();
	
	if (searchCandidate(id, iter)) 
	{
		cout << right << setw(6) << "* " << setw(2)
			<< iter->getVotesByKingdom(index) << "( => )"
			<< KINGDOMS[index] << endl; 
	}
}

// printCandidateTotalVotes
void CandidateList::printCandidateTotalVotes(int id) const
{
	auto iter = candidates.cbegin();

	if(searchCandidate(id, iter)) 
	{
		cout << right << setw(6) << "=>"
			<< "Total Votes: " << iter->getTotalVotes() << endl;
	}
}

void CandidateList::printFinalResults() const 
{
	auto current = candidates.cbegin();
	const auto end = candidates.cend();
	
	int pos = 0;
	bool print = true;

	size_t listSize = candidates.size();

	list<CandidateType>::const_iterator toPrint = end;

	printHeader();
	int belowValue = INT_MAX;

	while (print) 
	{
		current = candidates.cbegin();
		int cycleMax = 0;
		bool secondLoop = true;
		int vote = 0;
		while (current != end && secondLoop) 
		{
			vote = current->getTotalVotes();
			if (vote == belowValue - 1)
			{
				toPrint = current;
				cycleMax = vote;
				secondLoop = false;
			}
			else if (vote > cycleMax && vote < belowValue) 
			{
				cycleMax = vote;
				toPrint = current;
			}
			++current;
		}
		belowValue = cycleMax;
		++pos;
		//printing here
		printCandidate(toPrint, pos);
		if (pos == static_cast<int>(listSize)) print = false;
	}
}

/*********************************************
	* FUNCTION ADDED FOR SELECTION #6
*********************************************/
void CandidateList::SortCandidatesByID() const
{
	list<CandidateType>::const_iterator current = candidates.cbegin();
	list<CandidateType>::const_iterator end = candidates.cend();
	list<CandidateType>::const_iterator toPrint = candidates.cbegin();
	int belowValue = INT_MAX;
	int pos = 0;
	bool print = true;
	size_t listSize = candidates.size();

	while (print)
	{
		current = candidates.cbegin();
		int cycleMax = 0;
		bool secondLoop = true;
		int vote = 0;
		while (current != end && secondLoop)
		{
			vote = current->getID();
			if (vote < current->getID())
			{
				toPrint = current;
				cycleMax = vote;
				secondLoop = false;
			}
			else if (vote > cycleMax && vote < belowValue)
			{
				cycleMax = vote;
				toPrint = current;
			}
			++current;
		}
		belowValue = cycleMax;
		++pos;
		toPrint->printCandidateInfo();
		cout << endl;
		if (pos == static_cast<int>(listSize)) print = false;
	}
}
	    
// Destructor
CandidateList::~CandidateList()
{}

void CandidateList::printHeader() const
{
	cout << string(12, '*') << " FINAL RESULTS "
		<< string(12, '*') << endl;
	cout << "LAST" << setw(16) << "FIRST" << setw(10) << "TOTAL"
		<< setw(7) << "POS" << endl;
	cout << "NAME" << setw(15) << "NAME" << setw(11) << "VOTES"
		<< setw(7) << "#" << endl;
	cout << string(39, '-') << endl << endl;
}

void CandidateList::printCandidate(
	const list<CandidateType>::const_iterator& iter , int pos) const
{
	cout << left << setw(15)
		<< iter->getLastName()
		<< left << setw(10)
		<< iter->getFirstName()		
		<< right << setw(5);
	cout << iter->getTotalVotes()
		<< right << setw(7) << pos << endl;
	if (pos % 5 == 0)
	{
		cout << string(39, '-')
			<< endl;
	}
}

bool CandidateList::searchCandidate(int ID, 
	list<CandidateType>::const_iterator& myIter) const
{
	myIter = find(candidates.cbegin(), candidates.cend(), ID);
	return myIter != candidates.cend();
}