#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;

void printAdjacencyMatrix(int graph[MAX][MAX], int V) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


void printAdjacencyList(vector<vector<int>>& adjList) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

void printWeightedAdjacencyMatrix(int graph[MAX][MAX], int V) {
    cout << "Weighted Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void printWeightedAdjacencyList(vector<vector<vector<int>>>& adjList) {
    cout << "Weighted Adjacency List:" << endl;
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j][0] << "(" << adjList[i][j][1] << ") ";
        }
        cout << endl;
    }
}

void Graphs() {
    int graphDirected[MAX][MAX] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };

    vector<vector<int>> adjListDirected = {{1}, {2}, {4, 2}, {2, 4}, {2}};


    int graphWeightedDirected[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {2, 0, 3, 0, 0},
        {0, 5, 0, 1, 0},
        {0, 0, 5, 0, 5},
        {2, 0, 0, 3, 0}
    };

    vector<vector<vector<int>>> adjListWeightedDirected = {{{1, 10}}, {{2, 5}}, {{3, 10}}, {{2, 5}, {4, 20}}, {{0, 20}}};

    int graphUndirected[MAX][MAX] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    vector<vector<int>> adjListUndirected = {{1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}};

    int graphWeightedUndirected[MAX][MAX] = {
        {0, 1, 0, 0, 20},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 10, 0},
        {0, 0, 10, 0, 1},
        {20, 0, 0, 1, 0}
    };

    vector<vector<vector<int>>> adjListWeightedUndirected = {{{1, 1}, {3, 2}}, {{10, 11}, {7, 5}}, {{31, 5}, {23, 11}}, {{2, 1}, {4, 12}}, {{0, 2}, {4, 9}}};

    int V = 5;

    printAdjacencyMatrix(graphDirected, V);
    printAdjacencyList(adjListDirected);
    printWeightedAdjacencyMatrix(graphWeightedDirected, V);
    printWeightedAdjacencyList(adjListWeightedDirected);

    printAdjacencyMatrix(graphUndirected, V);
    printAdjacencyList(adjListUndirected);
    printWeightedAdjacencyMatrix(graphWeightedUndirected, V);
    printWeightedAdjacencyList(adjListWeightedUndirected);
}

int main() {
    Graphs();
    return 0;
}
