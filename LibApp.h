// Final Project Milestone 5 
// Menu Module
// File	LibApp.h
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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       char m_fileName[256]{};
       Publication* m_publications[SDDS_LIBRARY_CAPACITY]{};
       int m_numPublications = 0;
       int m_libRefNumber = 0;
       Menu m_publicationTypeMenu;
       bool confirm(const char* message);
       void load();
       void save();
       int search(int searchType = 1);
       void returnPub();
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef);
       char getType();
   public:
       LibApp(const char* filename);
       void run();
       ~LibApp();
   };
}
#endif // !SDDS_LIBAPP_H



