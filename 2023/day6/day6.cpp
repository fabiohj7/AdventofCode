#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getResult(int arr[2][4]) {
  int speed = 0, sum = 1, timeleft = 0, run = 0;

  for (int i = 0; i < 4; i++) {
    int best = 0;
    int distance = arr[0][i];
    for (int j = 1; j < distance; j++) {
      speed = j;
      timeleft = distance - j;
      run = speed * timeleft;
      if (run > arr[1][i]) {
        best++;
      }
    }
    sum *= best;
    cout << sum << endl;
  }
  return sum;
}

int main() {
  ifstream file("input6.txt");
  vector<string> lines;
  int arr[2][4] = {0};
  string words;
  int i = 0, j = 0;

  if (!file.is_open()) {
    cerr << "Error opening the file." << endl;
    return 1;
  }

  while (getline(file, words)) {
    lines.push_back(words);
  }

  for (int i = 0; i < 2; i++) {
    istringstream iss(lines[i]);
    string ignore;
    iss >> ignore;
    for (int j = 0; j < 4; j++) {
      iss >> arr[i][j];
    }
  }
  int ans = getResult(arr);
  cout << ans << endl;
}
