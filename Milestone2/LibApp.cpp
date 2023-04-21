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
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {

	LibApp::LibApp()
	{
		m_mainMenu.m_menuTitle = new char[27];
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";
		strcpy(m_mainMenu.m_menuTitle, "Seneca Library Application");
		m_mainMenu.m_menuCounter = 4;
		m_exitMenu.m_menuTitle = new char[64];
		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		strcpy(m_exitMenu.m_menuTitle, "Changes have been made to the data, what would you like to do?");
		m_exitMenu.m_menuCounter = 2;
		m_changed = false;
		load();
	}	
	bool LibApp::confirm(const char* message)
	{
		Menu a(message);
		bool TF;
		a.m_menuItems[0] = new MenuItem("Yes");
		a.m_menuCounter = 1;
		int get = a.run();
		if (get == 1)
			TF = true;
		else if (get == 0)
			TF = false;
		return TF;
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;

	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;

	}
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl << endl;
		m_changed = true;
	}

	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		bool TF = confirm("Add this publication to library?");
		if (TF)
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
		else
		{
			cout << endl;
		}

	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		bool TF = confirm("Remove this publication from the library?");
		if (TF)
		{
			m_changed = true;
			cout << "Publication removed" << endl;
			cout << endl;
		}
	}
	void LibApp::checkOutPub()
	{
		search();
		bool TF = confirm("Check out publication?");
		if (TF)
		{
			cout << "Publication checked out" << endl;
			cout << endl;
			m_changed = true;
		}
	}

	void LibApp::run()
	{
		bool TF = true;
		do
		{

			int choose;
			choose = m_mainMenu.run();

			if (choose == 0)
			{
				int s;
				if (m_changed)
				{
					s = m_exitMenu.run();
					if (s == 1)
					{
						save();
						TF = false;
					}
					else if (s == 2)
					{
						TF = true;
						cout << endl;
					}
					else if (s == 0)
					{

						bool get = confirm("This will discard all the changes are you sure?");

						if (get)
						{
							TF = false;
						}
						else
						{
							TF = false;
						}
					}
				}
				else
				{
					TF = false;
				}
			}
			else if (choose == 1)
			{
				newPublication();

			}
			else if (choose == 2)
			{
				removePublication();

			}
			else if (choose == 3)
			{
				checkOutPub();

			}
			else if (choose == 4)
			{
				returnPub();

			}
		} while (TF);
		cout << endl << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}
