// GA7.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    sort(lectures.begin(), lectures.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });

    int count = 0;
    int last_end = -1;

    for (const auto& lec : lectures) {
        if (lec.first >= last_end) {
            count++;
            last_end = lec.second;
        }
    }

    cout << count << '\n';
    return 0;
}