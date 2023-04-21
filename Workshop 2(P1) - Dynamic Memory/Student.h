/*
*****************************************************************************
                          Workshop - #2 (P1)
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

#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "File.h"

namespace sdds
{
    
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    

    void sort();
    bool load(Student& load);
    bool load(const char* filename);
    void display(const Student& stu);
    void display();
    void deallocateMemory();
 }

#endif