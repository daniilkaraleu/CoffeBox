#include <iostream>

using namespace std;

double const PRICE_LATTE = 2.50;
double const PRICE_ESPRESSO = 2.50;
double const PRICE_CAPPUCCINO = 2.50;

void callServiceMenu();
void callService();
void callMainMenu();

int main() {
    int choice = 0;
    while (1) {
        callMainMenu();
        cin >> choice;

        if (choice == 0)
            callService();
        else if (choice == 1) {

        } else if (choice == 2) {

        } else if (choice == 3) {

        } else if (choice == 4) {

        } else if (choice == -1) {
            break;
        } else{
            cout << "Error! Incorrect data.";
            return -1;
        }

    }
    return 0;
}

void callService() {
    int choice = 0;

    while (1) {
        callServiceMenu();
        cin >> choice;
    }

    return;
}

void callMainMenu(){
    cout << "Chose your option:\n" << endl;
    cout << "(1) Insert coins:      kopecks        roubles\n" << endl;
    cout << "(2) Make Latte       " << PRICE_LATTE << " BYN" << endl;
    cout << "(3) Make Espresso    " << PRICE_ESPRESSO << " BYN" << endl;
    cout << "(4) Make Cappuccino  " << PRICE_CAPPUCCINO << " BYN" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "(0) Service" << endl;
    cout << "(-1) Exit" << endl;

    return;
}

void callServiceMenu(){
    cout << "Chose your option:\n" << endl;
    cout << "(1) Show balance" << endl;
    cout << "(2) Check the number of coffee cups" << endl;
    cout << "(3) Withdraw proceeds" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "(-1) Exit" << endl;

    return;
}
