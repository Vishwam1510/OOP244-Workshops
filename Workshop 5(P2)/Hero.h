#ifndef SDDS_HERO_H
#define SDDS_HERO_H

#include "Power.h"

namespace sdds
{
	class Hero
	{
		char h_name[MAX_NAME_LENGTH+1];
		Power* powers;
		int n_powers;
		int powerLevel;

	public:
		Hero();
		Hero(const char* name, Power* power, int totalPowers);
		~Hero();
		void setEmpty();
		std::ostream& display(std::ostream&)const;
		Hero& operator+=(Power power);
		Hero& operator-=(int level);
		int determinePowerLevel(Power* power, int powercnt);
		int powerlevel();
	};
	bool operator<(Hero h1, Hero h2);
	bool operator>(Hero h1, Hero h2);
	void operator>> (Power& power, Hero& hero);
	void operator<< (Hero& hero, Power& power);
}
#endif