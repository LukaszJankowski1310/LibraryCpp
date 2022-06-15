#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include "./BorrowedBook.h"




using namespace std;

class Library;

class User
{
    public:
        User(string, string, int);

        // settery
        void setName(string);
        void setSurname(string);
        // gettery
        int getId();
        string getName();
        string getSurname();
        bool getIsPremium();
        int getNumberBorrowedBooks();

        void giveBackBook(int); // oddaje ksiazke
        void displayBorrowedBooks();
        BorrowedBook* getBorrowedBookById(int);


        virtual void displayUser();
        virtual void borrowBook(Library*, int);

        virtual void zadanie1();



    protected:
        string name;
        string surname;
        int id;
        int numberBorrowedBooks; // l wypozyczych ksiazek
        vector <BorrowedBook> borrowedBooks;
        bool isPremium;

    private:
};

#endif // USER_H
