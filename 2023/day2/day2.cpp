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

    bool possible = true;
    string game;
    iss >> game;
    iss >> flag;
    iss.ignore();
    int number;
    string color;
    while (!iss.eof()) {
      iss >> number >> color;
      color = removComma(color);
      if (color == "red" && number > 12) {
        possible = false;
        break;
      } else if (color == "blue" && number > 14) {
        possible = false;
        break;
      } else if (color == "green" && number > 13) {
        possible = false;
        break;
      }
    }
    if (possible == true)
      sum += flag;
  }
  cout << sum << endl;
}
