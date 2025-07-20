#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int knapsack(int W, int wt[], int val[], int n) {

  int dp[n + 1][W + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  for (int w = 1; w <= W; w++) {
    dp[0][w] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int w = 1; w <= W; ++w) {
      if (wt[i - 1] <= w) {

        dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
      } else {

        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  cout << "\nKnapsack Table:" << endl;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            cout << setw(2) << setfill('0') << dp[i][j] << " ";
        }
        cout << endl;
    }


  return dp[n][W];
}

int main() {
  int knapWeight = 14;
  int knapValues[] = {5, 9, 12, 15, 17};
  int knapWeights[] = {3, 1, 2, 4, 5};
  int knapsackValue = knapsack(knapWeight, knapWeights, knapValues, 5);
  cout << "Maximum value for 0/1 Knapsack with weight " << knapWeight << ": " << knapsackValue << endl;

  return 0;
}
