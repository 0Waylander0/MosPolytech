// GA6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N, S, F;
    cin >> N >> S >> F;
    S--; F--;

    vector<vector<pair<int, int> > > graph(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int w;
            cin >> w;
            if (w != -1 && i != j) {
                graph[i].push_back(make_pair(j, w));
            }
        }
    }

    vector<int> dist(N, INT_MAX);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, S));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (size_t idx = 0; idx < graph[u].size(); ++idx) {
            int v = graph[u][idx].first;
            int w = graph[u][idx].second;
            int nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push(make_pair(nd, v));
            }
        }
    }

    if (dist[F] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[F] << endl;

    return 0;
}