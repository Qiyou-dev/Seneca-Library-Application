// Final Project Milestone 5 
// Date Module
// File	Publication.cpp
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
#include "Publication.h"
#include "Lib.h"
#include "Utils.h"
using namespace std;

namespace sdds {
   
	Publication::Publication() :m_date() {}
	Publication::Publication(const Publication& toBeCopied) {
		operator=(toBeCopied);
	}
	Publication& Publication::operator=(const Publication& Ro) {
		if (this != &Ro) {
			delete[] m_title;
			m_title = nullptr;
			if (Ro) {
				m_title = new char[strlen(Ro.m_title) + 1];
				strcpy(m_title, Ro.m_title);
				strcpy(m_shelfId, Ro.m_shelfId);
			}
			m_membership = Ro.m_membership;
			m_libRef = Ro.m_libRef;
			m_date = Ro.m_date;
		}
		return *this;
	}
	void Publication::set(int member_id) {
		m_membership = member_id < 100000 && member_id > 9999 ? member_id : 0;
	}
	void Publication::setRef(int value) {
		m_libRef = value;
	}
	void Publication::resetDate() {
		Date tempDate = Date();
		m_date = tempDate;
	}
	char Publication::type()const {
		return 'P';
	}
	bool Publication::onLoan()const {
		return m_membership > 0;
	}
	Date Publication::checkoutDate()const {
		return m_date;
	}
	bool Publication::operator==(const char* title)const {
		return strstr(m_title, title);
	}
	Publication::operator const char* ()const {
		return m_title;
	}
	int Publication::getRef()const {
		return m_libRef;
	}
	bool Publication::conIO(ios& io)const {
		return &io == &cin || &io == &cout;
	}
	ostream& Publication::write(ostream& os)const {
		char tempTitle[SDDS_TITLE_WIDTH + 1];
		setTempTitle(tempTitle, m_title);
		if (conIO(os)) {
			os << "| ";
			os.width(4);
			os << m_shelfId << " | ";
			os.width(SDDS_TITLE_WIDTH);
			os.fill('.');
			os.setf(ios::left);
			os << tempTitle << " | ";
			os.unsetf(ios::left);
			os.width(5);
			os.fill(' ');
			if (onLoan()) {
				os << m_membership << " | ";
			}
			else {
				os << " N/A " << " | ";
			}
			os << m_date << " |";
		}
		else {
			os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
		}
		return os;
	}
	istream& Publication::read(istream& istr) {
		char tempTitle[256]{}; char tempShelfId[5]{}; int tempMembership = 0; int tempLibRef = -1; Date tempDate;
		delete[] m_title;
		m_shelfId[0] = 0;
		m_membership = 0;
		m_libRef = -1;
		resetDate();
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.get(tempShelfId, SDDS_SHELF_ID_LEN + 1);
			if (istr.peek() != '\n') {
				istr.setstate(ios::failbit);
				istr.ignore(1000, '\n');
			}
			istr.get();
			cout << "Title: ";
			istr.get(tempTitle, 256);
			istr.get();
			cout << "Date: ";
			tempDate.read(istr);
		}
		else {
			istr >> tempLibRef;
			istr.get();
			istr.get(tempShelfId, 5, '\t');
			istr.get();
			istr.get(tempTitle, 256, '\t');
			istr.get();
			istr >> tempMembership;
			istr.get();
			tempDate.read(istr);
		}
		if (!tempDate) {
			istr.setstate(ios::failbit);
		}
		if (istr) {
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
			strcpy(m_shelfId, tempShelfId);
			m_membership = tempMembership;
			m_libRef = tempLibRef;
			m_date = tempDate;
		}
		return istr;
	}
	Publication::operator bool()const {
		return m_title && m_title[0] && m_shelfId && m_shelfId[0];
	}
	Publication::~Publication() {
		delete[] m_title;
	}
}
