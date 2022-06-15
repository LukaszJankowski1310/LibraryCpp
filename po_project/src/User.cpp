#include "User.h"

User::User(string name, string surname, int id)
{
    this->name = name;
    this->surname = surname;
    this->id = id;
    this->numberBorrowedBooks = 0;
}

int User::getId() {
    return this->id;
}

string User::getName() {
    return this->name;
}

string User::getSurname() {

    return this->surname;
}

bool User::getIsPremium() {

    return this->isPremium;
}


void User::setName(string name){
    this->name = name;
}

void User::setSurname(string surname){
    this->surname = surname;
}


void User::displayUser() {
   // cout << "Klasa user" << endl;

    cout.width(10);
    cout << left << this->id;
    cout.width(25);
    cout << left << this->name;
    cout.width(25);
    cout << left << this->surname;

}

void User::displayBorrowedBooks() {
    cout.width(10);
    cout << left << "Id";
    cout.width(45);
    cout << left << "Tytul";
    cout.width(45);
    cout << left << "Autor";
    cout.width(45);
    cout << left << "Data oddania";

    cout << endl << endl;

    for (int i = 0; i < this->borrowedBooks.size(); i++) {
        cout.width(10);
        cout << left << i;
        this->borrowedBooks[i].displayBorrowedBook();
        cout << endl;

    }

}

void User::borrowBook(Library*, int) {
    return;
}

void User::giveBackBook(int id) {
        int index = this->borrowedBooks[id].getId();
   //     cout << "givebackbook func id: " <<index << endl;
     //   lib->displayUsers();

        this->borrowedBooks.erase(borrowedBooks.begin()+id);

}

BorrowedBook* User::getBorrowedBookById(int id) {
    return &this->borrowedBooks[id];

}

int User::getNumberBorrowedBooks() {
    return this->numberBorrowedBooks;
}


void User::zadanie1() {
    cout << "Klasa bazowa";
    cout << "imie: " << this->name << "id: " << this->id;
}



