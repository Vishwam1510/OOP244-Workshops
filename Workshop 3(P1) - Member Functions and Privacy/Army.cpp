/*
*****************************************************************************
						  Workshop - #3 (P1)
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

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include "Army.h"

using namespace std;

namespace sdds
{
	void Army::setEmpty()
	{
		nationality[MAX_NAME_LEN] = { '\0' };
		noUnits = 0;
	}
	void Army::createArmy(const char* country, double pow, int troops)
	{
		bool valid = true;

		if (country == nullptr || strlen(country)==0)
		{
			valid = false;
		}
		if (pow <= 0)
		{
			valid = false;
		}
		if (troops <= 0)
		{
			valid = false;
		}

		if (valid)
		{
			strcpy(nationality, country);
			power = pow;
			noUnits = troops;			
		}
		else
		{
			setEmpty();
		}	
	}
	void Army::updateUnits(int troops)
	{
		noUnits += troops;
		power += 0.25 * troops;
	}
	const char* Army::checkNationality() const
	{
		return nationality;
	}
	int Army::checkCapacity() const
	{
		return noUnits;
	}
	double Army::checkPower() const
	{
		return power;
	}
	bool Army::isEmpty() const
	{
		bool check = false;
		if (nationality[0] == '\0' && noUnits <= 0 && power <= 0.0)
		{
			check = true;
		}
		return check;
	}
	bool Army::isStrongerThan(const Army& army)const
	{
		bool check = false;
		if (army.power < power)
		{
			check = true;
		}
		return check;
	}
	void battle(Army& arm1, Army& arm2)
	{
		int power = 0;
		if (arm1.isEmpty() ==false && arm2.isEmpty()==false)
		{
			if (arm1.isStrongerThan(arm2))
			{
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm1.checkNationality() << " is victorious!" << endl;
				power = arm2.checkCapacity();
				power = power * 0.5;
				arm2.updateUnits(-power);
			}
			else
			{
				cout << "In battle of " << arm1.checkNationality() << " and " << arm2.checkNationality() << ", " << arm2.checkNationality() << " is victorious!" << endl;
				power = arm1.checkCapacity();
				power = power * 0.5;
				arm1.updateUnits(-power);
			}
		}
	}
	void displayDetails(const Army* armies,int size)
	{
		int i;
		cout << "Armies reporting to battle: " << endl;
		for (i = 0;i < size;i++)
		{
			if (!armies[i].isEmpty())
			{
				cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: " << armies[i].checkCapacity() << ", Power left: " << fixed << setprecision(1) << armies[i].checkPower() << endl;
			}
		}
	}

}