#include <iostream>

using namespace std;

double const priceLatte = 2.50;
double const priceEspresso = 2.50;
double const priceCappuccino = 2.50;

void callService();

int main(){
    int choice = 0;
    while (1){
        cout << "Chose your option:\n" << endl;
        cout << "(1) Insert coins:\nkopecks[1..50]\nroubles[1,2]" << endl;
        cout << "(2) Make Latte       ["<< priceLatte <<"]" << endl;
        cout << "(3) Make Espresso    ["<< priceEspresso <<"]"<< endl;
        cout << "(4) Make Cappuccino  ["<< priceCappuccino <<"]" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "(0) Service" << endl;
        cout << "(-1) Exit" << endl;
        callService();
        cin >> choice;

    }
    return 0;
}

void callService(){
    int choice = 0;

    while (1){
        cout << "Chose your option:\n" << endl;
        cout << "(1) Show balance" << endl;
        cout << "(2) Check the number of coffee cups" << endl;
        cout << "(3) Withdraw proceeds" << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "(-1) Exit" << endl;
        cin >> choice;

    }

    return ;
}