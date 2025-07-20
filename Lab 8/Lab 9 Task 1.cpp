#include <iostream>
#include <string>

using namespace std;

void LCS_Length(string& X, string& Y, int m, int n) {

  c = new int* [m + 1];
  for (int i = 0; i <= m; i++) {
    c[i] = new int[n + 1];
  }
  b = new char* [m + 1];
  for (int i = 0; i <= m; i++) {
    b[i] = new char[n + 1];
  }
  for (int i = 0; i <= m; i++) {
    c[i][0] = 0;
  }
  for (int j = 0; j <= n; j++) {
    c[0][j] = 0;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 'copy';
      } else {
        if (c[i - 1][j] >= c[i][j - 1]) {
          c[i][j] = c[i - 1][j];
          b[i][j] = 'skipX';
        } else {
          c[i][j] = c[i][j - 1];
          b[i][j] = 'skipY';
        }
      }
    }
  }
}

void Print_LCS(char** b, string X, int i, int j) {

  if (i == 0 || j == 0) {
    return;
  }

  if (b[i][j] == 'copy') {
    Print_LCS(b, X, i - 1, j - 1);
    cout << X[i];
  }


  else if (b[i][j] == 'skipX') {
    Print_LCS(b, X, i - 1, j);
  }

  else {
    Print_LCS(b, X, i, j - 1);
  }
}

int main() {
  string X = "Combination";
  string Y = "Competition";

  int m = X.length();
  int n = Y.length();

  int** c = new int* [m + 1];
  for (int i = 0; i <= m; i++) {
    c[i] = new int[n + 1];
  }
  char** b = new char* [m + 1];
  for (int i = 0; i <= m; i++) {
    b[i] = new char[n + 1];
  }

  LCS_Length(X, Y, m, n, c, b);

  cout << "LCS: ";
  Print_LCS(b, X, m, n);
  cout << endl;

  return 0;
}
