// GA3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void swapRows(std::vector<std::vector<int>>& mat, int i, int j) {
    if (i != j) mat[i].swap(mat[j]);
}


void quickSortFirstColumn(std::vector<std::vector<int>>& mat, int left, int right) {
    if (left >= right) return;

    int pivot = mat[(left + right) / 2][0];
    int i = left, j = right;

    while (i <= j) {
        while (mat[i][0] < pivot) i++;
        while (mat[j][0] > pivot) j--;
        if (i <= j) {
            swapRows(mat, i, j);
            i++;
            j--;
        }
    }

    if (left < j) quickSortFirstColumn(mat, left, j);
    if (i < right) quickSortFirstColumn(mat, i, right);
}

void task1() {
    const int N = 1000;
    std::vector<int> arr(N);

    std::cout << "\n Сортировка 1000 целых чисел \n";
    std::cout << "Введите " << N << " целых чисел :\n";

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    quickSort(arr, 0, N - 1);

    std::cout << "\nОтсортированная последовательность:\n";
    for (int i = 0; i < std::min(30, N); ++i) {
        std::cout << arr[i] << " ";
    }
    if (N > 40) {
        std::cout << "... ";
        for (int i = N - 10; i < N; ++i) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\n";
}

void task2() {
    const int N = 1000;
    std::vector<int> arr(N);

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < N; ++i) {
        arr[i] = 50 + rand() % 51;
    }

    std::cout << "\nСортировка 1000 случайных чисел из [50, 100]\n";
    std::cout << "Исходные: ";
    for (int i = 0; i < 15; ++i) std::cout << arr[i] << " ";
    std::cout << "... ";

    quickSort(arr, 0, N - 1);

    std::cout << "\nОтсортировано:\n";
    for (int i = 0; i < 15; ++i) std::cout << arr[i] << " ";
    std::cout << "... ";
    for (int i = N - 5; i < N; ++i) std::cout << arr[i] << " ";
    std::cout << "\n";
}

void task3() {
    const int rows = 15;
    const int cols = 6;

    std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(5, 61);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = dis(gen);
        }
    }

    std::cout << "\nЗадача 3: Сортировка строк по возрастанию первого столбца\n";
    std::cout << "Исходная матрица (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(3) << mat[i][j] << " ";
        }
        std::cout << " | col0 = " << std::setw(2) << mat[i][0] << "\n";
    }

    quickSortFirstColumn(mat, 0, rows - 1);

    std::cout << "\nПосле сортировки по первому столбцу:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(3) << mat[i][j] << " ";
        }
        std::cout << " | col0 = " << std::setw(2) << mat[i][0] << "\n";
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int choice;
    do {
        std::cout << "\n" << std::string(50, '=') << "\n";
        std::cout << "МЕНЮ:\n";
        std::cout << "1.Сортировка 1000 чисел (ввод с клавиатуры)\n";
        std::cout << "2.Сортировка 1000 случайных чисел из [50, 100]\n";
        std::cout << "3.Сортировка строк матрицы по первому столбцу ([5,61])\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите задачу: ";
        std::cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 0: std::cout << "Выход.\n"; break;
        default: std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}