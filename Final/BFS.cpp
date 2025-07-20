#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX = 100;

void bfs(int graph[][MAX], int nodes, int start, int end, string path[], string nodeNames[], string bfsTraversal[]) {
    bool visited[MAX] = {false};
    int parent[MAX];

    visited[start] = true;
    parent[start] = -1;
    queue<int> q;
    q.push(start);

    int bfsIndex = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        bfsTraversal[bfsIndex++] = nodeNames[current];

        if (current == end)
            break;

        for (int i = 0; i < nodes; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                parent[i] = current;
                q.push(i);
            }
        }
    }

    int currentNode = end;
    int pathLength = 0;
    while (currentNode != -1) {
        path[pathLength++] = nodeNames[currentNode];
        currentNode = parent[currentNode];
    }

    for (int i = 0; i < pathLength / 2; ++i) {
        swap(path[i], path[pathLength - i - 1]);
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> nodes;

    string nodeNames[MAX];
    cout << "Enter node names:" << endl;
    for (int i = 0; i < nodes; ++i) {
        cin >> nodeNames[i];
    }

    int graph[MAX][MAX] = {0};

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    cout << "Enter the edges (source node, destination node):" << endl;
    for (int i = 0; i < edges; ++i) {
        string source, destination;
        cout << "Edge " << i + 1 << ": ";
        cin >> source >> destination;

        int sourceIndex = -1, destinationIndex = -1;
        for (int j = 0; j < nodes; ++j) {
            if (nodeNames[j] == source) sourceIndex = j;
            if (nodeNames[j] == destination) destinationIndex = j;
        }

        if (sourceIndex != -1 && destinationIndex != -1) {
            graph[sourceIndex][destinationIndex] = 1;
        } else {
            cout << "Invalid edge. Please enter valid node names." << endl;
            --i;
        }
    }

    cout << "\nAdjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 0; i < nodes; ++i)
        cout << nodeNames[i] << " ";
    cout << endl;
    for (int i = 0; i < nodes; ++i) {
        cout << nodeNames[i] << " ";
        for (int j = 0; j < nodes; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    string startNode, endNode;
    cout << "\nEnter the starting node for BFS: ";
    cin >> startNode;

    cout << "Enter the destination node: ";
    cin >> endNode;

    int startIndex = -1, endIndex = -1;
    for (int i = 0; i < nodes; ++i) {
        if (nodeNames[i] == startNode) startIndex = i;
        if (nodeNames[i] == endNode) endIndex = i;
    }

    if (startIndex == -1 || endIndex == -1) {
        cout << "Invalid starting or destination node. Please enter valid node names." << endl;
        return 1;
    }

    string path[MAX];
    string bfsTraversal[MAX];
    bfs(graph, nodes, startIndex, endIndex, path, nodeNames, bfsTraversal);

    cout << "\nBFS Traversal: ";
    for (int i = 0; i < MAX && !bfsTraversal[i].empty(); ++i) {
        cout << bfsTraversal[i];
        if (bfsTraversal[i + 1].empty()) cout << endl;
        else cout << " -> ";
    }

    cout << "\nPath from " << startNode << " to " << endNode << ": ";
    for (int i = 0; i < MAX && !path[i].empty(); ++i) {
        cout << path[i];
        if (path[i + 1].empty()) cout << endl;
        else cout << " -> ";
    }

    return 0;
}
