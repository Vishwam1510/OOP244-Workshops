/*
*****************************************************************************
< Workshop - #5 (Part-1)>
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
#ifndef SDDS_CHAPTER_H_
#define SDDS_CHAPTER_H_
#include <iostream>
namespace sdds {
   const int MAX_CHAPTER_TITLE = 20;
    class Chapter
    {
        char m_title[MAX_CHAPTER_TITLE+1];
        int m_num_pages;
        int m_num_words;
        unsigned int m_chapter_number;
        void init_chapter();
    public:
        Chapter();
        Chapter(const char* title_);
        Chapter(const char* title_, int chapter_num, int n_pages, int n_words);
        operator int() const;
        operator double() const;
        operator const char* () const;
        Chapter& operator=(const Chapter& chapter);
        Chapter& operator++();
        Chapter& operator--();
        std::ostream& display(std::ostream&)const;
        int getPages();
    };
    std::ostream& operator << (std::ostream& os, const Chapter& ch);
}
#endif


