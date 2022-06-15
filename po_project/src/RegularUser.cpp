#include "RegularUser.h"



RegularUser::RegularUser(string name, string surname, int id): User(name, surname, id)
{
    this->bookLimit = 2;
    this->isPremium = false;

}


void RegularUser::borrowBook(Library* l, int id) {

    if (this->numberBorrowedBooks >= this->bookLimit) {
        cout << "Oddaj ksiazki ktore wypozyczyles !!";
        return;
    } else {

        if (l->getAmountBooks()[id] > 0) {


            this->numberBorrowedBooks++;
            Book b = l->getBookById(id);
            Date td = year_month_day{ ceil<days>(system_clock::now()) }; // aktualna data
            auto days_td = sys_days(td);
            auto days_td_diff = days_td + days{10};
            Date deadline = year_month_day{ days_td_diff };
            BorrowedBook borBook(b.getTiltle(), b.getAuthor(), id, deadline);
            this->borrowedBooks.push_back(borBook);
            l->increaseNumberBook(id, -1);
        } else {

            cout << "brakuje ksiazek";
        }
    }

}

void RegularUser::zadanie1() {
    cout << "Klasa pochodna";
    cout << this->id << " " << this->name;

}
