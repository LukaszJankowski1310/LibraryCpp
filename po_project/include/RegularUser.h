#ifndef REGULARUSER_H
#define REGULARUSER_H
#include <iostream>
#include "./User.h"
#include "./Book.h"
#include "./Library.h"
#include "./date.h"

using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;

typedef year_month_day Date;

class Library;


class RegularUser: public User
{
    public:
        RegularUser(string, string, int);
        void borrowBook(Library*, int);

        void zadanie1();

    protected:
    private:
        int bookLimit;

};

#endif // REGULARUSER_H
