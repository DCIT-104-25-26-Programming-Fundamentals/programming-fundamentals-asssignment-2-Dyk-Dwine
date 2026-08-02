// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to display the calculator menu and get the user's choice
int displayMenu() {
    cout << "============================\n";
    cout << "     SIMPLE CALCULATOR\n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
    cout << "Select an operation (1-7): ";

    int choice;
    cin >> choice;
    return choice;
}

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}
// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return NAN; // Return NaN to indicate an error
    }
    return a / b;
}

// Function to perform modulus
int modulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
        return 0; // Return 0 to indicate an error
    }
    return a % b;
}

// Function to perform exponentiation
double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

// Main function
int main() {
    bool running = true;

    while (running) {
        int choice = displayMenu();

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        double num1, num2, result;
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                cout << fixed << setprecision(2) << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2:
                result = subtract(num1, num2);
                cout << fixed << setprecision(2) << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3:
                result = multiply(num1, num2);
                cout << fixed << setprecision(2) << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4:
                result = divide(num1, num2);
                if (!isnan(result)) {
                    cout << fixed << setprecision(2) << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            case 5:
                if (static_cast<int>(num1) != num1 || static_cast<int>(num2) != num2) {
                    cout << "Error: Modulus operation requires integer inputs." << endl;
                    break;
                }
                result = modulus(static_cast<int>(num1), static_cast<int>(num2));
                if (num2 != 0) {
                    cout << static_cast<int>(num1) << " % " << static_cast<int>(num2) << " = " << static_cast<int>(result) << endl;
                }
                break;
            case 6:
                result = exponentiate(num1, num2);
                cout << fixed << setprecision(2) << num1 << " ^ " << num2 << " = " << result << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please select a number between 1 and 7." << endl;
        }
    }

    return 0;
}