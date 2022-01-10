// Final Project Milestone 5 
// Book Module
// File	Book.h
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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_author{};
	public:
		Book();
		Book(const Book& toBeCopied);
		Book& operator=(const Book& Ro);
		virtual ~Book();
		virtual char type()const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		virtual operator bool() const;
	};
}
#endif