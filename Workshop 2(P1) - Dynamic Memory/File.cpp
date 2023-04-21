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
#include <cstdio>
#include "File.h"
#include "Student.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool readStudentName(char *name)
   {
       bool success = fscanf(fptr, "%[^,],", name) == 1;
       return success;
   }

   bool readStudentNumber(int& studentNumber)
   {       
       bool success = fscanf(fptr, "%d,", &studentNumber) == 1;
       return success;
   }
    
   bool readGrade(char& grade)
   {       
       bool success = fscanf(fptr, "%c\n", &grade) == 1;
       return success;
   }
}