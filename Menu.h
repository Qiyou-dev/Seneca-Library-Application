// Final Project Milestone 5 
// Menu Module
// File	Menu.h
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
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds {
	class Menu;
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem {
		char* m_content = nullptr;
	private:
		MenuItem(const char* content = nullptr);
		friend class Menu;
		MenuItem(const MenuItem& mi) = delete;
		MenuItem& operator=(const MenuItem& mi) = delete;
		~MenuItem();
		bool isEmpty()const;
		operator bool()const;
		operator const char* ()const;
		std::ostream& display(std::ostream& os)const;
	};

	class Menu {
		MenuItem m_title;
		MenuItem* mp[MAX_MENU_ITEMS] = { nullptr };
		int m_numItems = 0;
	public:
		Menu(const char* title = nullptr);
		~Menu();
		std::ostream& displayTitle(std::ostream& os)const;
		std::ostream& displayMenu(std::ostream& os)const;
		unsigned int run();
		unsigned int operator~();
		Menu& operator<< (const char* menuItemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		const char* operator[] (int index)const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif