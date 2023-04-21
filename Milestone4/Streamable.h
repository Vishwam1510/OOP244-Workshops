// -----------------------------------------------------------
//Name:- Vishwam Shailesh Kapadia
//ID  :- 154933212
//email:- vkapadia3@myseneca.ca
/////////////////////////////////////////////////////////////////


#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

using namespace std;

namespace sdds {
    class Streamable {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& io) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
    };
    ostream& operator<<(std::ostream& os, const Streamable& s);
    istream& operator>>(std::istream& is, Streamable& s);
}
#endif 