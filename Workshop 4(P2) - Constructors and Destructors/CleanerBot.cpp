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

#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CleanerBot.h"

namespace sdds
{
	CleanerBot::CleanerBot()
	{		
		resetInfo();
	}
	CleanerBot::CleanerBot(const char* location, double battery, int brush, bool active)
	{
		if (location == nullptr || battery < 0 || brush < 0)
		{
			resetInfo();
		}
		else
		{
			forLocation = new char[strlen(location) + 1];
			strcpy(forLocation, location);
			forBattery = battery;
			forBrush = brush;
			forActive = active;
		}
	}
	CleanerBot::~CleanerBot()
	{
		delete[] forLocation;
		forLocation = nullptr;		
	}

	void CleanerBot::set(const char* location, double battery, int brush, bool active)
	{
		if (location == nullptr || battery < 0 || brush < 0)
		{
			resetInfo();
		}
		else
		{
			forLocation = new char[strlen(location) + 1];
			strcpy(forLocation, location);
			forBattery = battery;
			forBrush = brush;
			forActive = active;
		}
	}

	void CleanerBot::setLocation(const char* location)
	{
		forLocation = new char[strlen(location) + 1];
		strcpy(forLocation, location);
	}

	void CleanerBot::setActive(bool active)
	{
		forActive = active;
	}

	const char* CleanerBot::getLocation() const
	{
		return forLocation;
	}

	double CleanerBot::getBattery() const
	{
		return forBattery;
	}
	int CleanerBot::getBrush() const
	{
		return forBrush;
	}
	bool CleanerBot::isActive() const
	{
		return forActive;
	}
	bool CleanerBot::isValid() const
	{
		bool check;
		if (forLocation == nullptr || forBattery < 0 || forBrush < 0)
		{
			check = false;
		}
		else
		{
			check = true;
		}
		return check;
	}
	void CleanerBot::resetInfo()
	{
		forLocation = nullptr;
		forBattery = 0;
		forBrush = 0.0;
		forActive = false;
	}
	void CleanerBot::display() const
	{
		printf("| %-10s | %7.1lf | %18d | %-6s |\n", getLocation(), getBattery(), getBrush(), isActive() ? "YES" : "NO");
	}

	int report(CleanerBot* bot, short num_bots)
	{
		int i, j, count = 0;
		CleanerBot sort;

		printf("         ------ Cleaner Bots Report -----\n");
		printf("     ---------------------------------------\n");
		printf("| Location   | Battery |  Number of Brushes | Active |\n");
		printf("|------------+---------+--------------------+--------|\n");

		for (i = 0;i < num_bots;i++)
		{
			if (bot[i].isValid())
			{
				bot[i].display();
			}			
		}
		printf("\n");

		for (i = 0;i < num_bots;i++)
		{
			if (bot[i].getBattery() < 30.0 && bot[i].isValid())
			{
				count++;
			}
		}		
		if (count > 0)
		{
			for (i = num_bots - 1; i > 0; i--)
			{
				for (j = 0; j < i; j++)
				{
					if (bot[j].getBattery() < bot[j + 1].getBattery())
					{
						sort = bot[j];
						bot[j] = bot[j + 1];
						bot[j + 1] = sort;
					}
				}
			}
			printf("|====================================================|\n");
			printf("| LOW BATTERY WARNING:                               |\n");
			printf("|====================================================|\n");
			printf("| Number of robots to be charged:%2d                  |\n", count);
			printf("| Sorting robots based on their available power:     |\n");
			printf("| Location   | Battery |  Number of Brushes | Active |\n");
			printf("|------------+---------+--------------------+--------|\n");

			for (i = 0;i < num_bots;i++)
			{
				if (bot[i].isValid())
				{
					bot[i].display();
				}
			}
			printf("|====================================================|\n");			
		}
		return 1;
	}
}