#include <iostream>

auto main() -> int {

  std::string s;
  int64_t count{};

  while (std::cin >> s) {

    int64_t ans{}, max_num,loc{};
    char first_digit = '#', second_digit = '#';

    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] > first_digit) {
        first_digit = s[i];
        loc = i;
      }
    }

    // left side second max
    for (ssize_t i = loc - 1; i >= 0; i--) {
      if (s[i] > second_digit) {
        second_digit = s[i];
      }
    }

    max_num = first_digit - '0';
    max_num += 10 * (second_digit - '0');

    if (second_digit == '#')
      max_num = 0;


    //  right side second max
    second_digit = '#';
    for (ssize_t i = loc + 1; i < s.size(); i++) {
      if (s[i] > second_digit) {
        second_digit = s[i];
      }
    }

    ans = second_digit - '0';
    ans += 10 * (first_digit - '0');

    std::cout << ans << '\n';
    ans = std::max(ans, max_num);
    count += ans;
  }
  std::cout << count;

  return 0;
}
