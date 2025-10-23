// CLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "Headline.h"
using namespace std;

// Первая программа
void firstProgram() {
    setlocale(LC_CTYPE, "Russian");
    cout << "\n=== Первая программа ===\n";
    double a, b;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;

    double avg = (a + b) / 2.0;
    cout << "Среднее арифметическое: " << avg << endl;

    char op;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;

    /*
    if (op == '+') {
        cout << "Результат: " << a + b << endl;
    } else if (op == '-') {
        cout << "Результат: " << a - b << endl;
    } else if (op == '*') {
        cout << "Результат: " << a * b << endl;
    } else if (op == '/') {
        if (b != 0) {
            cout << "Результат: " << a / b << endl;
        } else {
            cout << "Деление на ноль" << endl;
        }
    } else {
        cout << "Неизвестная операция" << endl;
    }
    */

    switch (op) {
    case '+':
        cout << "Результат: " << a + b << endl;
        break;
    case '-':
        cout << "Результат: " << a - b << endl;
        break;
    case '*':
        cout << "Результат: " << a * b << endl;
        break;
    case '/':
        if (b != 0) {
            cout << "Результат: " << a / b << endl;
        }
        else {
            cout << "Деление на ноль" << endl;
        }
        break;
    default:
        cout << "Неизвестная операция" << endl;
    }
}

// Вторая программа
void secondProgram() {
    cout << "\n Вторая программа \n";
    int n;
    while (true) {
        cout << "Введите целое положительное число: ";
        cin >> n;
        if (n > 0) {
            break;
        }
        cout << "Число должно быть положительным\n";
    }

    // Сумма от 1 до n
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    cout << "Сумма чисел от 1 до " << n << " = " << sum << endl;

    // Массив из 10 чисел
    int arr[10] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };

    // Вывод всех чисел
    cout << "Массив: ";
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Чётные позиции (0, 2, 4, 6, 8)
    cout << "Элементы на чётных позициях: ";
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    // Сумма элементов на нечётных позициях (1, 3, 5, 7, 9)
    int oddSum = 0;
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 1) {
            oddSum += arr[i];
        }
    }
    cout << "Сумма элементов на нечётных позициях: " << oddSum << endl;
}

// Третья программа
int sumFrom1ToN(int n = 1) {
    if (n <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

void calculateSumAndProduct(int a, int b, int& sumRef, int& prodRef) {
    sumRef = a + b;
    prodRef = a * b;
}

void thirdProgram() {
    cout << "\nТретья программа\n";

    // 1. Двумерный массив 2x3
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // 2. Сумма всех чисел
    int totalSum = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            totalSum += matrix[i][j];
        }
    }
    cout << "Сумма всех элементов матрицы: " << totalSum << endl;

    // 3-4. Одномерный массив с суммами столбцов
    int colSums[3] = { 0 };
    for (int j = 0; j < 3; ++j) {
        colSums[j] = matrix[0][j] + matrix[1][j];
    }

    // 5. Вывод одномерного массива
    cout << "Суммы столбцов: ";
    for (int j = 0; j < 3; ++j) {
        cout << colSums[j] << " ";
    }
    cout << endl;

    // 6-9. Работа со ссылками
    float value = 20.84;
    float& ref1 = value;
    float& ref2 = value;

    ref1 = 100.5; // изменяем через ref1

    cout << "После изменения через ref1:\n";
    cout << "value = " << value << endl;
    cout << "ref1 = " << ref1 << endl;
    cout << "ref2 = " << ref2 << endl;

    // 10-11. Функция с параметром по умолчанию
    cout << "sumFrom1ToN(4) = " << sumFrom1ToN(4) << endl;
    cout << "sumFrom1ToN() = " << sumFrom1ToN() << " (по умолчанию n=1)" << endl;

    // 12-14. Функция с параметрами по ссылке
    int x = 3, y = 7;
    int sumResult, prodResult;
    calculateSumAndProduct(x, y, sumResult, prodResult);
    cout << "Сумма " << x << " и " << y << " = " << sumResult << endl;
    cout << "Произведение = " << prodResult << endl;

    // 15-18. Переменные и цикл
    int globalVar = 42;
    cout << "Переменная до цикла: " << globalVar << endl;

    for (int i = 0; i < 3; ++i) {
        cout << "globalVar в цикле: " << globalVar << endl;
        int localVar = 99; // объявляется внутри цикла
        cout << "localVar в цикле: " << localVar << endl;
    }
}
// Четвертая программа
void fourthProgram() {
    cout << "\nЧетвёртая программа \n";

    MyNameSpace::processNumber(10); // 10 + 0
    MyNameSpace::processNumber(5);  // 5 + 10
    MyNameSpace::processNumber(20); // 20 + 5
    MyNameSpace::processNumber(0);  // 0 + 20
}

int main() {
    firstProgram();
    secondProgram();
    thirdProgram();
    fourthProgram();
    return 0;
}