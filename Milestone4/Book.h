// -----------------------------------------------------------
//Name:- Vishwam Shailesh Kapadia
//ID  :- 154933212
//email:- vkapadia3@myseneca.ca
/////////////////////////////////////////////////////////////////

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {
    class Book : public Publication {
    private:
        char* authorName;
    public:
        Book();
        ~Book();       
        Book(const Book& book);
        Book& operator=(const Book& book);        
        void setBookEmpty();        
        char type() const;        
        std::ostream& write(std::ostream& os) const;       
        std::istream& read(std::istream& is);        
        virtual void set(int member_id);       
        operator bool() const;
    };
}

#endif