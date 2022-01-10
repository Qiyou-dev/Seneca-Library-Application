// Final Project Milestone 5 
// Lib Module
// File	Streamable.h
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
#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__
#include <iostream>

namespace sdds
{
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool conIO(std::ios& ios)const = 0;
		virtual operator bool()const = 0;
		virtual ~Streamable();
	};
	std::ostream& operator<<(std::ostream& os, const Streamable& sm);
	std::istream& operator>>(std::istream& is, Streamable& sm);
}
#endif
