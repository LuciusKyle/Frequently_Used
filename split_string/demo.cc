
#include <regex>
#include <string>
#include <vector>

template <char SPLITTER = '|'>
std::vector<std::string> split_string(const char *str, const size_t str_size) {
  std::vector<std::string> vec;
  vec.push_back(std::string());
  for (size_t i = 0, j = 0; i < str_size; ++i) {
    if (str[i] == SPLITTER) {
      vec.push_back(std::string());
      j++;
      continue;
    }
    vec[j].push_back(str[i]);
  }
  if (vec.back().empty()) vec.pop_back();
  return vec;
}

int main(int argc, char *argv[]) {
  std::string str("12|34|5,67|8");

  auto vec = split_string(str.c_str(), str.size());
  auto vec2 = split_string<','>(str.c_str(), str.size());

  return 0;
}
