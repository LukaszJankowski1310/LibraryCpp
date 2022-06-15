#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <vector>
#include <map>
#include "./PremiumUser.h"
#include "./RegularUser.h"
#include "./Book.h"
#include "./User.h"

using namespace std;
class User;
class Library
{
    public:
        Library(string); //
        bool checkUserExists(int);
        void addUser(string, string, int); //
        void deleteUser(int);
        void addBook(string, string); //
        void increaseNumberBook(int, int); //
        User* getUserById(int); // szuka po id
        void displayUsers();
        bool checkBookExists(int); // sprawdza czy ksiazka z danym id istinieje
        Book getBookById(int); // zwraca ksiazke po id
        int getIdNewUser();
        string getName();
        void displayAllBooks();
        vector <int> getAmountBooks();

    protected:

    private:
        string name; // nazwa biblioteki
        vector <User*> users; // uzytkownicy
        vector <Book> listBooks; // baza ksiazek
        vector <int> amountBooks; // liczba poszczegolnych ksiazek
        int numberBooksInList;  // dlugosc wektora bazy ksiazek
        int idNewUser; // id nowego usera
   //     int loggedUser;

};

#endif // LIBRARY_H
