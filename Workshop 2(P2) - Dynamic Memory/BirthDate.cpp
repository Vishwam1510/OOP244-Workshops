#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "BirthDate.h"

using namespace std;

namespace sdds
{
	Employee* records;
	int monthSearching = 0, totalrecords = 0;
	FILE* fptr;
	bool openFile(const char filename[]) 
	{
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	void closeFile() 
	{
		if (fptr) fclose(fptr);
	}

	int nRecords()
	{
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}

	bool load(Employee &employee)
	{
		char empName[128];
		if (read(empName) && read(employee.month) && read(employee.date) && read(employee.year)) {
			employee.name = new char[strlen(empName) + 1];
			strcpy(employee.name, empName);
		}
		return true;
	}

	bool read(char* employee_name)
	{
		bool success = fscanf(fptr, "%[^,],", employee_name) == 1;
		return success;
	}

	bool read(int& bdmonth)
	{
		bool success = fscanf(fptr, "%d/", &bdmonth) == 1;
		return success;
	}

	bool beginSearch(const char* filename)
	{
		monthSearching = 0;
		totalrecords = 0;
		int i = 0, j = 0;
		if (openFile(filename)) {
			totalrecords = nRecords();
			records = new Employee[totalrecords];
			for (j = 0;j < totalrecords;j++) 
			{
				i = i + load(records[j]);
			}			
			closeFile();
		}
		cout << "Birthdate search program\n";
		return true;
	}

	bool readBirthDate(int month)
	{		
		for (int i = 0;i < totalrecords ;i++)
		{
			if (records[i].month == month) 
			{
				monthSearching = month;
				return true;
			}
		}
		return false;
	}
	void sort()
	{
		int i, j;
		Employee temp;
		for (i = totalrecords - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (records[j].year > records[j + 1].year) {
					temp = records[j];
					records[j] = records[j + 1];
					records[j + 1] = temp;
				}
				else if (records[j].year == records[j + 1].year && records[j].month > records[j + 1].month) {
					temp = records[j];
					records[j] = records[j + 1];
					records[j + 1] = temp;
				}
			}
		}
	}
	void displayBirthdays()
	{
		int cnt = 0, index = 1;
		for (int i = 0;i < totalrecords;i++) 
		{
			if (records[i].month == monthSearching) {
				cnt++;
			}
		}
		cout << cnt << " birthdates found:\n";
		for (int i = 0;i < totalrecords;i++)
		{
			if (records[i].month == monthSearching)
			{
				cout << index << ") ";
				string forName;
				for (int j = 1;j < (int)strlen(records[i].name);j++)
				{
					forName = forName + records[i].name[j];
				}
				cout << forName << ":\n";
				cout << records[i].year << "-" << records[i].month << "-" << records[i].date << endl;
				cout << "===================================\n";
				index++;
			}
		}
	}
	void deallocate()
	{
		for (int i = 0;i < totalrecords;i++) 
		{
			delete[] records[i].name;
		}
		delete[] records;
	}
	void endSearch()
	{
		cout << "Birthdate Search Program Closed.\n";
	}
}