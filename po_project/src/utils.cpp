#include "utils.h"


int getChoiceInt() {

    int choice;
    cin >> setw(1) >> choice;

    while (!cin.good() || choice < 0 ) {


        cout << "Podaj poprawne dane: ";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin >> setw(1) >> choice;
    }
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return choice;
}

string getChoiceString() {

    string choice;
    cin >> setw(15) >> choice;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return choice;
}



