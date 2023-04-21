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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<cstring>
#include"FullName.h"
#include "Name.h"

using namespace std;

namespace sdds
{
	void FullName::setEmpty()
	{
		m_flName = nullptr;
	}
	void FullName::setlName(const char* lName)
	{
		m_flName = new char[strlen(lName) + 1];
		strcpy(m_flName, lName);
	}	
	FullName::FullName() :Name()
	{
		setEmpty();
	}
	FullName::FullName(const char* fName, const char* lName) :Name(fName)
	{
		setEmpty();
		if (lName != nullptr)
		{
			setlName(lName);
		}
	}
	FullName::FullName(const FullName& source) : Name(source)
	{
		setEmpty();
		if (bool(source))
		{

			setlName(source.m_flName);
		}
	}
	FullName::~FullName()
	{
		delete[] m_flName;
	}
	FullName::operator const char* ()const
	{
		return m_flName;
	}
	FullName::operator bool()const
	{
		return (Name::operator bool() && m_flName != nullptr);
	}
	FullName& FullName::operator=(const FullName& source)
	{
		if (this != &source)
		{
			Name::operator=(source);
			delete[] m_flName;
			setEmpty();
			if (bool(source))
			{
				setlName(source.m_flName);
			}
		}
		return *this;
	}
	ostream& FullName::display(std::ostream& ostr)const
	{
		if (bool(this))
		{
			Name::display(ostr);
			ostr << " " << m_flName;
		}
		return ostr;
	}
	istream& FullName::read(std::istream& istr)
	{
		Name::read(istr);		
		char* temp = new char[200];
		istr.getline(temp, 199, '\n');
		delete[] m_flName;
		setEmpty();
		if (istr)
		{
			setlName(temp);
		}
		delete[] temp;
		return istr;
	}
}