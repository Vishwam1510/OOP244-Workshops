/*
*****************************************************************************
< Workshop - #4 (Part-2)>
Full Name : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email : vkapadia3@myseneca.ca
Section : NCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************

*/

#ifndef SDDS_CLEANERBOT_H
#define SDDS_CLEANERBOT_H

namespace sdds
{
	class CleanerBot
	{
		char* forLocation;
		double forBattery;
		int forBrush;
		bool forActive;

	public:
		CleanerBot();
		CleanerBot(const char* location, double battery, int brush, bool active);
		~CleanerBot();
		void set(const char* location, double battery, int brush, bool active);
		void setLocation(const char* location);
		void setActive(bool active);

		const char* getLocation() const;
		double getBattery() const;
		int getBrush() const;
		bool isActive() const;
		bool isValid() const;
		void resetInfo();

		void display() const;		
	};
	int report(CleanerBot* bot, short num_bots);
}
#endif