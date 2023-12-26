#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Games {
  string hand;
  int bid;
  int points;
  int strength = 0;
};

int get_result(vector<Games> games) {
  int sum = 0;
  int ite = 1;

  for (int i = 0; i < games.size(); i++) {
    sum += games[i].bid * ite;
    ite++;
  }

  return sum;
}

void order(vector<Games> &games) {

  map<char, int> cards = {{'2', 1},  {'3', 2},  {'4', 3}, {'5', 4}, {'6', 5},
                          {'7', 6},  {'8', 7},  {'9', 8}, {'T', 9}, {'J', 0},
                          {'Q', 11}, {'K', 12}, {'A', 13}};
  int n = games.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      // If there is a tie check for card strength.
      if (games[j].points == games[j + 1].points) {
        for (int k = 0; k < 5; k++) {
          games[j].strength = cards[games[j].hand[k]];
          games[j + 1].strength = cards[games[j + 1].hand[k]];
          if (games[j].strength > games[j + 1].strength) {
            swap(games[j], games[j + 1]);
            break;
          } else if (games[j].strength < games[j + 1].strength) {
            break;
          }
        }
        // Sort by points.
      } else if (games[j].points > games[j + 1].points) {
        swap(games[j], games[j + 1]);
      }
    }
  }
}

int main() {
  fstream file("input7.txt");
  vector<string> lines;
  string words;
  vector<Games> game;
  vector<unordered_map<char, int>> count;

  while (getline(file, words)) {
    lines.push_back(words);
  }

  for (int i = 0; i < lines.size(); i++) {
    game.push_back(Games());

    istringstream iss(lines[i]);

    iss >> game[i].hand;
    iss >> game[i].bid;
  }

  for (int i = 0; i < game.size(); i++) {
    count.push_back(unordered_map<char, int>());
  }

  // Iterate through all the hands.
  for (int j = 0; j < game.size(); j++) {
    for (int i = 0; i < game[j].hand.size(); i++) {
      count[j][game[j].hand[i]]++;
    }
    int counter = 0;
    for (auto it : count[j]) {
      // Created system of points depending on the hand.
      switch (it.second) {
      case 2:
        game[j].points += 2;
        break;
      case 3:
        game[j].points += 5;
        break;
      case 4:
        game[j].points += 8;
        break;
      case 5:
        game[j].points += 9;
        break;
      default:
        break;
      }
    }
  }
  order(game);
  for (int i = 0; i < game.size(); i++) {
    cout << game[i].hand << " " << game[i].bid << " Points: " << game[i].points
         << " Strength: " << game[i].strength << endl;
  }
  int sum = get_result(game);
  cout << sum << endl;
}
