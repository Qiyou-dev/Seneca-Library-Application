// Final Project Milestone 5 
// Lib Module
// File	Streamable.cpp
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

#include <iostream>
#include "Streamable.h"
using namespace std;

namespace sdds
{
	Streamable::~Streamable() {

	}
	ostream& operator<<(ostream& os, const Streamable& sm) {
		if (sm) {
			sm.write(os);
		}
		return os;
	}
	istream& operator>>(istream& is, Streamable& sm) {
		sm.read(is);
		return is;
	}
}
