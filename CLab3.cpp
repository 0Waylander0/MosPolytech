// CLab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int sumArray(int* start, int* end) {
    int sum = 0;
    while (start != end) {
        sum += *start;
        start++;
    }
    return sum;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return &add;
    }
    else if (op == '-') {
        return &subtract;
    }
    return nullptr;
}

int main() {
    setlocale(LC_CTYPE, "Russian");
    std::cout << "ПРОГРАММА 1" << std::endl;

    int number = 42;
    std::cout << "Исходная переменная: " << number << std::endl;

    int* ptr = &number;

    std::cout << "Адрес указателя: " << ptr << ", значение: " << *ptr << std::endl;

    *ptr = 100;

    std::cout << "После изменения через указатель: " << number << std::endl;

    int arr[] = { 1, 2, 3, 4, 5 };

    std::cout << "Элементы массива: ";
    int* arrPtr = arr;
    for (size_t i = 0; i < 5; i++) {
        std::cout << *arrPtr << " ";
        arrPtr++;
    }
    std::cout << std::endl;

    int value = 5;

    int* const constPtr = &value;
    *constPtr = 10;

    std::cout << "Переменная через константный указатель: " << *constPtr << std::endl;

    std::cout << "\nПРОГРАММА 2" << std::endl;

    int testArr[] = { 10, 20, 30, 40, 50 };
    int arraySum = sumArray(testArr, testArr + 5);
    std::cout << "2. Сумма массива: " << arraySum << std::endl;

    char operation = '+';
    int (*operationPtr)(int, int) = getOperation(operation);

    if (operationPtr != nullptr) {
        int result = operationPtr(15, 7);
        std::cout << "6. Результат операции " << operation << ": " << result << std::endl;
    }

    operation = '-';
    operationPtr = getOperation(operation);

    if (operationPtr != nullptr) {
        int result = operationPtr(15, 7);
        std::cout << "6. Результат операции " << operation << ": " << result << std::endl;
    }

    float* dynamicFloat = new float(3.14159f);
    std::cout << "7. Динамический float: " << *dynamicFloat << std::endl;

    delete dynamicFloat;
    std::cout << "8. Память освобождена" << std::endl;
    dynamicFloat = nullptr;

    return 0;
}