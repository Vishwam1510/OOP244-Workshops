#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

using namespace std;

namespace sdds
{
	Hero::Hero()
	{
		this->setEmpty();
	}

	Hero::Hero(const char* name, Power* power, int totalPowers)
	{

		if (name && name[0] != '\0' && totalPowers > 0)
		{
			strncpy(this->h_name, name, MAX_NAME_LENGTH);
			powers = power;			 
			n_powers = totalPowers;		
			determinePowerLevel(power, totalPowers);
		}
		else
		{
			this->setEmpty();
		}
	}

	Hero::~Hero()
	{
		delete[] powers;
		powers = nullptr;
	}

	ostream& Hero::display(ostream& os) const
	{		
		os << "Name: " << h_name << endl;		
		displayDetails(powers, n_powers);
		os << "Power Level: " << powerLevel << endl;
		return os;
	}

	void Hero::setEmpty()
	{
		h_name[0] = '\0';
		n_powers = 0;
		powers = nullptr;
		powerLevel = 0;
	}

	Hero& Hero::operator+=(Power power)
	{
		int i;
		Power* temp = new Power[n_powers + 1];

		for (i = 0;i < n_powers;i++)
		{
			temp[i].createPower(powers[i].checkName(), powers[i].checkRarity());
		}

		temp[i].createPower(power.checkName(), power.checkRarity());
		n_powers = i;
		delete[] powers;

		powers = nullptr;
		powers = new Power[n_powers];

		for (i = 0;i < n_powers;i++)
		{
			powers[i] = temp[i];
		}
		determinePowerLevel(powers, n_powers);
		return *this;
	}

	Hero& Hero::operator-=(int level)
	{
		powerLevel = powerLevel - level;
	}

	int Hero::determinePowerLevel(Power* power, int powercnt)
	{
		int i, powerlvl = 0;
		for (i = 0;i < n_powers;i++)
		{
			powerlvl += powers[i].checkRarity();
		}
		powerLevel = powerlvl * n_powers;
		return powerLevel;
	}

	int Hero::powerlevel()
	{
		return powerLevel;
	}

	bool sdds::operator<(Hero h1, Hero h2)
	{
		bool check = false;
		if (h1.powerlevel() < h2.powerlevel())
		{
			check = true;
		}
		return check;
	}

	bool sdds::operator>(Hero h1, Hero h2)
	{
		bool check = false;
		if (h1.powerlevel() > h2.powerlevel())
		{
			check = true;
		}
		return check;
	}

	void sdds::operator>>(Power& power, Hero& hero)
	{
		hero += power;
	}

	void sdds::operator<<(Hero& hero, Power& power)
	{
		hero += power;
	}
}