#include "./Book.h"
#include "./date.h"
#ifndef BORROWEDBOOK_H
#define BORROWEDBOOK_H

using namespace std;
using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;

typedef year_month_day Date;


class BorrowedBook:public Book
{
    public:
        BorrowedBook(string, string, int, Date);
        void extendTime(int);
        int getId();
        Date getDeadline();
        void displayBorrowedBook();

    protected:
    private:
        int id;
        Date deadline;


};

#endif // BORROWEDBOOK_H
