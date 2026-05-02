#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "******** SIMPLE CALCULATOR *********" << endl;

    // Input numbers
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Choose operation
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    // Perform calculation
    switch(operation) {
        case '+':
            cout << "Result = " << num1 + num2;
            break;

        case '-':
            cout << "Result = " << num1 - num2;
            break;

        case '*':
            cout << "Result = " << num1 * num2;
            break;

        case '/':
            if(num2 != 0){
                cout << "Result = " << num1 / num2;
            }
            else{
                cout << "Error: Division by zero!";
            break;
            }

        default:
            cout << "Invalid operation!";
    }
     
    return 0;
}