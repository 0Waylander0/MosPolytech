// GA2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void printFrom1ToN(int n, int current = 1) {
    if (current > n) return;
    cout << current << " ";
    printFrom1ToN(n, current + 1);
}

int main() {
    int n;
    cin >> n;
    printFrom1ToN(n);
    cout << endl;
    return 0;
}