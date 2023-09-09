#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    string operation;
    double num1, num2;

    cout << "Введите операцию (+, -, *, /, sin, cos, sqrt, pow, exp, fact, tan, cot, %): ";
    cin >> operation;

    if (operation == "sin" || operation == "cos" || operation == "sqrt" || operation == "pow" || operation == "exp" || operation == "tan" || operation == "cot" || operation == "%") {
        cout << "Введите число: ";
        cin >> num1;

        if (operation == "sin") {
            cout << "sin(" << num1 << ") = " << sin(num1) << endl;
        } else if (operation == "cos") {
            cout << "cos(" << num1 << ") = " << cos(num1) << endl;
        } else if (operation == "sqrt") {
            cout << "sqrt(" << num1 << ") = " << sqrt(num1) << endl;
        } else if (operation == "pow") {
            cout << "Введите степень: ";
            cin >> num2;
            cout << num1 << "^" << num2 << " = " << pow(num1, num2) << endl;
        } else if (operation == "exp") {
            cout << "exp(" << num1 << ") = " << exp(num1) << endl;
        } else if (operation == "tan") {
            cout << "tan(" << num1 << ") = " << tan(num1) << endl;
        } else if (operation == "cot") {
            cout << "cot(" << num1 << ") = " << 1.0 / tan(num1) << endl;
        } else if (operation == "%") {
            cout << "Введите делитель: ";
            cin >> num2;
            if (num2 != 0) {
                cout << fmod(num1, num2) << endl;
            } else {
                cout << "Деление на ноль!" << endl;
            }
        }
    } else if (operation == "+" || operation == "-" || operation == "*" || operation == "/" || operation == "fact") {
        if (operation == "fact") {
            cout << "Введите целое число для вычисления факториала: ";
            int n;
            cin >> n;
            if (n >= 0) {
                cout << n << "! = " << factorial(n) << endl;
            } else {
                cout << "Факториал отрицательного числа не определен!" << endl;
            }
        } else {
            cout << "Введите два числа: ";
            cin >> num1 >> num2;

            switch(operation[0]) {
                case '+':
                    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                    break;
                case '-':
                    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                    break;
                case '*':
                    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                    break;
                case '/':
                    if (num2 != 0) {
                        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                    } else {
                        cout << "Деление на ноль!" << endl;
                    }
                    break;
                default:
                    cout << "Неправильная операция!" << endl;
                    break;
            }
        }
    } else {
        cout << "Неправильная операция!" << endl;
    }

    return 0;
}
