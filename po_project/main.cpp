#include <iostream>
#include "./include/Book.h"
#include "./include/Library.h"
#include "./include/User.h"
#include "./include/RegularUser.h"
#include "./include/PremiumUser.h"
#include "./include/date.h"
#include "./include/Menu.h"
#include "./include/utils.h"

using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
typedef year_month_day Date;





int main()
{

   Menu menu;
   Library* lib = menu.createLibrary();

   lib->addUser("Janusz", "Nowak", 0);
   lib->addUser("Jan", "Kowalski", 1);

   lib->addBook("Pan Tadeusz", "Adam Mickiewicz");
   lib->addBook("Quo Vadis ", "Henryk Sienkiewicz");

   lib->increaseNumberBook(0, 10);
   lib->increaseNumberBook(1, 15);


   menu.displayLibraryPanel(lib);

/*
    PremiumUser p("ds", "dsf", 2);
    PremiumUser p2("ds", "dsf", 2);

    PremiumUser p3 = p2 + p;




    User *u = new RegularUser("sd", "fsg", 5);
    User *u2 = new RegularUser("sd", "asd", 2);
    u->zadanie1();
    u2->zadanie1();
*/
    return 0;
}
