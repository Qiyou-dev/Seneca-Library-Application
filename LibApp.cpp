// Final Project Milestone 5 
// Menu Module
// File	LibApp.cpp
// Version 1.0
// Author	Qiyou Wu (140690215)
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshopsand assignments.
// 
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2021/10/29	       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "Book.h"
#include "PublicationSelector.h"
#include "Utils.h"
#include <cstring>
using namespace std;

namespace sdds {
	LibApp::LibApp(const char* filename):m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?"), m_publicationTypeMenu("Choose the type of publication:") {
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		m_publicationTypeMenu << "Book";
		m_publicationTypeMenu << "Publication";
		strCpy(m_fileName, filename);
		load();
	}
	bool LibApp::confirm(const char* message) {
		Menu test(message);
		test << "Yes";
		return (test.run() == 1);
	}
	void LibApp::load() {
		std::cout << "Loading Data" << endl;
		ifstream infile(m_fileName);
		char type{};
		int i;
		for (i = 0; infile; i++) {
			infile >> type;
			//infile.ignore();
			if (infile) {
				if (type == 'P') {
					m_publications[i] = new Publication;
				}
				else if (type == 'B') {
					m_publications[i] = new Book;
				}
				if (m_publications[i]) {
					infile >> *m_publications[i];
					m_numPublications++;
				}
			}
		}
		m_libRefNumber = m_publications[m_numPublications-1]->getRef();
	}
	void LibApp::save() {
		std::cout << "Saving Data" << endl;
		ofstream outfile(m_fileName);
		for (int i = 0; i < m_numPublications; i++) {
			if (m_publications[i]->getRef() != 0) {
				outfile << *m_publications[i] << endl;
			}
		}
	}
	int LibApp::search(int searchType) {
		int retValue = 0; // the return value/ref number
		PublicationSelector ps("Select one of the following found matches:");
		char type = getType();
		char title[256]{};
		std::cout << "Publication Title: ";
		cin.getline(title, 256);
		for (int i = 0; i < m_numPublications; i++) {
			if (searchType == 1) {
				if (strstr(*m_publications[i], title) && type == m_publications[i]->type()) {
					ps << m_publications[i];
				}
			}
			else if (searchType == 2) {
				if (strstr(*m_publications[i], title) && m_publications[i]->onLoan() && type == m_publications[i]->type()) {
					ps << m_publications[i];
				}
			}
			else if (searchType == 3) {
				if (strstr(*m_publications[i], title) && !m_publications[i]->onLoan() && type == m_publications[i]->type()) {
					ps << m_publications[i];
				}
			}
		}
		if (ps) {
			ps.sort(); // sort them based on date and title
			int ref = ps.run(); // display the publications and select one
			if (ref) {
				retValue = ref;
				cout << *getPub(ref) << endl;
			}
			else {
				cout << "Aborted!" << endl;
			}
		}
		else {
			cout << "No matches found!" << endl;
		}
		return retValue;
	}
	Publication* LibApp::getPub(int libRef) {
		int index = 0;
		for (int i = 0; i < m_numPublications; i++) {
			if (libRef == m_publications[i]->getRef()) {
				index = i;
			}
		}
		return m_publications[index];
	}
	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;
		int selection = search(2);
		if (selection) {
			if (confirm("Return Publication?")) {
				int daysLoaned = Date() - getPub(selection)->checkoutDate();
				if (daysLoaned > SDDS_MAX_LOAN_DAYS) {
					int daysLate = daysLoaned - SDDS_MAX_LOAN_DAYS;
					double penalty = 0;
					penalty = 0.5 * daysLate;
					cout << "Please pay $";
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << penalty << " penalty for being " << daysLate << " days late!" << endl;
					cout.unsetf(ios::fixed);
				}
				getPub(selection)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
	}
	void LibApp::newPublication() {
		if (m_numPublications == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
			return;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			char type = getType();
			if (!type) {
				cout << "Aborted!" << endl;
				return;
			}
			Publication* tempPublication = nullptr;
			if (type == 'P') {
				tempPublication = new Publication;
			}
			else if (type == 'B') {
				tempPublication = new Book;
			}
			tempPublication->read(cin);
			if (cin) {
				if (confirm("Add this publication to the library?")) {
					if (tempPublication) {
						tempPublication->setRef(++m_libRefNumber);
						m_publications[m_numPublications++] = tempPublication;
						m_changed = true;
						cout << "Publication added" << endl;
					}
					else {
						cout << "Failed to add publication!" << endl;
						delete tempPublication;
					}
				}
				else {
					cout << "Aborted!" << endl;
					delete tempPublication;
				}
			}
			else {
				cin.ignore(1000, '\n');
				cout << "Aborted!" << endl;
				delete tempPublication;
			}
		}
	}
	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		int selection = search(1);
		if (selection) {
			if (confirm("Remove this publication from the library?")) {
				getPub(selection)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}
	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		int selection = search(3);
		if (selection) {
			if (confirm("Check out publication?")) {
				unsigned int membershipNumber = 0;
				cout << "Enter Membership number: ";
				getIntInRange(membershipNumber, 10000, 99999, "membership number");
				getPub(selection)->set(membershipNumber);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}
	void LibApp::run() {
		bool done = false;
		do {
			unsigned int selection = m_mainMenu.run();
			if (selection == 1) {
				newPublication();
				cout << endl;
			}
			else if (selection == 2) {
				removePublication();
				cout << endl;
			}
			else if (selection == 3) {
				checkOutPub();
				cout << endl;
			}
			else if (selection == 4) {
				returnPub();
				cout << endl;
			}
			else {
				if (m_changed) {
					unsigned int selectionB = m_exitMenu.run();
					if (selectionB == 1) {
						save();
						done = true;
						cout << endl;
					}
					else if (selectionB == 0) {
						if (confirm("This will discard all the changes are you sure?")) {
							done = true;
							cout << endl;
						}
					}
					else {
						cout << endl;
					}
				}
				else {
					done = true;
					cout << endl;
				}
			}
		} while (!done);
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
	char LibApp::getType(){
		int selection = m_publicationTypeMenu.run();
		char type{};
		if (selection == 1) {
			type = 'B';
		}
		else if (selection == 2) {
			type = 'P';
		}
		return type;
	}
	LibApp::~LibApp() {
		for (int i = 0; i < m_numPublications; i++) {
			delete m_publications[i];
		}
	}
}
