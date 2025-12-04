#include <cmath>
#include <iostream>

auto main() -> int {

  int64_t x, y, sum = 0;
  char ignore;

  while (std::cin >> x >> ignore >> y) {
    std::cin >> ignore; // to ignore comma :P

    for (int i = 1; i < 11; i++) {

      int64_t multiplier = std::pow(10, i) + 1;

      int64_t maxPattern = std::pow(10, i) - 1;
      int64_t minPattern = std::pow(10, i - 1);

      int64_t firstPattern = (x + multiplier - 1) / multiplier;
      int64_t lastPattern = y / multiplier;

      firstPattern = std::max(firstPattern, minPattern);
      lastPattern = std::min(lastPattern, maxPattern);

      if (firstPattern > lastPattern)
        continue;

      int64_t count = lastPattern - firstPattern + 1;
      int64_t patternSum = count * (firstPattern + lastPattern) / 2;

      sum += patternSum * multiplier;
    }
  }

  std::cout << sum << '\n';
  return 0;
}
