// Final Project Milestone 5 
// Lib Module
// File	Lib.h
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
#ifndef SDDS_LIB_H_
#define SDDS_LIB_H_

namespace sdds
{
    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 333;
    // Maximum number of publications the library can hold.
}
#endif