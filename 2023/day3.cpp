#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkAdjacent(int x, int y, vector<string> lines) {
  for (int j = -1; j < 2; j++) {
    for (int k = -1; k < 2; k++) {
      int newX = x + j;
      int newY = y + k;

      // Check boundaries
      if (newX >= 0 && newX < lines.size() && newY >= 0 &&
          newY < lines[newX].size()) {
        if (!(lines[newX][newY] == '.' || isdigit(lines[newX][newY]))) {
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  // Read the file
  ifstream file("input3.txt");
  string words;
  vector<string> lines;
  int sum = 0;
  string number;
  bool isEngine = false, adjacent = false;

  while (getline(file, words)) {
    lines.push_back(words);
  }
  // Iterate through all the lines.
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (isdigit(lines[i][j])) {
        number += lines[i][j];
        if (checkAdjacent(i, j, lines)) {
          isEngine = true;
        }
      } else {
        if (isEngine) {
          sum += stoi(number);
          number = "";
          isEngine = false;
        } else {
          number = "";
        }
      }
    }
  }

  cout << sum << endl;
}
