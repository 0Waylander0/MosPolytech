// GA5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

unordered_map<string, vector<string>> buildMazeGraph() {
    unordered_map<string, vector<string>> graph;
    graph["A"] = { "S", "F" };
    graph["B"] = { "D", "C", "G" };
    graph["C"] = { "B" };
    graph["D"] = { "S", "E", "B" };
    graph["E"] = { "D", "F", "G" };
    graph["F"] = { "A", "E", "H" };
    graph["G"] = { "E", "B", "I" };
    graph["H"] = { "F" };
    graph["I"] = { "G", "J" };
    graph["J"] = { "I" };
    graph["S"] = { "A", "D" };
    return graph;
}

pair<vector<string>, int> bfsShortestPath(const unordered_map<string, vector<string>>& graph,
    const string& start, const string& end) {
    if (start == end) {
        return make_pair(vector<string>(1, start), 0);
    }

    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    q.push(start);
    visited.insert(start);
    parent[start] = "";

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (graph.find(current) == graph.end()) continue;

        for (const string& neighbor : graph.at(current)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                parent[neighbor] = current;
                q.push(neighbor);

                if (neighbor == end) {
                    vector<string> path;
                    string node = end;
                    while (!node.empty()) {
                        path.push_back(node);
                        node = parent[node];
                    }
                    reverse(path.begin(), path.end());
                    return make_pair(path, (int)path.size() - 1);
                }
            }
        }
    }

    return make_pair(vector<string>(), -1);
}

int main() {
    auto graph = buildMazeGraph();
    string start = "S";
    string end = "I";

    auto result = bfsShortestPath(graph, start, end);
    vector<string> path = result.first;
    int steps = result.second;

    if (steps == -1) {
        cout << "Path not found." << endl;
    }
    else {
        cout << "Shortest path from " << start << " to " << end << ":" << endl;
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Steps: " << steps << endl;
    }

    return 0;
}