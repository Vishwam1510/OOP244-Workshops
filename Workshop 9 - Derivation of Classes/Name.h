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

#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include<iostream>

namespace sdds
{	
	class Name 
	{		
		char* m_Name;		
		void setEmpty(); 
		void setFname(const char* fName); 
	public:		
		Name();
		Name(const char* name);		
		Name(const Name& source);		
		~Name();
		void set(const char* name);
		operator const char* ()const;
		virtual operator bool()const;		
		Name& operator=(const Name& source);		
		virtual std::ostream& display(std::ostream& ostr = std::cout)const;
		virtual std::istream& read(std::istream& istr = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, Name& source);
	std::istream& operator>>(std::istream& in, Name& source);
}
#endif