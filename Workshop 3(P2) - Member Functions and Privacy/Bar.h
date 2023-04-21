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
#ifndef SDDS_BAR_H
#define SDDS_BAR_H
#include <iostream>


namespace sdds
{
    class Bar
    {
        char* gameTitle;
        Bar* forGame;
        char gameSymbol;
        int  gthn;
        int work;
        bool execution;

    public:
        Bar(const char* title, char symbol, int value);
        Bar();        
        ~Bar();
        void forSetting(const char* title, char symbol, int value);
        bool isBar() const;
        void draw() const;
    };
}

#endif