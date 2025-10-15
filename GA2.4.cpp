// GA2.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int divideOut(int n, int divisor) {
    if (n % divisor != 0) return n;
    return divideOut(n / divisor, divisor);
}

void printPrimeDivisors(int n, int divisor = 2) {
    if (n == 1) return;

    if (n % divisor == 0) {
        cout << divisor << " ";
        int newN = divideOut(n, divisor); // удаляем все вхождения divisor
        printPrimeDivisors(newN, divisor);
    }
    else {
        if (divisor * divisor > n) {
            if (n > 1) {
                cout << n << " ";
            }
            return;
        }
        else {
            printPrimeDivisors(n, divisor + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;
    printPrimeDivisors(N);
    cout << endl;
    return 0;
}