#include <iostream>
#include <windows.h>

using namespace std;

double const PRICE_LATTE = 2.50;
double const PRICE_ESPRESSO = 2.50;
double const PRICE_CAPPUCCINO = 2.50;

double mainBalance = 0.0;

void callServiceMenu();

void callService();

void callMainMenu(double currentBalance);

double insertCoins();

void getLatte();

void getEspresso();

void getCappuccino();

void printCoffeeIsDone();

bool checkCurrentBalance(double currentBalance, double price);

int main() {
    int choice = 0;
    double currentBalance = 0;
    while (1) {
        callMainMenu(currentBalance);
        cin >> choice;

        if (choice == 0)
            callService();
        else if (choice == 1) {
            currentBalance += insertCoins();
            mainBalance += insertCoins();
        } else if (choice == 2) {
            if (checkCurrentBalance(currentBalance, PRICE_LATTE)){
                getLatte();
                currentBalance -= PRICE_LATTE;
            }
        } else if (choice == 3) {
            if (checkCurrentBalance(currentBalance, PRICE_ESPRESSO)){
                getEspresso();
                currentBalance -= PRICE_ESPRESSO;
            }
        } else if (choice == 4) {
            if (checkCurrentBalance(currentBalance, PRICE_CAPPUCCINO)){
                getCappuccino();
                currentBalance -= PRICE_CAPPUCCINO;
            }
        } else if (choice == -1) {
            break;
        } else {
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

void callMainMenu(double currentBalance) {
    system("cls");
    cout << "Choose your option:\n" << endl;
    cout << "(1) Insert coins:      kopecks        roubles\n" << endl;
    cout << "(2) Make Latte       " << PRICE_LATTE << " BYN" << endl;
    cout << "(3) Make Espresso    " << PRICE_ESPRESSO << " BYN" << endl;
    cout << "(4) Make Cappuccino  " << PRICE_CAPPUCCINO << " BYN" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "(0) Service" << endl;
    cout << "(-1) Exit" << endl;
    cout << endl;
    cout << "             Balance: " << currentBalance << " BYN" << endl;
    return;
}

void callServiceMenu() {
    system("cls");
    cout << "Choose your option:\n" << endl;
    cout << "(1) Show balance" << endl;
    cout << "(2) Check the number of coffee cups" << endl;
    cout << "(3) Withdraw proceeds" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "(-1) Exit" << endl;

    return;
}

double insertCoins() {
    return 5;
}

void getLatte() {
    for (int i = 20; i > 0; --i) {
        system("cls");
        cout << "Making latte..." << endl;
        cout << i << " seconds left\n";
        Sleep(1000);
    }
    printCoffeeIsDone();

}

void getEspresso() {
    for (int i = 20; i > 0; --i) {
        system("cls");
        cout << "Making espresso..." << endl;
        cout << i << " seconds left\n";
        Sleep(1000);
    }
    printCoffeeIsDone();

}

void getCappuccino() {
    for (int i = 20; i > 0; --i) {
        system("cls");
        cout << "Making cappuccino..." << endl;
        cout << i << " seconds left\n";
        Sleep(1000);
    }
    printCoffeeIsDone();
}

void printCoffeeIsDone() {
    system("cls");
    cout << "Done!" << endl;
    cout << "Enjoy your coffee ^_^" << endl;
    Sleep(4000);
}

bool checkCurrentBalance(double currentBalance, double price){
    if (currentBalance < price){
        system("cls");
        cout << "Not enough money on balance!" << endl;
    } else {
        return true;
    }
    Sleep(4000);
    return false;
}
