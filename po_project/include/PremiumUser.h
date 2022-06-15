#ifndef PREMIUMUSER_H
#define PREMIUMUSER_H
#include <iostream>
#include "./User.h"
#include "./Library.h"

using namespace std;

class Library;


class PremiumUser: public User
{
    public:
        PremiumUser(string, string, int);

         void displayUser();
         void borrowBook(Library*, int);


//         PremiumUser operator+(string, string, int);

          void zadanie1();
          PremiumUser operator+(PremiumUser u2);


    protected:
    private:

};

#endif // PREMIUMUSER_H

