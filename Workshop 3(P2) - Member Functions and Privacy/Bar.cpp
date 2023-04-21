/*
*****************************************************************************
                          Workshop - #3 (P2)
Full Name  : Vishwam Shailesh Kapadia
Student ID#: 154933212
Email      : vkapadia3@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <cstring>
#include <bits/stdc++.h>
#include "Bar.h"

using namespace std;
namespace sdds
{
    Bar::Bar()
    {
        gameTitle = nullptr;
        gameSymbol = ' ';

        forGame = nullptr;
        
        gthn = 0;
        work = 0;

        execution = false;
    }
    Bar::Bar(const char* title, char symbol, int value)
    {
        gameTitle = new char[strlen(title) + 1];
        strcpy(gameTitle, title);

        gameSymbol = symbol;
        gthn = value;
        work = 0;
        execution = true;
    }
    Bar::~Bar()
    {
        delete[] gameTitle;
        gameTitle = nullptr;
        forGame = nullptr;
    }
    void Bar::forSetting(const char* title, char symbol, int value)
    {
        if (value <= 0 || value > 100)
        {
            execution = false;
            return;
        }

        value = value / 2;
        gameTitle = new char[strlen(title) + 1];
        strcpy(gameTitle, title);

        execution = true;        
        gthn = value;
        work = 0;
        gameSymbol = symbol;        
    }
    bool Bar::isBar() const
    {
        return execution;
    }
    void Bar::draw() const
    {
        if (execution)
        {
            int index = 0;
            for (index = 0; gameTitle[index] != '\0'; index++) 
            {
                cout << gameTitle[index];
            }
            while (index < 20) 
            {
                cout << ".";
                index++;
            }
            cout << "|";
            for (int i = 0; i < gthn; i++)
            {
                cout << gameSymbol;
            }
            cout << endl;
        }
    }
}