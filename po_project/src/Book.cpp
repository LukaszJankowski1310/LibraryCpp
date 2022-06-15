#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(string title, string author)
{
    this->title = title;
    this->author = author;

}

string Book::getTiltle() {
    return this->title;
}

string Book::getAuthor() {
    return this->author;
}

void Book::displayBook() {
 //   cout.width(10);
 //   cout << left << "Id";
    cout.width(45);
    cout << left << this->title;
    cout.width(45);
    cout << left << this->author;
 //   cout.width(10);
 //   cout << left << "Ilosc";


    //cout << this->title << " - " << this->author;

}

