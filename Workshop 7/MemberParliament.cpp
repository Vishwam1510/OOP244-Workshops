/*					Workshop-7
Name:- Vishwam Shailesh Kapadia
Student ID:- 154933212
E-mail:- vkapadia3@myseneca.ca
*/

#define CRT_SECURE_CO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "MemberParliament.h"

using namespace std;
namespace sdds
{
	MemberParliament::MemberParliament(const char* id, int age)
	{
		strcpy(mpID, id);
		mpAge = age;
		strcpy(mpDistrict, "Unassigned");		
	}
	void MemberParliament::NewDistrict(const char* district)
	{
		cout << "|";
		cout.setf(std::ios::right);
		cout.width(8);
		cout << mpID;
		cout << "| |";
		cout.setf(std::ios::right);
		cout.width(20);
		cout << mpDistrict;
		cout << " ---> ";
		strcpy(mpDistrict, district);
		cout << setw(23) << left << mpDistrict;
		cout << "|" << endl;
	}
	std::istream& MemberParliament::read(std::istream& is)
	{
		int age = 0;
		char id[30 + 1] = { '\0' };
		char district[64 + 1] = { '\0' };

		cout << "Age: ";
		is >> age;
		mpAge = age;

		cout << "Id: ";
		is >> id;
		strcpy(mpID, id);

		cout << "District: ";
		is >> district;
		strcpy(mpDistrict, district);	
		
		return is;
	}
	std::ostream& MemberParliament::write(std::ostream& os) const
	{
		os << "| " << mpID << " | " << mpAge << " | " << mpDistrict;
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const MemberParliament& mp1)
	{
		return mp1.write(os);
	}
	std::istream& operator>>(std::istream& is, MemberParliament& mp1)
	{
		return mp1.read(is);
	}
}
