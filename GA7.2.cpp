// GA7.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> boxes;
    boxes.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long w, c;
        cin >> w >> c;
        boxes.emplace_back(w, c);
    }

    sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b) {
        return a.first + a.second < b.first + b.second;
        });

    long long total_weight_above = 0; 
    int count = 0;

    for (const auto& box : boxes) {
        long long w = box.first;
        long long c = box.second;

        if (total_weight_above <= c) {
            count++;
            total_weight_above += w;
        }
    }

    cout << count << '\n';
    return 0;
}