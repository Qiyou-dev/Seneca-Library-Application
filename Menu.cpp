// Final Project Milestone 5 
// Menu Module
// File	Menu.cpp
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
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	MenuItem::MenuItem(const char* content) {
		if (content && content[0]) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
	}
	MenuItem::~MenuItem() {
		delete[] m_content;
	}
	bool MenuItem::isEmpty()const {
		return !(m_content && m_content[0]);
	}
	MenuItem::operator bool()const {
		return !isEmpty();
	}
	MenuItem::operator const char* ()const {
		return m_content;
	}
	ostream& MenuItem::display(ostream& os)const {
		if (!isEmpty()) {
			os << m_content;
		}
		return os;
	}

	Menu::Menu(const char* title) {
		if (title && title[0]) {
			m_title.m_content = new char[strlen(title) +1];
			strcpy(m_title.m_content, title);
		}
	}
	Menu::~Menu() {
		for (int i = 0; i < m_numItems; i++) {
			delete mp[i];
		}
	}
	ostream& Menu::displayTitle(ostream& os)const {
		if (m_title) {
			os << m_title.m_content;
		}
		return os;
	}
	ostream& Menu::displayMenu(ostream& os)const {
		displayTitle(os);
		if (m_title) {
			os << endl;
		}
		for (int i = 0; i < m_numItems; i++) {
			os.width(2);
			os << i + 1 << "- " << mp[i]->m_content << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}
	unsigned int Menu::run() {
		displayMenu(cout);
		unsigned int selection;
		getIntInRange(selection, 0, m_numItems, "Selection");
		return selection;
	}
	unsigned int Menu::operator~() {
		return run();
	}
	Menu& Menu::operator<< (const char* menuItemContent) {
		if ((unsigned)m_numItems < MAX_MENU_ITEMS) {
			mp[m_numItems++] = new MenuItem(menuItemContent);
		}
		return *this;
	}
	Menu::operator int()const {
		return m_numItems;
	}
	Menu::operator unsigned int()const {
		return m_numItems;
	}
	Menu::operator bool()const {
		return m_numItems > 0;
	}
	const char* Menu::operator[] (int index)const {
		index %= m_numItems;
		return (const char*)*mp[index];
	}
	ostream& operator<<(ostream& os, const Menu& menu) {
		menu.displayTitle(os);
		return os;
	}
}