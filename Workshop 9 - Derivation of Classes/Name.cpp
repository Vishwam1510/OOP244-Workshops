/*
*****************************************************************************
						  Workshop - #9
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Name.h"

using namespace std;
namespace sdds
{
	Name::Name()
	{
		m_Name = nullptr;
	}
	Name::Name(const char* name)
	{
		m_Name = nullptr;
		if (name != nullptr)
		{
			set(name);
		}
	}
	void Name::set(const char* name)
	{
		m_Name = new char[strlen(name) + 1];
		strcpy(m_Name, name);
	}
	Name::Name(const Name& n1)
	{
		m_Name = nullptr;
		if (n1.m_Name != nullptr)
		{
			set(n1.m_Name);
		}
	}
	Name& Name::operator=(const Name& n1)
	{
		if (this != &n1)
		{
			delete[] m_Name;
			m_Name = nullptr;
			if (n1.m_Name != nullptr)
			{
				set(n1.m_Name);
			}
		}
		return *this;
	}
	Name::~Name()
	{
		delete[] m_Name;
		m_Name = nullptr;
	}
	Name::operator const char* () const
	{
		return m_Name;
	}
	Name::operator bool() const
	{
		bool success = false;
		if (m_Name != nullptr)
		{
			success = true;
		}
		return success;
	}
	std::ostream& Name::display(std::ostream& ostr)const
	{
		if (operator bool())
		{
			ostr << m_Name;
		}
		return ostr;
	}
	std::istream& Name::read(std::istream& istr)
	{
		char* temp = new char[100];
		istr.getline(temp, 99, ' ');
		delete[] m_Name;
		m_Name = nullptr;
		if (istr)
		{
			set(temp);
		}
		delete[] temp;
		return istr;
	}
	std::ostream& operator<<(std::ostream& os, Name& n1)
	{
		return n1.display(os);
	}
	std::istream& operator>>(std::istream& is, Name& n1)
	{
		return n1.read(is);
	}
}