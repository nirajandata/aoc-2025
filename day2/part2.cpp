#include <array>
#include <iostream>
#include <set>

auto main() -> int {
  int64_t x, y, sum = 0;
  char ignore;
  std::array<int64_t, 11> precom_ten{1};
  for (size_t i = 1; i < 11; i++)
    precom_ten[i] = 10 * precom_ten[i - 1];

  std::array<std::array<int64_t, 21>, 11> precom_mult{};
  for (int d = 1; d <= 10; d++) {
    for (int k = 2; k <= 20; k++) {
      int64_t multiplier = 0;
      int64_t power = 1;
      for (int i = 0; i < k; i++) {
        multiplier += power;
        power *= precom_ten[d];
      }
      precom_mult[d][k] = multiplier;
    }
  }

  while (std::cin >> x >> ignore >> y) {
    std::cin >> ignore;
    std::set<int64_t> seen;

    for (int d = 1; d <= 10; d++) {
      for (int k = 2; d * k <= 20; k++) {
        int64_t multiplier = precom_mult[d][k];

        int64_t minPattern = precom_ten[d - 1];
        int64_t maxPattern = precom_ten[d] - 1;
        int64_t firstPattern = (x + multiplier - 1) / multiplier;
        int64_t lastPattern = y / multiplier;
        firstPattern = std::max(firstPattern, minPattern);
        lastPattern = std::min(lastPattern, maxPattern);

        for (int64_t p = firstPattern; p <= lastPattern; p++) {
          int64_t num = p * multiplier;
          if (num >= x && num <= y && seen.find(num) == seen.end()) {
            sum += num;
            seen.insert(num);
          }
        }
      }
    }
  }

  std::cout << sum << '\n';
  return 0;
}
