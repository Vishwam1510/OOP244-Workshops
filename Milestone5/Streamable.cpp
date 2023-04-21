// -----------------------------------------------------------
//Name:- Vishwam Shailesh Kapadia
//ID  :- 154933212
//email:- vkapadia3@myseneca.ca
/////////////////////////////////////////////////////////////////

#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds {
    Streamable::~Streamable(){};    
    ostream& operator<<(std::ostream& os, const Streamable& s) {
        if (s) {
            s.write(os);
        }
        return os;
    }
    istream& operator>>(std::istream& is, Streamable& s) {
        return (s.read(is));
    }
}