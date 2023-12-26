#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int concat(int l, int r) {
  string s1 = to_string(l);
  string s2 = to_string(r);

  string s = s1 + s2;

  int c = stoi(s);
  return c;
}

int main() {
  string s;
  int sum = 0;
  vector<string> lines;
  string arr[] = {"one", "two",   "three", "four", "five",
                  "six", "seven", "eight", "nine"};
  ifstream file("input.txt");
  string words;

  while (getline(file, words)) {
    lines.push_back(words);
  }

  for (int i = 0; i < lines.size(); i++) {
    vector<int> nums;
    for (int j = 0; j < lines[i].size(); j++) {
      if (isdigit(lines[i][j])) {
        nums.push_back(lines[i][j] - '0');
      } else {
        for (int k = 0; k < 9; k++) {
          int ans =
              std::strncmp(lines[i].c_str() + j, arr[k].c_str(), arr[k].size());
          if (ans == 0) {
            nums.push_back(k + 1);
            break;
          }
        }
      }
    }
    sum += concat(nums[0], nums[nums.size() - 1]);
  }
  cout << sum << endl;
}
