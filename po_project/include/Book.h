#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;

class Book
{
    public:
        Book(string, string);
        string getTiltle();
        string getAuthor();
        void displayBook();
    //    string getType();

    protected:
        string title;
        string author;
  //      string type;
    private:


};

#endif // BOOK_H
