#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int winningNumbers(vector<int> leftnums, vector<int> rightnums) {
  int counter = 0;
  int result = 0;
  for (int i = 0; i < leftnums.size(); i++) {
    for (int j = 0; j < rightnums.size(); j++) {
      if (leftnums[i] == rightnums[j]) {
        counter++;
      }
    }
  }
  if (counter == 1) {
    result = 1;
  } else if (counter == 0) {
    result = 0;
  } else {
    result = 1;
    for (int i = 1; i < counter; i++) {
      result = result * 2;
    }
  }

  return result;
}

int main() {
  ifstream file("input4.txt");
  vector<string> lines;
  int check = 0;
  int result = 0;

  if (!file.is_open()) {
    cerr << "Error opening file." << endl;
    return 1;
  }

  string words;
  while (getline(file, words)) {
    lines.push_back(words);
  }

  for (int i = 0; i < lines.size(); i++) {
    vector<int> leftnums;
    vector<int> rightnums;

    istringstream iss(lines[i]);

    string ignore;
    iss >> ignore >> ignore;

    string num;
    bool secondPart = false;

    while (iss >> num) {

      if (num == "|") {
        secondPart = true;
        continue;
      }
      if (secondPart) {
        rightnums.push_back(stoi(num));
      } else {
        leftnums.push_back(stoi(num));
      }
    }
    check = winningNumbers(leftnums, rightnums);
    result += winningNumbers(leftnums, rightnums);
  }
  cout << result << endl;
}
