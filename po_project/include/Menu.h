#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "./Book.h"
#include "./Library.h"
#include "./User.h"
#include "./RegularUser.h"
#include "./PremiumUser.h"
#include "./date.h"
#include "./Menu.h"
#include "./utils.h"
#include "windows.h"
#include <conio.h>


using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
typedef year_month_day Date;


class Menu
{
    public:
        Menu();
        Library* createLibrary();
       // void addUser(Library*);
        void displayLibraryPanel(Library*);
        void displayUserPanel(Library*, User*);
     //   void cso(Library*);
    protected:

    private:
    //   bool userPanel;
      //  bool libraryPanel;

};




#endif // MENU_H
