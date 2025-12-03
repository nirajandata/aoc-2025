#include <charconv>
#include <iostream>

auto main() -> int {

  int64_t count{};
  int val, cal = 50;

  std::string x;
  while (std::cin >> x) {
    std::from_chars(x.data() + 1, x.data() + x.size(), val);

    if (x[0] == 'L')
      val *= -1;
    cal += val;

    while (cal < 0)
      cal += 100;

    while (cal > 99) 
      cal -= 100;

    count += !cal;
  }
  std::cout << count << '\n';
  return 0;
}
