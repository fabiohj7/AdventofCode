#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int decrypt(string character) {
  cout << "String: " << character << endl;
  int result = 0;
  for (int i = 0; i < character.size(); i++) {
    if (character[i] != '\n') {
      result += int(character[i]);
      result = result * 17;
      result = result % 256;
    }
  }
  return result;
}

int main() {
  ifstream file("input15.txt");

  if (!file.is_open()) {
    cerr << "Error opening file." << endl;
    return 1;
  }
  string fileContents((istreambuf_iterator<char>(file)),
                      istreambuf_iterator<char>());

  istringstream iss(fileContents);

  vector<string> codes;
  string token;
  int decrypted = 0;

  while (getline(iss, token, ',')) {
    codes.push_back(token);
  }
  int flag = 0;

  for (int i = 0; i < codes.size(); i++) {
    decrypted += decrypt(codes[i]);
  }
  cout << decrypted << endl;
}
