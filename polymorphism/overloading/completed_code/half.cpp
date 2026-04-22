#include <iostream>
#include <string>
#include <vector>

int half(int n) {
  return n / 2;
}

std::string half(const std::string& s) {
  return s.substr(half(s.length()));
}

std::vector<int> half(const std::vector<int>& v) {
  return std::vector<int>(v.begin(), v.begin() + half(v.size()));
}

int main() {
  std::cout << half(13) << std::endl;
  std::cout << half("strawberry") << std::endl;

  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<int> vec_half = half(vec);
  for (const int& element : vec_half)
    std::cout << element << " ";
  std::cout << std::endl;

  return 0;
}
