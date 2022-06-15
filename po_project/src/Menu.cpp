#include "Menu.h"


Menu::Menu()
{
 //   this->libraryPanel = false;
  //  this->userPanel = false;
}

Library* Menu::createLibrary() {
   //     this->libraryPanel = true;

        string name;
        cout << "Witaj! Stworz biblioteke" << endl;
        cout << "Podaj nazwe: ";
        getline(cin, name);
        Library* lib = new Library(name);
        system("cls");
        return lib;

}



void Menu::displayLibraryPanel(Library* lib) {
    int option;
    while (true) {


    cout <<"Witaj w bibliotece " << lib->getName() << " !" << endl << endl;

     cout << "1. Dodaj uzytkownika" << endl;
     cout << "2. Wyswietl wszystkich uzytkownikow" << endl;
     cout << "3. Zaloguj uzytkownika" << endl;
     cout << "4. Dodaj nowa ksiazke do biblioteki" << endl;
     cout << "5. Zwieksz liczbe ksiazek" << endl;
     cout << "6. Wyswietl stan biblioteki" << endl;
     cout << "7. Usun uzytkownika" << endl;
     cout << "8. Wyjdz" << endl;



    cout << endl << endl << endl;

    cout << "Wybierz opcje od 1 do 8 : ";
    option = getChoiceInt();

        if (option == 1) {
            system("cls");

            string name;
            string surname;
            int userState;
            int userId = lib->getIdNewUser();
            cout << "Dodawanie uzytkownika" << endl;
            cout << "Podaj imie: ";

            name = getChoiceString();

            cout << "Podaj nazwisko: ";

            surname = getChoiceString();
            cout << "Wpisz 1, jesli chcesz zalozyc konto premium, lub 0 jesli chcesz konto zwykle: ";
            userState = getChoiceInt();

            while (!(userState == 0 || userState == 1) ) {

                 cout << "Podaj poprawne dane: ";
                  userState = getChoiceInt();
            }

            lib->addUser(name, surname, userState);
            cout << endl;
            cout << "Witaj " <<  name << "! " << endl;
            cout << "Oto twoje id: " << userId << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;

            while (getch() != 13); // 13 = enter
            system("cls");

        } else if (option == 2) {
            system("cls");
            lib->displayUsers();
            cout << endl << endl;
            cout << "Wcisnij enter aby kontynuowac";

            while (getch() != 13); // 13 = enter
            system("cls");

        } else if (option == 3) {
            int id;
            system("cls");
            cout << "Logowanie uzytkownika" << endl;
            cout << "Podaj id: ";
            id = getChoiceInt();
            if (!(lib->checkUserExists(id))) {
                cout << "Uzytkownik o id: " << id << " nie istnieje" << endl << endl;

                cout << "Wcisnij enter aby kontynuowac" << endl;

                while (getch() != 13); // 13 = enter
                system("cls");
                this->displayLibraryPanel(lib);
                return;

            }
            else {
                system("cls");
                User* u = lib->getUserById(id);
                this->displayUserPanel(lib, u);
                return;
            }
        }



         else if (option == 4) {
             system("cls");
             string title;
             string author;

             cout << "Dodawanie ksiazki" << endl;

             cout << "Podaj tytul: ";
             getline(cin, title);
             cout << "Podaj autora: ";
             getline(cin, author);
             lib->addBook(title, author);
             cout << endl;
             cout << "Dodano ksiazke: " << endl;
             cout << "Tytul: " << title << endl;
             cout << "Autor: " << author  << endl << endl;

            cout << "Wcisnij enter aby kontynuowac" << endl;

            while (getch() != 13); // 13 = enter
            system("cls");


        }

        else if(option == 5) {
             system("cls");
             int id, amount;

             lib->displayAllBooks();
             cout << endl << endl;
             cout << "Podaj id ksiazki: ";
             id = getChoiceInt();

            if (!lib->checkBookExists(id)) {
                cout << "Ksiazka o id: " << id << " nie istnieje" << endl << endl;

                cout << "Wcisnij enter aby kontynuowac" << endl;

                while (getch() != 13); // 13 = enter
                system("cls");
                this->displayLibraryPanel(lib);
                return;

            }

            else {
                cout << "Podaj ilosc: ";
                amount = getChoiceInt();
                lib->increaseNumberBook(id, amount);

            }


             cout << "Wcisnij enter aby kontynuowac" << endl;

             while (getch() != 13); // 13 = enter
             system("cls");


        }


        else if (option == 6) {
            system("cls");
            cout << "Oto dostepne ksiazki" << endl << endl;
            lib->displayAllBooks();
            cout << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;

            while (getch() != 13); // 13 = enter
            system("cls");


        }

        else if (option == 7) {

            int id;
            system("cls");
            cout << "Usuwanie uzytkownika" << endl;
            cout << "Podaj id: ";
            id = getChoiceInt();
            if (!(lib->checkUserExists(id))) {
                cout << "Uzytkownik o id: " << id << " nie istnieje" << endl << endl;

                cout << "Wcisnij enter aby kontynuowac" << endl;

                while (getch() != 13); // 13 = enter
                system("cls");
                this->displayLibraryPanel(lib);
                return;

            }
            else {

                lib->deleteUser(id);

                cout << "Uzytkownik zostal usuniety" << endl << endl;
                cout << "Wcisnij enter aby kontynuowac" << endl;

                 while (getch() != 13); // 13 = enter
                system("cls");


            }



        }

        else if (option == 8) {
            system("cls");
             break;
            return;
        }



         else {
           // if ()
            system("cls");
        }

    }

}

void Menu::displayUserPanel(Library* lib, User* user) {


    int option;
    while (true) {


    cout << "Witaj " << user->getName() << " " << user->getSurname() << endl;

    cout << "1. Wypozycz ksiazke" << endl;
    cout << "2. Wyswietl wypozyczone ksiazki" << endl;
    cout << "3. Oddaj ksiazke" << endl;
    cout << "4. Zaaktualizuj dane osobowe" << endl;
    cout << "5. Przedluz czas wypozyczenia ksiazki" << endl;
    cout << "6. Wyjdz" << endl;

    cout << endl << endl << endl;

    cout << "Wybierz opcje od 1 do 6 : ";
    option = getChoiceInt();

    if (option == 1) {
        system("cls");
        int id;
        cout << "Oto dostepne ksiazki" << endl;

        lib->displayAllBooks();

        cout << "Podaj id ksiazki, ktora chcesz wypozyczyc: ";
        id = getChoiceInt();

        if (!lib->checkBookExists(id)) {
            cout << "Ksiazka o tym id nie istnieje" << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");
        } else {
            user->borrowBook(lib, id);
            cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");
        }


    } else if (option == 2) {
         system("cls");
         user->displayBorrowedBooks();
         cout << endl << endl;
         cout << "Wcisnij enter aby kontynuowac" << endl;
         while (getch() != 13); // 13 = enter
         system("cls");


    } else if (option == 3) {
        system("cls");
        user->displayBorrowedBooks();
        int id;
        cout << "Podaj id ksiazki ktora chcesz oddac: ";
        id = getChoiceInt();

        if (id >= user->getNumberBorrowedBooks() || id < 0) {
            cout << "Ksiazka o tym id nie istnieje" << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");
        } else {

            BorrowedBook* bb = user->getBorrowedBookById(id);
            lib->increaseNumberBook(bb->getId(), 1);
            user->giveBackBook(id);


            cout << "Udalo sie oddac ksiazke" << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");

        }


    } else if (option == 4) {
            system("cls");
            string name;
            string surname;
            cout << "Podaj imie: ";
            name = getChoiceString();
            cout << "Podaj nazwisko: ";
            surname = getChoiceString();

            user->setName(name);
            user->setSurname(surname);
            cout << endl;
            cout << "Zaktualnowano dane" << endl << endl;
             cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");



    }
    else if (option == 5)  {
        system("cls");
        user->displayBorrowedBooks();
        int id;
        cout << "Podaj id ksiazki, ktorej chcesz przedluzyc czas wypozyczenia: ";
        id = getChoiceInt();
        if (id >= user->getNumberBorrowedBooks() || id < 0) {
            cout << "Ksiazka o tym id nie istnieje" << endl << endl;
            cout << "Wcisnij enter aby kontynuowac" << endl;
            while (getch() != 13); // 13 = enter
            system("cls");
        } else {

        BorrowedBook* b = user->getBorrowedBookById(id);
        b->extendTime(7);

        cout << "Przedluzono czas do: " << b->getDeadline();

        cout << endl << endl;
        cout << "Wcisnij enter aby kontynuowac" << endl;
        while (getch() != 13); // 13 = enter
        system("cls");

        }

    }

    else if (option == 6) {
        system("cls");
        this->displayLibraryPanel(lib);
        return;
    }
    else {
        system("cls");
    }



    }



}


