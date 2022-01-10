/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Author	Qiyou Wu (140690215)
// Description
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshopsand assignments.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Lib.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	void getIntInRange(unsigned int& value, unsigned int lower, unsigned int upper, const char* selectionType) {
		bool entryDone = false;
		do {
			cin >> value;
			if (cin.fail()) {
				cin.clear(); // clears the error state
				cin.ignore(10000, '\n');
				cout << "Invalid " << selectionType << ", try again: ";
			}
			else if (cin.get() != '\n') { // 123adsfga<enter> -> bad
				cout << "Invalid " << selectionType << ", try again: ";
				cin.ignore(10000, '\n');
			}
			else if (value < lower || value > upper) {
				cout << "Invalid " << selectionType << ", try again: ";
			}
			else {
				entryDone = true;
			}
		} while (!entryDone);
	}
	int strLen(const char* str) {
		int len = -1;
		while (str[++len]);
		return len;
	}
	void strCpy(char* des, const char* src) {
		while (*src) *des++ = *src++;
		*des = *src;
	}
	void strCat(char* des, const char* src) {
		while (*des) des++;
		while (*src) *des++ = *src++;
		*des = *src;
	}
	void delAlloCopy(char*& des, const char* src) {
		delete[] des;
		des = nullptr;
		if (src && src[0]) {
			des = new char[strLen(src) + 1];
			strCpy(des, src);
		}
	}
	char* dynRead(istream& istr, char delimeter) {
		char* str{};
		string toRead;
		getline(istr, toRead, delimeter);
		if (istr) {
			str = new char[strLen(toRead.c_str()) + 1];
			strCpy(str, toRead.c_str());
		}
		return str;
	}
	void setTempAuthor(char* destination, char* source) {
		int i;
		for (i = 0; i < SDDS_AUTHOR_WIDTH && i < strLen(source); i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
	}
	void setTempTitle(char* destination, char* source) {
		int i;
		for (i = 0; i < SDDS_TITLE_WIDTH && i < strLen(source); i++) {
			destination[i] = source[i];
		}
		destination[i] = '\0';
	}
}