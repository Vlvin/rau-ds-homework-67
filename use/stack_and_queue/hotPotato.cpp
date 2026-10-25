
#include <cassert>
#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string hotPotato(const std::vector<std::string> &names, const size_t k) {
  if (names.empty())
    return "";
  std::queue<std::string> players;
  for (auto &name : names)
    players.push(name);
  while (players.size() > 1) {
    for (int i = 0; i < k; i++) {
      players.push(players.front());
      players.pop();
    }
    players.pop();
  }
  return players.front();
}

void test_hotPotato() {
  { // normal
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    assert(hotPotato(players, 7) == "Charlie");
  }
  { // empty list of players
    std::vector<std::string> players = {};
    assert(hotPotato(players, 3) == "");
  }
  { // 0 passes
    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    assert(hotPotato(players, 0) == "David");
  }
}

int main() { test_hotPotato(); }
