// GA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void selectionSort(int arr[], int n) { // Функция сортировки выбором
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // Находим индекс минимального элемента в оставшейся части массива
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) { // Меняем местами найденный минимальный элемент с первым элементом неотсортированной части
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int SIZE = 20; // Размер массива
    int arr[SIZE];

    std::srand(static_cast<unsigned int>(std::time(0))); // Генерация случайных чисел

    
    for (int i = 0; i < SIZE; ++i) // Заполнение массива случайными числами от 2 до 103 
    {
        arr[i] = 2 + std::rand() % (103 - 2 + 1); // rand() % 102 даёт [0, 101], +2 сдвигает выборку до [2, 103]
    }

    setlocale(LC_CTYPE, "Russian");
    std::cout << "Исходный массив:\n";
    printArray(arr, SIZE);

    selectionSort(arr, SIZE); // Сортировка выбором

    std::cout << "Отсортированный массив:\n";
    printArray(arr, SIZE);

    return 0;
}