
#include <cstddef>  // for size_t type;
#include <iostream>

using std::cout;
using std::endl;

template <int BASE = 10>
constexpr size_t get_digit_count(int value) {
  size_t rtn = 0;
  if (value < 0) value *= -1;
  do {
    value /= BASE;
    ++rtn;
  } while (value != 0);
  return rtn;
}
constexpr size_t digit_count_test = get_digit_count(-12345678);

int main(void) {
  cout << digit_count_test << endl;
  for (int i = 1; i < 0xffff; i *= 10) cout << get_digit_count(i) << endl;

  return 0;
}