#include <iostream>

int create_integer(int i) {
  int* z = new int{i};
  return *z;
}

int main() {
  int w = create_integer(12);
  std::cout << w << std::endl;

  w = create_integer(3);
  std::cout << w << std::endl;

  return 0;
}
