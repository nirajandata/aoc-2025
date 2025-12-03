#include <charconv>
#include <iostream>
#include <string>

auto main() -> int {

  int64_t count{};
  int cal = 50, val;
  std::string x;

  while (std::cin >> x) {
    std::from_chars(x.data() + 1, x.data() + x.size(), val);

    int dir = x[0] == 'L' ? -1 : 1;

    int pos;
    if (dir == 1) {
      pos = 100 - cal;
    } else {
      pos = cal;
    }

    if (pos == 0)
      pos = 100;

    if (val >= pos)
      count += 1 + (val - pos) / 100;

    while (val >= 100)
      val -= 100;
    cal += dir * val;

    while (cal < 0)
      cal += 100;
    while (cal >= 100)
      cal -= 100;
  }

  std::cout << count << '\n';
  return 0;
}
