/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version 
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
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
#include <fstream>
namespace sdds {
	void getIntInRange(unsigned int& value, unsigned int lower, unsigned int upper, const char* selectionType);
	int strLen(const char* str);
	void strCpy(char* des, const char* src);
	void strCat(char* des, const char* src);
	void delAlloCopy(char*& des, const char* src);
	char* dynRead(std::istream& istr, char delimeter = '\n');
	void setTempAuthor(char* destination, char* source);
	void setTempTitle(char* destination, char* source);
}
#endif // SDDS_UTILS_H__
