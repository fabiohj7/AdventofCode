#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getResult(long time, long distance) {
  long speed = 0, sum = 1, timeleft = 0, run = 0;
  long best = 0;

  for (int j = 1; j < time; j++) {
    speed = j;
    timeleft = time - j;
    run = speed * timeleft;
    if (run > distance) {
      best++;
    }
  }
  return best;
}

int main() {
  ifstream file("input6.txt");
  vector<string> lines;
  long time;
  long distance;
  string words;
  long result;
  int i = 0, j = 0;

  if (!file.is_open()) {
    cerr << "Error opening the file." << endl;
    return 1;
  }

  while (getline(file, words)) {
    lines.push_back(words);
  }

  istringstream iss(lines[0]);
  string ignore;
  iss >> ignore;
  iss >> time;
  istringstream iss2(lines[1]);
  iss2 >> ignore;
  iss2 >> distance;
  result = getResult(time, distance);
  cout << result << endl;
}
