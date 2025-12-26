#include <array>
#include <iostream>
#include <vector>

int main() {

  // direction map
  std::array<int, 8> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
  std::array<int, 8> dy = {1, 1, 1, 0, 0, -1, -1, -1};

  size_t count = 0;

  std::string line;
  std::vector<std::string> graph;

  while (std::cin >> line) {
    graph.push_back(std::move(line));
  }
  for (size_t row = 0; row < graph.size(); row++) {

    for (size_t col = 0; col < graph[0].size(); col++) {

      if (graph[row][col] == '@') {

        size_t adj_rolls = 0;
        for (size_t adj = 0; adj < 8; adj++) {
          int new_row = row + dx[adj];
          int new_col = col + dy[adj];
          if (new_row > -1 && new_row < graph.size() && new_col > -1 &&
              new_col < graph[0].size()) {

            if (graph[new_row][new_col] == '@')
              adj_rolls++;
          }
        }
        if (adj_rolls < 4)
          count++;
      }
    }
  }
  std::cout << count;
  return 0;
}
