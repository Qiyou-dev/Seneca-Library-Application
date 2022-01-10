// Final Project Milestone 5 
// Book Module
// File	Book.cpp
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
#include <cstring>
#include "Book.h"
#include "Lib.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	Book::Book() {}
	Book::Book(const Book& toBeCopied) : Publication(toBeCopied) {
		delAlloCopy(m_author, toBeCopied.m_author);
	}
	Book& Book::operator=(const Book& Ro) {
		if (this != &Ro) {
			Publication::operator=(Ro);
			delAlloCopy(m_author, Ro.m_author);
		}
		return *this;
	}
	Book::~Book() {
		delete[] m_author;
	}
	char Book::type()const {
		return 'B';
	}
	ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		char tempAuthor[SDDS_AUTHOR_WIDTH + 1]{};
		setTempAuthor(tempAuthor, m_author);

		if (conIO(os)) {
			os << ' ';
			os.setf(ios::left);
			os.width(SDDS_AUTHOR_WIDTH);
			os << tempAuthor << " |";	
			os.unsetf(ios::left);
		}
		else {
			os << '\t' << m_author;
		}
		return os;
	}
	istream& Book::read(std::istream& istr) {
		char tempAuthor[256];
		Publication::read(istr);
		delete[] m_author;
		m_author = nullptr;
		if (conIO(istr)) {
			istr.get();
			cout << "Author: ";
			istr.get(tempAuthor, 256);
		}
		else {
			istr.get();
			istr.get(tempAuthor, 256);
		}
		if (istr) {
			m_author = new char[strlen(tempAuthor) + 1];
			strcpy(m_author, tempAuthor);
		}
		return istr;
	}
	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}
	Book::operator bool() const {
		return m_author && m_author[0] && Publication::operator bool();
	}
}
	