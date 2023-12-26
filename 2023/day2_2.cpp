#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string removComma(string color) {
  for (int i = 0; i < color.size(); i++) {
    if (color[i] == ',' || color[i] == ';') {
      color.erase(i, 1);
      i--;
    }
  }
  return color;
}

int main() {
  ifstream file("input2.txt");
  vector<string> lines;
  string s;
  int sum = 0;
  int flag = 0;

  while (getline(file, s)) {
    lines.push_back(s);
  }

  // Loop to go through all the lines
  for (int i = 0; i < lines.size(); i++) {
    istringstream iss(lines[i]);

    string game;
    iss >> game;
    iss >> flag;
    iss.ignore();
    int number;
    int minRed = 0, minBlue = 0, minGreen = 0;
    string color;
    while (!iss.eof()) {
      iss >> number >> color;
      color = removComma(color);
      if (color == "red" && number > minRed) {
        minRed = number;
      } else if (color == "blue" && number > minBlue) {
        minBlue = number;
      } else if (color == "green" && number > minGreen) {
        minGreen = number;
      }
    }
    int total = minRed * minBlue * minGreen;
    sum += total;
  }
  cout << sum << endl;
}
