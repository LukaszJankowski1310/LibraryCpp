#include "PremiumUser.h"

PremiumUser::PremiumUser(string name, string surname, int id): User(name, surname, id)
{
    this->isPremium = true;
}



void PremiumUser::displayUser() {
    //cout <<"*** Imie: " << this->name << "Nazwisko: " << this->surname << "Id: " << this->id << "***" << endl;

    cout.width(10);
    cout << left << this->id;
    cout.width(25);
    cout << left << this->name;
    cout.width(25);
    cout << left << this->surname;
    cout << "***";
}


void PremiumUser::borrowBook(Library* l, int id) {

        if (l->getAmountBooks()[id] > 0) {


        this->numberBorrowedBooks++;
        Book b = l->getBookById(id);
        Date td = year_month_day{ ceil<days>(system_clock::now()) }; // aktualna data
        auto days_td = sys_days(td);
        auto days_td_diff = days_td + days{30};
        Date deadline = year_month_day{ days_td_diff };
        BorrowedBook borBook(b.getTiltle(), b.getAuthor(), id , deadline);
        this->borrowedBooks.push_back(borBook);
        l->increaseNumberBook(id, -1);

        } else {
            cout << "brakuje ksiazek";
        }

}


void PremiumUser::zadanie1() {
    cout << "Klasa pochodna";
    cout << this->id << " " << this->name;

}

PremiumUser PremiumUser::operator+(PremiumUser u2) {
    return PremiumUser{this->name, this->surname, this->id + u2.getId()};
}

