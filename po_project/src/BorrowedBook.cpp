#include "BorrowedBook.h"
#include "Book.h"

BorrowedBook::BorrowedBook(string title, string author, int id, Date deadline):Book(title, author)
{
    this->deadline = deadline;
    this->id = id;
}

int BorrowedBook::getId(){
    return this->id;

}

Date BorrowedBook::getDeadline() {

    return this->deadline;
}

void BorrowedBook::extendTime(int numOfDays) {


    auto nd = sys_days(this->deadline);
    nd = nd + days{numOfDays};
    this->deadline = year_month_day{nd};

}

void BorrowedBook::displayBorrowedBook() {

    cout.width(45);
    cout << left << this->title;
    cout.width(45);
    cout << left << this->author;
    cout.width(45);
    cout << left << this->deadline;

}
