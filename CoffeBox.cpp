#include <iostream>
#include <windows.h>

using namespace std;

double const PRICE_LATTE = 1.9;
double const PRICE_ESPRESSO = 1.9;
double const PRICE_CAPPUCCINO = 1.9;
int const PIN = 7815;

double mainBalance = 0.0;
int numberOfCups = 1;

void printServiceMenu();

void callService();

void callMainMenu(double currentBalance);

double insertCoins();

void getCoffee(int choice);

void printCoffeeIsDone();

bool checkCurrentBalance(double currentBalance, double price);

bool checkNumberOfCups();

void printServiceEntrance();

void addCups();

void getRevenue();

int main() {
    int choice = 0;
    double balanceIncrement = 0;
    double currentBalance = 0;
    int usersPIN = 0;
    while (1) {
        callMainMenu(currentBalance);
        cin >> choice;

        if (choice == 5){
            printServiceEntrance();
            cin >> usersPIN;
            if (usersPIN == PIN)
                callService();
            else{
                system("cls");
                cout << "Incorrect PIN. Try again\n";
                Sleep(2500);
            }
            continue;
        }
        else if (choice == 1) {
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
                checkNumberOfCups();
                getCoffee(choice);
                currentBalance -= PRICE_ESPRESSO;
            }
        } else if (choice == 4) {
            if (checkCurrentBalance(currentBalance, PRICE_CAPPUCCINO) and checkNumberOfCups()) {
                checkNumberOfCups();
                getCoffee(choice);
                currentBalance -= PRICE_CAPPUCCINO;
            }
        } else if (choice == -1) {
            break;
        } else {
            system("cls");
            cout << "Error! Incorrect data.";
            Sleep(3000);
        }

    }
    return 0;
}

void callService() {

    int serviceChoise = 0;

    while (true) {

        system("cls");
        printServiceMenu();
        cin >> serviceChoise;

        if (serviceChoise == 1) {
            addCups();
        }
        else if (serviceChoise == 2) {
            getRevenue();
            continue;
        }
        else if (serviceChoise == 3){
            break;
        }
        else {
            system("cls");
            cout << "Error! Incorrect input.";
            Sleep(1500);
            break;
        }
    }
}

void callMainMenu(double currentBalance) {
    system("cls");
    cout << "Balance: " << currentBalance << " BYN" << endl;
    cout << "(1) Insert coins" << endl;
    cout << "(2) Make Latte       " << PRICE_LATTE << " BYN" << endl;
    cout << "(3) Make Espresso    " << PRICE_ESPRESSO << " BYN" << endl;
    cout << "(4) Make Cappuccino  " << PRICE_CAPPUCCINO << " BYN" << endl;
    cout << "(5) Service" << endl;
    return;
}

void printServiceEntrance() {
    system("cls");
    cout << "Service Entrance Menu" << endl;
    cout << "Enter PIN: ";
}

void printServiceMenu() {
    cout << "Current number of cups is " << numberOfCups << " and"<< endl;
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
    double coins = 0;
    double balanceIncrement = 0;

    system("cls");
    checkNumberOfCups();
    cout << "Insert rouble coin[1, 2] or kopeck coin[10, 20, 50]" << endl;
    cin >> coins;

    if (coins > 2)
        balanceIncrement = coins / 100;
    else
        balanceIncrement = coins;
    return balanceIncrement;
}//
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
    } else {
        return true;
    }
    Sleep(4000);
    return false;
}

void getCoffee(int choice) {
    for (int i = 20; i > 0; --i) {
        system("cls");
        if (choice == 2)
            cout << "Making Latte..." << endl;
        if (choice == 3)
            cout << "Making Espresso" << endl;
        if (choice == 4)
            cout << "Making Cappuccino" << endl;
        cout << i << " seconds left\n";
        Sleep(1000);
    }
    printCoffeeIsDone();
    numberOfCups--;

    return;
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