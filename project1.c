#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

// Function to safely read a number
double getNumber(string message) {
    double num;

    while (true) {
        cout << message;

        if (cin >> num && isfinite(num)) {
            return num;
        }

        cout << "Invalid input! Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    int choice;
    double num1, num2, result;

    cout << "====================================\n";
    cout << "       BASIC CALCULATOR (C++)\n";
    cout << "====================================\n";

    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Modulus (%)\n";
        cout << "0. Exit\n";
        cout << "----------------------------\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice! Enter a number from 0 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0) {
            cout << "\nThank you for using the calculator!\n";
            break;
        }

        if (choice < 0 || choice > 5) {
            cout << "Invalid choice! Please select 0 to 5.\n";
            continue;
        }

        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case 2:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;

            case 3:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case 4:
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed!\n";
                } else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;

            case 5:
                if (num2 == 0) {
                    cout << "Error: Modulus by zero is not allowed!\n";
                } else {
                    result = fmod(num1, num2);
                    cout << "Result: " << result << endl;
                }
                break;
        }

    } while (true);

    return 0;
}

