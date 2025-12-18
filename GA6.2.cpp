// GA6.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> cost(N);
    for (int i = 0; i < N; ++i) {
        cin >> cost[i];
    }

    int M;
    cin >> M;

    vector<vector<int> > graph(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;
        if (u == N - 1) break;

        for (size_t idx = 0; idx < graph[u].size(); ++idx) {
            int v = graph[u][idx];
            int nd = d + cost[u];
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push(make_pair(nd, v));
            }
        }
    }

    if (dist[N - 1] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[N - 1] << endl;

    return 0;
}