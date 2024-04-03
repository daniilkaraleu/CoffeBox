#include <iostream>
#include <windows.h>

using namespace std;

double const PRICE_LATTE = 2.50;
double const PRICE_ESPRESSO = 2.50;
double const PRICE_CAPPUCCINO = 2.50;
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

void printBalance(double cashRemain);

void printCups(int numberOfCoffeeCups);

int main() {
    int choice = 0;
    double balanceIncrement = 0;
    double currentBalance = 0;
    while (1) {
        callMainMenu(currentBalance);
        cin >> choice;

        if (choice == 5)
            callService();
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

    int serviceEntranceChoise = 0;
    int serviceChoise = 0;
    int usersPIN = 0;
    int cups = 0;

    while (true) {

        system("clear");
        printServiceEntrance();
        cin >> serviceEntranceChoise;

        if (serviceEntranceChoise == 1) {
            system("clear");
            cout << "Please, enter PIN code: ";
            cin >> usersPIN;
            if (usersPIN == PIN) {
                while (true) {
                    system("clear");
                    printCups(numberOfCups);
                    printBalance(mainBalance);
                    printServiceMenu();
                    cin >> serviceChoise;
                    if (serviceChoise == 1) {
                        system("clear");
                        cout << "Please, insert cups: " << endl;
                        cin >> cups;
                        numberOfCups += cups;
                    }
                    else if (serviceChoise == 2) {
                        system("clear");
                        cout << "Revenue withdrawn" << endl << endl;
                        mainBalance = 0;
                        Sleep(1500);
                        continue;
                    }
                    else if (serviceChoise == 3){
                        break;
                    }
                    else {
                        system("clear");
                        cout << "Error! Incorrect input.";
                        Sleep(1500);
                        break;
                    }
                }
            }
            else {
                system("clear");
                cout << "Error! Incorrect PIN. Try again." << endl;
                Sleep(1500);
                continue;
            }
        }
        else if (serviceEntranceChoise == 2) {
            break;
        }
        else {
            system("clear");
            cout << "Error! Incorrect input.";
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
    system("clear");
    cout << "Service Entrance Menu" << endl;
    cout << "(1) Enter PIN" << endl << "(2) Exit" << endl;
}

void printServiceMenu() {  
    cout << "(1) Insert cups" << endl;
    cout << "(2) Withdraw proceeds" << endl;
    cout << "(3) Exit" << endl;
}

void printBalance(double cashRemain) {
    cout << "total revenue of the machine is " << cashRemain << " BYN" << endl;
}

void printCups(int numberOfCoffeeCups) {
    cout << "Current number of cups is " << numberOfCoffeeCups << " and"<< endl;
}

double insertCoins() {
    double roubles = 0;
    double kopecks = 0;
    double balanceIncrement = 0;

    system("cls");
    checkNumberOfCups();
    cout << "Insert rouble coins:" << endl;
    cin >> roubles;
    cout << "Insert kopeck coins:" << endl;
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
    numberOfCups--;

    return;
}

bool checkNumberOfCups() {
    if (numberOfCups < 1) {
        system("cls");
        cout << "Sorry, out of cups" << endl;
        Sleep(4000);
        return false;
    }
    return true;
}

