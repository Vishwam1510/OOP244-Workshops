/*					Workshop-7
Name:- Vishwam Shailesh Kapadia
Student ID:- 154933212
E-mail:- vkapadia3@myseneca.ca
*/

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "MemberParliament.h"
#include "Minister.h"

using namespace std;
namespace sdds
{
	Minister::Minister(const char* id, int age, double year, const char* name, const char* district) :MemberParliament(id, age)
	{
		strcpy(pmName, name);
		pmYear = year;
		MemberParliament::NewDistrict(district);
	}
	void Minister::changePM(const char* pm)
	{
		strcpy(pmName, pm);
	}
	void Minister::assumeOffice(double year)
	{
		pmYear = year;
	}
	std::ostream& Minister::write(std::ostream& os)const
	{
		MemberParliament::write(os);
		os << " | " << pmName << "/" << (int)pmYear;
		return os;
	}
	std::istream& Minister::read(std::istream& is)
	{
		char pmName[50 + 1] = { '\0' };
		double pmYear = 0;
		MemberParliament::read(is);

		cout << "Reports TO: ";
		is >> pmName;
		changePM(pmName);

		cout << "Year Assumed Office: ";
		is >> pmYear;
		assumeOffice(pmYear);
		
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const Minister& m1)
	{
		return m1.write(os);
	}
	std::istream& operator>>(std::istream& is, Minister& m1)
	{
		return m1.read(is);
	}
}