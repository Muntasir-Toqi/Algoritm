#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
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
    int knapWeight = 12;
    vector<int> knapValues = {5, 9, 12, 15, 17};
    vector<int> knapWeights = {3, 1, 2, 4, 5};
    int knapsackValue = knapsack(knapWeight, knapWeights, knapValues, 5);
    cout << "Maximum value for 0/1 Knapsack with weight " << knapWeight << ": " << knapsackValue << endl;

    return 0;
}
