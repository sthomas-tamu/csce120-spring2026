#include <iostream>
#include <string>
#include <vector>

int half(int n) {
  return n / 2;
}

std::string half(const std::string& s) {
  return s.substr(half(s.length()));
}

// TODO(@Student): implement half for vector<int>

int main() {
  std::cout << half(13) << std::endl;
  std::cout << half("strawberry") << std::endl;

  /*
  // TODO(@Student): after implement half, this should work
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<int> vec_half = half(vec);
  for (const int& element : vec_half)
    std::cout << element << " ";
  std::cout << std::endl;
  */

  return 0;
}
