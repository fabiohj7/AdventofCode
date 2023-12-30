#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Maps {
  string element;
  string right;
  string left;
};

void cleanUp(vector<Maps> &maps) {
  for (int i = 0; i < maps.size(); i++) {
    for (int j = 0; j < maps[i].left.size(); j++) {
      if (maps[i].left[j] == ',' || maps[i].left[j] == '(') {
        maps[i].left.erase(j, 1);
        i--;
      }
    }
  }
  for (int i = 0; i < maps.size(); i++) {
    for (int j = 0; j < maps[i].right.size(); j++) {
      if (maps[i].right[j] == ')') {
        maps[i].right.erase(j, 1);
        i--;
      }
    }
  }
}

struct Maps searchElement(vector<Maps> maps, string element) {
  int itemFound = 0;
  for (int i = 0; i < maps.size(); i++) {
    if (maps[i].element == element) {
      itemFound = i;
    }
  }
  return maps[itemFound];
}

int findPath(vector<Maps> maps, string instructions, string search) {
  bool foundPath = false;
  int steps = 0;
  struct Maps temp = searchElement(maps, search);
  for (int i = 0; i < instructions.size(); i++) {
    if (instructions[i] == 'L') {
      temp = searchElement(maps, temp.left);
      steps++;
    } else if (instructions[i] == 'R') {
      temp = searchElement(maps, temp.right);
      steps++;
    }
  }

  if (temp.element == "ZZZ") {
    foundPath = true;
  } else {
    int recursiveSteps = 0;
    recursiveSteps += findPath(maps, instructions, temp.element);
    steps += recursiveSteps;
    foundPath = recursiveSteps > 0;
  }

  if (foundPath) {
    return steps;
  } else {
    return 0;
  }
}

int main() {
  ifstream file("input8.txt");
  vector<string> lines;
  vector<Maps> maps;
  string instructions;

  string words;
  getline(file, instructions);
  while (getline(file, words)) {
    if (words == "") {
      continue;
    }
    lines.push_back(words);
    maps.push_back(Maps());
  }

  for (int i = 0; i < lines.size(); i++) {
    istringstream iss(lines[i]);

    string ignore;
    iss >> maps[i].element;
    iss >> ignore;
    iss >> maps[i].left;
    iss >> maps[i].right;
  }

  cleanUp(maps);
  string search = "AAA";
  int steps = 0;
  steps = findPath(maps, instructions, search);
  cout << steps << endl;
}
