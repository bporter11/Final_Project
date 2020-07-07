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

#ifndef CANDIDATELIST_H
#define CANDIDATELIST_H

#include "CandidateType.h"
#include <list>


class CandidateList
{
public:
	// Default constructor
	CandidateList();

	// addCandidate
	void addCandidate(const CandidateType& newCandidate);

	// getWinner
	int getWinner() const;

	// isEmpty
	bool isEmpty() const;
	// searchCandidate
	bool searchCandidate(int id) const;

	// printCandidateName
	void printCandidateName(int id) const;
	// printAllCandidates
	void printAllCandidates() const;
	// printKingdomVotes
	void printKingdomVotes(int id, int index) const;
	// printCandidateTotalVotes
	void printCandidateTotalVotes(int id) const;
	// printFinalResults
	void printFinalResults() const;

	/*********************************************
	* FUNCTION ADDED FOR SELECTION #6
	*********************************************/
	void SortCandidatesByID() const;

	// Destructor
	~CandidateList();

private:
	// searchCandidate
	bool searchCandidate(int ID, std::list<CandidateType>::const_iterator& myIter) const;
	
	void printHeader() const;

	void printCandidate(const std::list<CandidateType>::const_iterator& iter, int pos) const;

	std::list<CandidateType> candidates;
};

#endif