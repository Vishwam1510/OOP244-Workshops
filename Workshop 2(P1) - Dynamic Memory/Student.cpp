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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"
#include "File.h"

#include <cstring>

using namespace std;



namespace sdds
{
    Student* students;
    int noOfStudents;

    void sort() {
        int i, j;
        Student temp;
        for (i = noOfStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].m_grade > students[j + 1].m_grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    bool load(Student& student) 
    {
        char sname[128];
        if (readStudentName(sname) && readStudentNumber(student.m_studentNumber) && readGrade(student.m_grade)) 
        {
            student.m_name = new char[strlen(sname) + 1];
            strcpy(student.m_name, sname);
        }
        return true;
    }

    bool load(const char* filename)
    {
        int cnt = 0, i;
        bool success;
        openFile(filename);
        noOfStudents = noOfRecords();
        students = new Student[noOfStudents];
        for (i = 0;i < noOfStudents;i++)
        {
            success = load(students[i]);
            if (success == true)
            {
                cnt++;
            }
        }
        if (cnt != noOfStudents)
        {
            std::cout << "Error: incorrect number of records read; the data is possibly corrupted.";
            success = false;
        }
        else
        {
            success = true;
            
        }
        closeFile();
        return success;
    }

    void display(const Student& stu) 
    {
        cout << stu.m_name << ", " << stu.m_studentNumber << ": " << stu.m_grade << endl;
    }
    
    void display() 
    {
        sort();
        int i = 0;
        for (i = 0;i < noOfStudents;i++) 
        {
            cout << i + 1 << ": ";
            display(students[i]);
        }
    }

    void deallocateMemory() 
    {
        int i = 0;
        for (i = 0;i < noOfStudents;i++) 
        {
            delete[] students[i].m_name;
        }
        delete[] students;
    }       
    
}
