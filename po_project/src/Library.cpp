#include "Library.h"
#include <iostream>



using namespace std;

Library::Library(string name)
{
    this->name = name;
    this->numberBooksInList = 0;
    this->idNewUser = 1;

}


void Library::addBook(string title, string author ) {
    Book b(title, author);
    this->numberBooksInList++;
    this->listBooks.push_back(b);
    this->amountBooks.push_back(0);

}


void Library::increaseNumberBook(int index, int number ) {
    if (index < 0 && index >= this->numberBooksInList) {
        return;
    }
    else {
        this->amountBooks[index] += number;
    }
}


void Library::addUser(string name, string surname, int userState) {
    /*int userState;
    cout << "Premium(1) / Zwykly(0)" << endl;
    cin >> userState;*/

    if (userState == 1)
    {
        User *preUser = new PremiumUser(name, surname, this->idNewUser);
        this->idNewUser++;
        this->users.push_back(preUser);

    }
    else if (userState == 0)
    {
         User *regUser = new RegularUser(name, surname, this->idNewUser);
         this->idNewUser++;
         this->users.push_back(regUser);
    }
    else
    {
        return;
    }

}


User* Library::getUserById(int id) {
    User* user;
    for (User* u : this->users) {
        if (u->getId() == id ) {
            user = u;
        }

    }

    return user;
}


bool Library::checkUserExists(int id) {

    for (User* u : this->users) {
        if (u->getId() == id) {
            //    cout << "sprawdzam" << endl;
            return true;
        }
    }

    return false;
}


void Library::deleteUser(int id) {

        for (int i = 0; i <= this->users.size(); i++) {
            if (this->users[i]->getId() == id) {
                users.erase(users.begin()+i);
                break;
            }
        }

    return;
}


void Library::displayUsers() {


    cout.width(10);
    cout << left << "Id";
    cout.width(25);
    cout << left << "Imie";
    cout.width(25);
    cout << left << "Nazwisko";
    cout << endl << endl;
    for (User* u : this->users) {
        u->displayUser();
        cout << endl;
    }
}


bool Library::checkBookExists(int id) {
    if (id >= 0 && id < this->numberBooksInList) return true;
    return false;
}


Book Library::getBookById(int id) {

    return this->listBooks[id];

}


int Library::getIdNewUser(){
    return this->idNewUser;
}


string Library::getName() {
    return this->name;

}


void Library::displayAllBooks() {

    cout.width(10);
    cout << left << "Id";
    cout.width(45);
    cout << left << "Tytul";
    cout.width(45);
    cout << left << "Autor";
    cout.width(10);
    cout << left << "Ilosc";

    cout << endl << endl;




    for (int i = 0; i < this->listBooks.size(); i++) {
        cout.width(10);
        cout << left << i;
        listBooks[i].displayBook();
        cout.width(10);
        cout << left << this->amountBooks[i];

        cout << endl;
      /*  cout << "Id: " << i << " ";
        listBooks[i].displayBook();
        cout << ": " << this->amountBooks[i] << endl;*/

    }

}


vector <int> Library::getAmountBooks() {

    return this->amountBooks;
}










