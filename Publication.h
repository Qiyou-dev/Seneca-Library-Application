// Final Project Milestone 5 
// Date Module
// File	Publication.h
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
#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__
#include <iostream>
#include "Date.h"
#include "Streamable.h"
namespace sdds {
	class Publication : public Streamable {
		char* m_title{}; // max 255 char long
		char m_shelfId[5]{};
		int m_membership = 0;
		int m_libRef = -1;
		Date m_date;
	public:
		Publication();
		Publication(const Publication& toBeCopied);
		Publication& operator=(const Publication& Ro);
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		virtual bool conIO(std::ios& io)const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		virtual operator bool() const;
		virtual ~Publication();
	};
   
}
#endif