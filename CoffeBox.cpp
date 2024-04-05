#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

double const PRICE_LATTE = 1.9;
double const PRICE_ESPRESSO = 1.9;
double const PRICE_CAPPUCCINO = 1.9;
int const PIN = 7815;
int const TIMES_REPEAT = 3;

double mainBalance = 0.0;
int numberOfCups = 2;

void printServiceMenu();

void callService();

void printMainMenu(double currentBalance);

double insertCoins();

void getCoffee(int choice);

void printCoffeeIsDone();

bool checkCurrentBalance(double currentBalance, double price);

bool checkNumberOfCups();

void printServiceEntrance();

void addCups();

void getRevenue();

bool checkPin();

void block();

void printCoinsMenu();

int main() {
    int choice = 0;
    double balanceIncrement = 0;
    double currentBalance = 0;

    while (true) {
        printMainMenu(currentBalance);
        cin >> choice;

        if (choice == 5) {
            if (checkPin()) {
                block();
            }
        } else if (choice == 1) {
            if (checkNumberOfCups()) {
                balanceIncrement = insertCoins();
                currentBalance += balanceIncrement;
                mainBalance += balanceIncrement;
            }
        } else if (choice == 2) {
            if (checkCurrentBalance(currentBalance, PRICE_LATTE) and checkNumberOfCups()) {
                getCoffee(choice);
                currentBalance -= PRICE_LATTE;
            }
        } else if (choice == 3) {
            if (checkCurrentBalance(currentBalance, PRICE_ESPRESSO) and checkNumberOfCups()) {
                getCoffee(choice);
                currentBalance -= PRICE_ESPRESSO;
            }
        } else if (choice == 4) {
            if (checkCurrentBalance(currentBalance, PRICE_CAPPUCCINO) and checkNumberOfCups()) {
                getCoffee(choice);
                currentBalance -= PRICE_CAPPUCCINO;
            }
        } else if (choice == -1) {
            break;
        } else {
            continue;
        }

    }
    return 0;
}

void callService() {

    int serviceChoice = 0;

    while (true) {
        system("cls");
        printServiceMenu();
        cin >> serviceChoice;

        if (serviceChoice == 1) {
            addCups();
        } else if (serviceChoice == 2) {
            getRevenue();
            continue;
        } else if (serviceChoice == 3) {
            break;
        } else {
            break;
        }
    }
}

void printMainMenu(double currentBalance) {
    if (currentBalance < 0.01)
        currentBalance = round(currentBalance);
    system("cls");
    cout << "Balance: " << currentBalance << " BYN" << endl;
    cout << "(1) Insert coins" << endl;
    cout << "(2) Make Latte       " << PRICE_LATTE << " BYN" << endl;
    cout << "(3) Make Espresso    " << PRICE_ESPRESSO << " BYN" << endl;
    cout << "(4) Make Cappuccino  " << PRICE_CAPPUCCINO << " BYN" << endl;
    cout << "(5) Service" << endl;
}

void printServiceEntrance() {
    system("cls");
    cout << "Service Entrance Menu" << endl;
    cout << "Enter PIN: ";
}

void printServiceMenu() {
    cout << "Current number of cups is " << numberOfCups << " and" << endl;
    cout << "total revenue of the machine is " << mainBalance << " BYN" << endl;
    cout << "(1) Insert cups" << endl;
    cout << "(2) Withdraw proceeds" << endl;
    cout << "(3) Exit" << endl;
}

void addCups() {
    system("cls");
    int cups = 0;
    cout << "Please, insert cups: " << endl;
    cin >> cups;
    numberOfCups += cups;
}

void getRevenue() {
    system("cls");
    cout << "Revenue withdrawn" << endl << endl;
    Sleep(1500);
    mainBalance = 0;
}

double insertCoins() {
    double choice = 0;
    double balanceIncrement = 0;

    printCoinsMenu();
    cin >> choice;
    if (choice == 1)
        balanceIncrement = 1;
    else if (choice == 2)
        balanceIncrement = 2;
    else if (choice == 3)
        balanceIncrement = 0.1;
    else if (choice == 4)
        balanceIncrement = 0.2;
    else
        balanceIncrement = 0.5;

    return balanceIncrement;
}

void printCoffeeIsDone() {
    system("cls");
    cout << "Done!" << endl;
    cout << "Enjoy your coffee ^_^" << endl;
    Sleep(4000);
}

bool checkCurrentBalance(double currentBalance, double price) {
    if (currentBalance < price) {
        system("cls");
        cout << "Not enough money on balance!" << endl;
        Sleep(4000);
    } else {
        return true;
    }
    return false;
}

void getCoffee(int choice) {
    for (int i = 20; i > 0; --i) {
        system("cls");
        if (choice == 2)
            cout << "Making Latte..." << endl;
        if (choice == 3)
            cout << "Making Espresso..." << endl;
        if (choice == 4)
            cout << "Making Cappuccino..." << endl;
        cout << i << " seconds left\n";
        Sleep(1000);
    }
    printCoffeeIsDone();
    numberOfCups--;
}

bool checkNumberOfCups() {
    if (numberOfCups < 1) {
        system("cls");
        cout << "Sorry, out of cups" << endl;
        Sleep(3500);
        return false;
    }
    return true;
}

bool checkPin() {
    int counter = 0;

    int usersPIN = 0;
    while (counter < TIMES_REPEAT) {
        printServiceEntrance();
        cin >> usersPIN;
        if (usersPIN == PIN) {
            callService();
            break;
        } else {
            system("cls");
            cout << "Incorrect PIN\n";
            Sleep(2500);
            counter++;
        }
    }
    if (counter >= TIMES_REPEAT) {
        return true;
    }
    return false;
}

void block() {
    while (true) {
        system("cls");
        cout << "Machine is locked" << endl;
        Sleep(1000);
    }
}

void printCoinsMenu() {
    system("cls");
    cout << "Insert rouble coin or kopeck coin:" << endl;
    cout << "(1) 1 rouble" << endl;
    cout << "(2) 2 roubles" << endl;
    cout << "(3) 10 kopecks" << endl;
    cout << "(4) 20 kopecks" << endl;
    cout << "(5) 50 kopecks" << endl;
}