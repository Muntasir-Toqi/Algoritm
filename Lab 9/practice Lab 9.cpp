#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string lcs(string& X, string& Y, int m, int n) {
    int LCS[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    cout << "Value matrix Table:" << endl;
    cout<<"        ";
    for (int i = 0; i <= m; i++)
    {
      cout<<X[i]<<"   ";
    }
    cout<<endl;
    for (i = 0; i <= m; i++) {
        if(i!=0){
          cout<<Y[i-1]<<"   ";
        }
        else{
          cout<<"    ";
        }

        for (j = 0; j <= n; j++) {
            cout << LCS[i][j] << "   ";
        }
        cout << endl;
    }

    int index = LCS[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    return string(lcs);
}

int main() {
    string X = "Combination";
    string Y = "Competition";
    int m = X.length();
    int n = Y.length();
    string result = lcs(X, Y, m, n);
    cout<<endl<<endl;
    cout << "Length of LCS is " << result.length() << endl;
    cout << "Longest Common Subsequence: " << result << endl;
    return 0;
}
