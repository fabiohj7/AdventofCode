#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Cards {
  int pairs = 0, cards = 1;
};

string removeColon(string card) {
  for (int i = 0; i < card.size(); i++) {
    if (card[i] == ':') {
      card.erase(i, 1);
      i--;
    }
  }
  return card;
}

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
  return counter;
}

int main() {
  ifstream file("input4.txt");
  vector<string> lines;
  vector<Cards> card;
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
    istringstream iss(lines[i]);

    string cardNum;
    string ignore;
    iss >> ignore;
    iss >> cardNum;
    cardNum = removeColon(cardNum);

    card.push_back(Cards());
  }

  for (int i = 0; i < lines.size(); i++) {
    vector<int> leftnums;
    vector<int> rightnums;

    istringstream iss(lines[i]);

    string cardNum;
    string ignore;
    iss >> ignore;
    iss >> cardNum;

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
    int counter = winningNumbers(leftnums, rightnums);

    for (int x = 1; x <= counter; x++) {
      card[i + x].cards += card[i].cards;
    }
  }
  for (int y = 0; y < card.size(); y++) {
    result += card[y].cards;
  }
  cout << result << endl;
}
