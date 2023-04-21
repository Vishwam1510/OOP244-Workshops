#ifndef SDDS_BIRTHDATE_H
#define SDDS_BRITHDATE_H

#include <iostream>

namespace sdds
{
	struct Employee
	{
		char* name;
		int month;
		int date;
		int year;
	};
	
	bool openFile(const char filename[]);
	void closeFile();

	//bool load(Employee* employee);

	int nRecords();
	bool read(char* employee_name);
	bool read(int& bdmonth);

	bool beginSearch(const char* filename);
	bool readBirthDate(int month);
	void sort();
	void displayBirthdays();
	void deallocate();
	void endSearch();
}
#endif