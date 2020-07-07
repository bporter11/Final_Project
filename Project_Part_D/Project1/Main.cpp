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

#include "InputHandler.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu();
void processChoice(CandidateList& candidateList);

int main()
{
	CandidateList candidateList;

	readCandidateData(candidateList);
	system("Color 40");
	displayMenu();
	processChoice(candidateList);

	cout  <<  endl;
	system("Pause");
	return 0;
}

void displayMenu()
{
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nSelect one of the following:\n\n";
	cout << "    1: Print all candidates" << endl;
	cout << "    2: Print a candidate's kingdom votes" << endl;
	cout << "    3: Print a candidate's total votes" << endl;
	cout << "    4: Print winner" << endl;
	cout << "    5: Print final results" << endl;
	cout << "    6: Print candidates sorted by ID (Descending)" << endl;
	cout << "    7: To exit" << endl;
}

void processChoice(CandidateList& candidateList)
{
	int choice;
	cout << "\nEnter your choice: ";
	cin >> choice;

	while (choice != 7)
	{
		string fName, lName;
		int kingdom = 0,
			     id = 0;

		switch (choice)
		{
			// Print all candidates
		case 1:
			cout << endl;
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
				candidateList.printAllCandidates();
			break;

			// Print a candidates's kingdom votes
		case 2:
			cout << endl;
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				cout << "Enter candidate's ID number: ";
				cin >> id;
				cout << endl;
				if (candidateList.searchCandidate(id))
				{
					candidateList.printCandidateName(id);
					cout << endl;
					for (int i = 0; i < NUM_OF_KINGDOMS; ++i)
						candidateList.printKingdomVotes(id, i);
				}
			}
			break;

			// Print a candidate's total votes
		case 3:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				cout << "Enter candidate's ID number: ";
				cin >> id;
				cout << endl;
				if (candidateList.searchCandidate(id))
				{
					candidateList.printCandidateName(id);
					cout << endl;
					candidateList.printCandidateTotalVotes(id);
				}
				else
				{
					cout << "\n    =>  ID not in the list."
						<< endl;
				}
			}
			break;

				// Print winner
		case 4:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
			{
				id = candidateList.getWinner();
				if (id != 0)
				{
					cout << "Election winner: ";
					candidateList.printCandidateName(id);
					cout << endl;
					candidateList.printCandidateTotalVotes(id);
				}
				else
				{
					cout << "\n    => There are no candidates." 
						 << endl;
				}
			}
			break;

			// Print final results
		case 5:
			cout << endl; 
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
				candidateList.printFinalResults();
			break;

			//print candidates sorted by ID (Descending)
		case 6:
			if (candidateList.isEmpty())
				cerr << "*** List is empty.\n";
			else
				candidateList.SortCandidatesByID();
			break;

		default:
			cout << "\n    => Sorry. That is not a selection." << endl;
		}

		cout << endl;
		system("Pause");
		displayMenu();
		cout << "\nEnter your choice: ";
		cin >> choice;
	}

	if (choice == 7)
		cout << "\n*** Thank you and have a great day!" << endl;
}