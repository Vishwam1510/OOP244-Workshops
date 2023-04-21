// -----------------------------------------------------------
//Name:- Vishwam Shailesh Kapadia
//ID  :- 154933212
//email:- vkapadia3@myseneca.ca
/////////////////////////////////////////////////////////////////

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
#include <iostream>

using namespace std;

namespace sdds {
    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        ~Publication();
       
        Publication(const Publication& publication);
        Publication& operator=(const Publication& publication);
        
        void setDefault();
        virtual void set(int member_id);
        // Sets the membership attribute to either zero or a five-digit integer.
        void setRef(int value);
        // Sets the **libRef** attribute value
        void resetDate();
        // Sets the date to the current date of the system.
        virtual char type()const;
        //Returns the character 'P' to identify this object as a "Publication object"
        bool onLoan()const;
        //Returns true is the publication is checkout (membership is non-zero)
        Date checkoutDate()const;
        //Returns the date attribute
        bool operator==(const char* title)const;
        //Returns true if the argument title appears anywhere in the title of the 
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        operator const char* ()const;
        //Returns the title attribute
        int getRef()const;
        //Returns the libRef attirbute.       
        bool conIO(std::ios& io) const;
        // Returns true if the address of the io object is the same as the address of either the cin object or the cout object.

        // Write into an ostream object
        ostream& write(std::ostream& os) const;

        // Read from an istream object.
        istream& read(std::istream& is);

        // Overloads of this method will return if the Streamable object is in a valid state or not
        operator bool() const;
    };
}

#endif