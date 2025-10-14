// GA1.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

void selectionSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) { // Находим индекс минимальной строки в оставшейся части
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) { // Меняем местами, если нужно
            std::string temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printPhones(const std::string arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    const int SIZE = 3;
    std::string phones[SIZE] = {
        "+7 (916) 987-65-43",
        "+7 (905) 123-45-67",
        "+7 (926) 000-11-22"
    };

    setlocale(LC_CTYPE, "Russian");
    std::cout << "Исходный список телефонов:\n";
    printPhones(phones, SIZE);

    selectionSort(phones, SIZE);

    std::cout << "\nОтсортированный список (по возрастанию):\n";
    printPhones(phones, SIZE);

    return 0;
}