#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

double const PRICE_LATTE = 1.9;
double const PRICE_ESPRESSO = 1.5;
double const PRICE_CAPPUCCINO = 1.9;
int const PIN = 7815;
int const TIMES_REPEAT = 3;
int const SLEEP = 2500;
int const COFFEE_MAKING = 20;
int const MAX_OF_CUPS = 700;

double mainBalance = 0.0;
int numberOfCups = 7;
bool machineWasOpened = false;

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
void printDeposit(double balanceIncrement);

int main() {
    int choice = 0;
    double balanceIncrement = 0.0;
    double currentBalance = 0.0;

    while (true) {
        printMainMenu(currentBalance);
        cin >> choice;
        if (choice == 5) {
            if (checkPin()) {
                block();
            }
            if (machineWasOpened)
                currentBalance = 0;
            machineWasOpened = false;
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
            machineWasOpened = true;
        } else if (serviceChoice == 2) {
            getRevenue();
            machineWasOpened = true;
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
    if (cups + numberOfCups > MAX_OF_CUPS)
        cout << "Machine can't hold more cups";
    else
        numberOfCups += cups;
}

void getRevenue() {
    system("cls");
    cout << "Revenue withdrawn" << endl << endl;
    Sleep(SLEEP);
    mainBalance = 0;
}

double insertCoins() {
    double choice = 0.0;
    double balanceIncrement = 0.0;

    printCoinsMenu();
    cin >> choice;
    if (choice == 1) {
        balanceIncrement = 1;
        printDeposit(balanceIncrement);
    }
    else if (choice == 2){
        balanceIncrement = 2;
        printDeposit(balanceIncrement);
    }
    else if (choice == 3){
        balanceIncrement = 0.1;
        printDeposit(balanceIncrement);
    }
    else if (choice == 4){
        balanceIncrement = 0.2;
        printDeposit(balanceIncrement);
    }
    else if (choice == 5){
        balanceIncrement = 0.5;
        printDeposit(balanceIncrement);
    }
    else
        balanceIncrement = 0;

    return balanceIncrement;
}

void printCoffeeIsDone() {
    system("cls");
    cout << "Done!" << endl;
    cout << "Enjoy your coffee ^_^" << endl;
    Sleep(SLEEP);
}

bool checkCurrentBalance(double currentBalance, double price) {
    if (currentBalance < price) {
        system("cls");
        cout << "Not enough money on balance!" << endl;
        Sleep(SLEEP);
    } else {
        return true;
    }
    return false;
}

void getCoffee(int choice) {
    for (int i = COFFEE_MAKING; i > 0; --i) {
        system("cls");
        if (choice == 2)
            cout << "Making Latte..." << endl;
        if (choice == 3)
            cout << "Making Espresso..." << endl;
        if (choice == 4)
            cout << "Making Cappuccino..." << endl;
        cout << i << " seconds left\n";
        Sleep(SLEEP);
    }
    printCoffeeIsDone();
    numberOfCups--;
}

bool checkNumberOfCups() {
    if (numberOfCups < 1) {
        system("cls");
        cout << "Sorry, out of cups" << endl;
        Sleep(SLEEP);
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
            Sleep(SLEEP);
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
        Sleep(SLEEP);
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
void printDeposit(double balanceIncrement) {
    system("cls");
    if (balanceIncrement == 2 )
        cout << "Ok, " << balanceIncrement << " roubles was deposited" << endl;
    else if(balanceIncrement == 1)
        cout << "Ok, " << balanceIncrement << " rouble was deposited" << endl;
    else
        cout << "Ok, " << balanceIncrement * 100.0 << " kopecks was deposited" << endl;
    Sleep(SLEEP);
}