//
// Created by divan on 9/25/23.
//
// 2. Шоколадка.
// Требуется определить, можно ли от шоколадки размером n × m долек отломить k долек, если разрешается сделать один разлом
// по прямой между дольками (то есть разломить шоколадку на два прямоугольника).
// Вводятся 3 числа: n, m и k; k не равно n × m. Гарантируется, что количество долек в шоколадке не превосходит 30000.
// Программа должна вывести слово YES, если возможно отломить указанное число долек, в противном случае вывести слово NO.

#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cout << "Введите длину шоколадки" << endl;
    cin >> n;
    cout << "Введите ширину шоколадки" << endl;
    cin >> m;
    cout << "Введите количество ломтиков шоколадки (k)" << endl;
    cin >> k;
    if (k <= (m * n / 2))
        cout << "YES";
    else
        cout << "NO";
}