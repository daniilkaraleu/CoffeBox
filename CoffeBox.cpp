#include <iostream>
#include <windows.h>

using namespace std;

double const PRICE_LATTE = 2.50;
double const PRICE_ESPRESSO = 2.50;
double const PRICE_CAPPUCCINO = 2.50;

double mainBalance = 0.0;
int numberOfCups = 0;

void printServiceMenu();

void callService();

void callMainMenu(double currentBalance);

double insertCoins();

void getCoffee(int choice);

void printCoffeeIsDone();

bool checkCurrentBalance(double currentBalance, double price);

void checkNumberOfCups();

int main() {
    int choice = 0;
    double balanceIncrement = 0;
    double currentBalance = 0;
    while (1) {
        callMainMenu(currentBalance);
        cin >> choice;

        if (choice == 0)
            callService();
        else if (choice == 1) {
            balanceIncrement = insertCoins();
            currentBalance += balanceIncrement;
            mainBalance += balanceIncrement;
        } else if (choice == 2) {
            if (checkCurrentBalance(currentBalance, PRICE_LATTE)) {
                checkNumberOfCups();
                getCoffee(choice);
                currentBalance -= PRICE_LATTE;
            }
        } else if (choice == 3) {
            if (checkCurrentBalance(currentBalance, PRICE_ESPRESSO)) {
                checkNumberOfCups();
                getCoffee(choice);
                currentBalance -= PRICE_ESPRESSO;
            }
        } else if (choice == 4) {
            if (checkCurrentBalance(currentBalance, PRICE_CAPPUCCINO)) {
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
    int choice = 0;

    while (1) {
        printServiceMenu();
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
    cout << endl;
    cout << "                Balance: " << currentBalance << " BYN" << endl;
    return;
}

void printServiceMenu() {
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
    double roubles = 0;
    double kopecks = 0;
    double balanceIncrement = 0;

    system("cls");
    cout << "Insert rouble coins" << endl;
    cin >> roubles;
    cout << "Insert kopeck coins" << endl;
    cin >> kopecks;

    balanceIncrement = roubles + kopecks / 100;
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

    return;
}

void checkNumberOfCups() {
    if (numberOfCups < 0)
        cout << "Sorry, out of cups";
    return;
}

