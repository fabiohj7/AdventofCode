#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct coordinates {
  int x = 0;
  int y = 0;
  bool hasNumber = false;
  int number = 0;
};

void getgears(vector<string> lines, vector<coordinates> &coord) {
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == '*') {
        coordinates gearCoord;
        gearCoord.x = i;
        gearCoord.y = j;
        coord.push_back(gearCoord);
      }
    }
  }
}

bool checkAdjacent(int &a, int &b, int x, int y, vector<string> lines) {
  for (int j = -1; j < 2; j++) {
    for (int k = -1; k < 2; k++) {
      int newX = x + j;
      int newY = y + k;

      // Check boundaries
      if (newX >= 0 && newX < lines.size() && newY >= 0 &&
          newY < lines[newX].size()) {
        if (lines[newX][newY] == '*') {
          a = newX;
          b = newY;
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
  bool isGear = false, adjacent = false;
  vector<coordinates> coord;
  int a, b, it = 0;

  while (getline(file, words)) {
    lines.push_back(words);
  }
  getgears(lines, coord);
  // Iterate through all the lines.
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (isdigit(lines[i][j])) {
        number += lines[i][j];
        if (checkAdjacent(a, b, i, j, lines)) {
          isGear = true;
        }
      } else {
        if (isGear) {
          for (int c = 0; c < coord.size(); c++) {
            if (coord[c].x == a && coord[c].y == b) {
              if (coord[c].hasNumber) {
                sum += coord[c].number * stoi(number);
              } else {
                coord[c].number = stoi(number);
                coord[c].hasNumber = true;
              }
            }
          }
          number = "";
          isGear = false;
        } else {
          number = "";
        }
      }
    }
  }
  cout << sum << endl;
}
