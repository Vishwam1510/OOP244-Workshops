/*					Workshop-7
Name:- Vishwam Shailesh Kapadia
Student ID:- 154933212
E-mail:- vkapadia3@myseneca.ca
*/

#ifndef SDDS_MEMBERPARLIAMENT_H
#define SDDS_MEMBERPARLIAMENT_H
#include <iostream>

namespace sdds
{
	class MemberParliament
	{
		char mpID[32 + 1];
		char mpDistrict[64 + 1];
		int mpAge;
	public:
		MemberParliament(const char* id, int age);
		void NewDistrict(const char* district);
		std::istream& read(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& os, const MemberParliament& mp1);
	std::istream& operator>>(std::istream& is, MemberParliament& mp1);
}
#endif