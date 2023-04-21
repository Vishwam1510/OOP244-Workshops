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

#ifndef SDDS_BARCHART_H_
#define SDDS_BARCHART_H_
#include "Bar.h"

#include <iostream>

using namespace std;

namespace sdds
{
    class BarChart
    {
    public:
        BarChart();
        
        bool validBars();

        void init(const char* title, int noOfSampels, char fill);
        void add(const char* bar_title, int value);
        void draw() const;

        void deallocate();
    private:
        const char* chartTitle;
        Bar* bars;
        int barSize;
        int samples;
        char symbol;
        bool check;;
    };
}
#endif