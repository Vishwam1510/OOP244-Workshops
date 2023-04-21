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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "BarChart.h"

using namespace std;

namespace sdds
{
    BarChart::BarChart()
    {
        samples = 0;
        check = false;
    }
    
    bool BarChart::validBars()
    {
        return check;
    }
    void BarChart::init(const char* title, int noOfSamples, char fill)
    {
        bars = new Bar[noOfSamples];
        chartTitle = title;
        barSize = noOfSamples;
        symbol = fill;
    }
    void BarChart::add(const char* bar_title, int value)
    {
        Bar* b = (Bar*)malloc(sizeof(Bar) * 5);
        if (samples <= barSize)
        {
            b->forSetting(bar_title, symbol, value);
            bars[samples] = *b;
            samples += 1;
        }
        check = false;
        if (samples == barSize)
        {
            check = true;
        }        
        free(b);
    }
    void BarChart::draw() const
    {
        if (check)
        {
            bool checkBars = false;
            for (int i = 0; i < barSize; i++)
            {
                if (bars[i].isBar())
                {
                    checkBars = true;
                }
            }
            if (checkBars)
            {
                cout << chartTitle << endl;
                for (int j = 0; j < 71; j++)
                {
                    cout << "-";
                }

                cout << endl;

                for (int k = 0; k < barSize; k++)
                {
                    bars[k].draw();
                }
                for (int l = 0; l < 71; l++)
                {
                    cout << "-";
                }
                
                cout << endl;
            }
        }
        else
        {
            cout << "Invalid Chart!" << endl;
        }
    }
    void BarChart::deallocate()
    {
        delete[] bars;
    }
}
