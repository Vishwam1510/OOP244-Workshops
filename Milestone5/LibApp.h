// -----------------------------------------------------------
//Name:- Vishwam Shailesh Kapadia
//ID  :- 154933212
//email:- vkapadia3@myseneca.ca
/////////////////////////////////////////////////////////////////

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include <cstring>
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"
namespace sdds {
   class LibApp {
      char m_filename[256];
      Publication *PPA[SDDS_LIBRARY_CAPACITY]{};
      int NOLP=0;
      int LLRN=0;
      bool m_changed=false;

      Menu m_publicationMenu{"Choose the type of publication:"};      
      Menu m_mainMenu{"Seneca Library Application"};
      Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};

      bool confirm(const char* message);
      void load(); 
      void save();   
      int search(int option,char type);  
      
      
      void newPublication();
      void removePublication();

      void checkOutPub();
      void returnPub();

      Publication* getPub(int libRef);

   public:
       LibApp();
       ~LibApp();
       LibApp(const char filename[256]);
       void run();      
   };
}
#endif // !SDDS_LIBAPP_H



