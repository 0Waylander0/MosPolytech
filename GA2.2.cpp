// GA2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void printRange(int A, int B) {
    if (A == B) {
        cout << A << " ";
        return;
    }
    cout << A << " ";
    if (A < B)
        printRange(A + 1, B);
    else
        printRange(A - 1, B);
}

int main() {
    int A, B;
    cin >> A >> B;
    printRange(A, B);
    cout << endl;
    return 0;
}