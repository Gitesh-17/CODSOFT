#include <iostream>
using namespace std;
int main()
{
    double num1, num2;
    char operation;
    double result = 0;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        cout << "Invalid operation selected!" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}