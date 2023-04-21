/*					Workshop-7
Name:- Vishwam Shailesh Kapadia
Student ID:- 154933212
E-mail:- vkapadia3@myseneca.ca
*/

#ifndef SDDS_MINISTER_H
#define SDDS_MINISTER_H
#include <iostream>
#include "MemberParliament.h"

namespace sdds
{
	class Minister :public MemberParliament
	{
	private:
		char pmName[50 + 1];
		double pmYear;
	public:
		Minister(const char* id, int age, double year, const char* name, const char* district);
		void changePM(const char* pm);
		void assumeOffice(double year);
		std::ostream& write(std::ostream& os = std::cout)const;
		std::istream& read(std::istream& is = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, const Minister& m1);
	std::istream& operator>>(std::istream& is, Minister& m1);
}
#endif
