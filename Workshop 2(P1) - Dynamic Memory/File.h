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


#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds 
{
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool readStudentName(char *name);
   bool readStudentNumber(int& studentNumber);
   bool readGrade(char& grade);
}
#endif // !SDDS_FILE_H_

