// CS162 Project 1
// Written by: Jenna Hildebrand
// Date: Aptil 8 2017
// Sources: Stack Overflow

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

double enterItems();
double getTotal(double total);
double checkOut(double total);
void abortProgram();

int main() {
    char action;
    double total;

    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Welcome to your personal shopping calculator." << endl;

    bool done = false;
    while (done != true) {
        cout << "Would you like to A) enter items; B) see your current total or Q) quit and check out? ";
        cin >> action;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (toupper(action)) {
            case 'A': 
              total = total + enterItems();
              break;
            case 'B': 
              getTotal(total);
              break;
            case 'Q':
              done = true;
              checkOut(total);
              break;
            default:
              cout << "Please select either A, B or Q." << endl;
          }
      }
    return 0;
}

double enterItems() {
    char reply;
    char itemName[101];
    double itemPrice;
    double total;

    
    while (toupper(reply) != 'Y') {
        cout << "Item name: ";
        cin.getline(itemName, 101);
        cout << "Item price: $";
        cin >> itemPrice; 

        // make sure itemPrice is numeric
        if(cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input! Please input a numerical value for price." << endl;
            cin >> itemPrice;
        }

        cout << "Is this correct? (Y/N)" << endl;
        cout << "Item: " << itemName << endl;
        cout << "Price: $" << itemPrice << endl;
        cin >> reply;
        switch (toupper(reply)) {
            case 'Y': {
              cout << "Item added." << endl;
              total = total + itemPrice;
              cout << "Your current total is " << total << endl;
              break;
            }
            case 'N': 
              cout << "Please correct any mistakes and resubmit the item." << endl;
              break;
            default: 
              cout << "Please enter Y or N: " << endl;
              break;
        }
    }

    return total; 

}

double getTotal(double total) {
    cout << "Your current total is: " << total << endl;

    return total;
}

double checkOut(double total) {
    double grandTotal = getTotal(total);

    cout << "Your grand total is: $" << grandTotal << endl;
    abortProgram();
}

// This function stops the program 'flashing' off the screen.
void abortProgram() {
    char reply;

    cout << "Press q (or any other key) followed by 'Enter' to quit and check out:";
    cin >> reply;
    exit(1);
}

