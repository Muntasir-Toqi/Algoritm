#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

void printTable(int table[MAX][MAX], int m, int n, const string& X, const string& Y) {
    cout << "   ";
    for (int j = 0; j < n; ++j) {
        cout << Y[j] << " ";
    }
    cout << endl;

    for (int i = 0; i <= m; ++i) {
        if (i > 0) cout << X[i - 1] << " ";
        else cout << "  ";
        for (int j = 0; j <= n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

string LCS(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();
    int dp[MAX][MAX] = {0};

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Length of LCS: " << dp[m][n] << endl;
    cout << "LCS Table:" << endl;
    printTable(dp, m, n, X, Y);

    return lcs;
}

int main() {
    const string X = "ANACONDA";
    string Y;
    cout << "Enter your first name: ";
    cin >> Y;

    string lcs = LCS(X, Y);
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
