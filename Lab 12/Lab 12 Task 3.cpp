#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};
const int MAX_INT = 2147483647;

vector<pair<int, int>> primMST(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    vector<pair<int, int>> mst;
    vector<bool> visited(n, false);
    vector<int> key(n, MAX_INT);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        visited[u] = true;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        mst.push_back({parent[i], i});
    }

    return mst;
}
int main() {
    // Example usage
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {7, 8}},
        {{0, 4}, {2, 8}, {7, 11}},
        {{1, 8}, {3, 7}, {5, 4}, {8, 2}},
        {{2, 7}, {4, 9}, {5, 14}},
        {{3, 9}, {5, 10}},
        {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
        {{5, 2}, {7, 1}, {8, 6}},
        {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
        {{2, 2}, {6, 6}, {7, 7}}
    };

    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 0, 4}, {1, 2, 8}, {1, 7, 11},
        {2, 1, 8}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 2, 7},
        {3, 4, 9}, {3, 5, 14}, {4, 3, 9}, {4, 5, 10}, {5, 2, 4},
        {5, 3, 14}, {5, 4, 10}, {5, 6, 2}, {6, 5, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 0, 8}, {7, 1, 11}, {7, 6, 1}, {7, 8, 7},
        {8, 2, 2}, {8, 6, 6}, {8, 7, 7}
    };

    // Prim's algorithm
    vector<pair<int, int>> primResult = primMST(graph);
    cout << "Minimum Spanning Tree using Prim's Algorithm:\n";
    for (const auto& edge : primResult) {
        cout << edge.first << " - " << edge.second << endl;
    }
       return 0;
}
