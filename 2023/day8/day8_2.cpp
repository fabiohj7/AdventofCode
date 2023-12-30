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

vector<Maps> searchFirstElements(vector<Maps> maps, char element) {
  vector<Maps> matches;
  for (int i = 0; i < maps.size(); i++) {
    if (maps[i].element[2] == element) {
      matches.push_back(maps[i]);
    }
  }
  return matches;
}

int findFirstIteration(vector<Maps> maps, string instructions, string search) {
  int steps = 0;
  struct Maps temp = searchElement(maps, search);
  for (int i = 0; i < instructions.size(); i++) {
    if (instructions[i] == 'L') {
      temp = searchElement(maps, temp.left);
    } else if (instructions[i] == 'R') {
      temp = searchElement(maps, temp.right);
    }
    steps++;
  }
  if (temp.element[2] == 'Z') {
    return steps;
  }
  int recSteps = findFirstIteration(maps, instructions, temp.element);
  steps += recSteps;
  return steps;
}

void findPath(vector<Maps> maps, string instructions, string search, int &steps,
              Maps &matches, bool &found, int &flag) {
  struct Maps temp = searchElement(maps, search);
  for (int i = 0; i < instructions.size(); i++) {
    if (instructions[i] == 'L') {
      temp = searchElement(maps, temp.left);
    } else if (instructions[i] == 'R') {
      temp = searchElement(maps, temp.right);
    }
    steps++;
  }

  if (temp.element[2] == 'Z' && steps < flag) {
    cout << "1" << endl;
    findPath(maps, instructions, temp.element, steps, matches, found, flag);
  } else if (temp.element[2] == 'Z' && steps > flag) {
    flag = steps;
    cout << "2" << endl;
    found = false;
  } else if (temp.element[2] != 'Z') {
    findPath(maps, instructions, temp.element, steps, matches, found, flag);
  } else {
    cout << "4" << endl;
    found = true;
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
  char search = 'A';
  bool found = false;
  vector<Maps> matches = searchFirstElements(maps, search);
  int flag = findFirstIteration(maps, instructions, matches[0].element);

  for (int i = 0; i < matches.size(); i++) {
    int steps = 0;
    findPath(maps, instructions, matches[i].element, steps, matches[i], found,
             flag);
    if (found) {
      continue;
    } else {
      i = -1;
    }
  }
  cout << flag << endl;
}
