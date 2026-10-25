

#include <cassert>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
int timeRequiredToBuy(std::vector<int> tickets, const int K) {
  if (K > tickets.size() || K < 0)
    return 0;
  if (tickets[K] == 0)
    return 0;
  int seconds = 0;
  std::queue<int> life_queue;
  for (int i = 0; i < tickets.size(); i++)
    life_queue.push(i);
  while (!life_queue.empty()) {
    tickets[life_queue.front()]--;
    seconds++;
    if (tickets[life_queue.front()] <= 0) {
      if (life_queue.front() == K)
        break;
    } else {
      life_queue.push(life_queue.front());
    }

    life_queue.pop();
  }
  return seconds;
}

void test_timeRequiredToBuy() {
  {
    std::vector<int> tickets = {2, 3, 2};
    assert(timeRequiredToBuy(tickets, 2) == 6);
  }
  {
    std::vector<int> tickets = {5, 1, 1, 1};
    assert(timeRequiredToBuy(tickets, 0) == 8);
  }
  {
    std::vector<int> tickets = {5};
    assert(timeRequiredToBuy(tickets, 0) == 5);
  }
  {
    std::vector<int> tickets = {0};
    assert(timeRequiredToBuy(tickets, 0) == 0);
  }
}

int main() { test_timeRequiredToBuy(); }
