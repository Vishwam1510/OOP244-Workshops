/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                       Date            Reason
// Vishwam Shailesh Kapadia
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds {
	class LibApp {
		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
	public:
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		LibApp();		
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
	};
}
#endif 



