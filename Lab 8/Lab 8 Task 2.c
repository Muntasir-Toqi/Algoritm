#include <iostream>

using namespace std;

// Function to calculate logarithm base 2
int log2(int n) {
  int log = 0;
  while (n > 1) {
    n >>= 1; // Divide by 2
    log++;
  }
  return log;
}

int main() {
  char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int frequencies[] = {45, 13, 12, 16, 9, 5};

  int num_characters = sizeof(characters) / sizeof(characters[0]);

  // Calculate minimum code length without cmath
  int min_code_length = log2(num_characters);

  cout << "Minimum required code length: " << min_code_length << " bits\n";

  string codes[num_characters];

  // Pad codes with leading zeros if necessary
  for (int i = 0; i < num_characters; ++i) {
    string code = "";
    for (int j = 0; j < min_code_length; ++j) {
      code = '0' + code;
    }
    codes[i] = code;
  }

  // Assign codes based on frequency (higher frequency gets shorter prefix)
  for (int i = 0; i < num_characters; ++i) {
    for (int j = i + 1; j < num_characters; ++j) {
      if (frequencies[i] > frequencies[j]) {
        swap(frequencies[i], frequencies[j]);
        swap(codes[i], codes[j]);
      }
    }
  }

  // Print the characters and their corresponding fixed-length codes
  cout << "Character\tCode\n";
  for (int i = 0; i < num_characters; ++i) {
    cout << characters[i] << "\t\t" << codes[i] << endl;
  }

  return 0;
}
