// GA4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_set<long long> numbers;
    long long x;

    while (std::cin >> x) {
        if (x > 0) {
            numbers.insert(x);
        }
        else if (x < 0) {
            numbers.erase(-x);
        }
        else {
            std::vector<long long> vec(numbers.begin(), numbers.end());
            std::sort(vec.begin(), vec.end());

            for (size_t i = 0; i < vec.size(); ++i) {
                if (i > 0) std::cout << ' ';
                std::cout << vec[i];
            }
            std::cout << '\n';
            break;
        }
    }

    return 0;
}