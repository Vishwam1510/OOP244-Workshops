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

#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H

#include"Name.h"

namespace sdds
{	
	class FullName : public Name
	{				
		char* m_flName;		
		void setEmpty();
		void setlName(const char* lName);
	public:		
		FullName();
		FullName(const char* fName, const char* lName);		
		FullName(const FullName& source);		
		~FullName();		
		operator const char* ()const;
		virtual operator bool()const;				
		FullName& operator=(const FullName& source);		
		virtual std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual std::istream& read(std::istream& istr = std::cin);
	};
}

#endif