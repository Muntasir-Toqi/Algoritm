#include <iostream>
#include <string>

using namespace std;

void LCS_Length(string X, string Y, int m, int n, int** c, char** b) {
  // Allocate memory for c and b tables (2D arrays)
  c = new int* [m + 1];
  for (int i = 0; i <= m; i++) {
    c[i] = new int[n + 1];
  }
  b = new char* [m + 1];
  for (int i = 0; i <= m; i++) {
    b[i] = new char[n + 1];
  }

  // Initialize first row and column as 0
  for (int i = 0; i <= m; i++) {
    c[i][0] = 0;
  }
  for (int j = 0; j <= n; j++) {
    c[0][j] = 0;
  }

  // Fill the c and b tables
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = '\\'; // Diagonal arrow (copy)
      } else {
        if (c[i - 1][j] >= c[i][j - 1]) {
          c[i][j] = c[i - 1][j];
          b[i][j] = '^'; // Up arrow (skipX)
        } else {
          c[i][j] = c[i][j - 1];
          b[i][j] = '<'; // Left arrow (skipY)
        }
      }
    }
  }
}

void Print_LCS(char** b, string X, int i, int j) {
  // Base cases
  if (i == 0 || j == 0) {
    return;
  }

  // Print the LCS length before starting the recursion
  cout << c[m][n] << " "; // Access the LCS length from the bottom right corner of c

  // Now, use backtracking to print the actual LCS characters
  if (b[i][j] == 'copy') {
    Print_LCS(b, X, i - 1, j - 1);
    cout << X[i - 1];
  } else if (b[i][j] == 'skipX') {
    Print_LCS(b, X, i - 1, j);
  } else {
    Print_LCS(b, X, i, j - 1);
  }
}

int main() {
  string X = "Combination";
  string Y = "Competition";

  int m = X.length();
  int n = Y.length();

  // Allocate memory for tables (c and b)
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
  Print_LCS(b, X, m, n); // Start from the bottom right corner of b
  cout << endl;

  // Deallocate memory for tables
  for (int i = 0; i <= m; i++) {
    delete[] c[i];
  }
  delete[] c;
  for (int i = 0; i <= m; i++) {
    delete[] b[i];
  }
