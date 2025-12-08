#include <iostream>
#include <string>

auto main() -> int {
  std::string s;
  __int128 total{};

  while (std::cin >> s) {

    ssize_t skipped{}, to_skip = s.size() - 12;
    std::string result;

    for (size_t i = 0; i < s.size(); i++) {
      while (!result.empty() && result.back() < s[i] && skipped < to_skip) {
        result.pop_back();
        skipped++;
      }
      result += s[i];
    }

    // Don't worry bruh! the last 12+x characters are guaranteed to be smaller
    // than the prior numbers since we already checked in the while loop :P
    result = result.substr(0, 12);

    __int128 num = 0;
    for (char c : result) {
      num = num * 10 + (c - '0');
    }
    total += num;
  }

  std::string out;
  __int128 temp = total;
  while (temp > 0) {
    out = char('0' + temp % 10) + out;
    temp /= 10;
  }

  std::cout << out << '\n';

  return 0;
}
