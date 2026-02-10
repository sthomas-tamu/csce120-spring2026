#include <iostream>
#include <string>

int main() {
  std::string term;

  do {
    std::cout << "Enter std::string to convert to an integer or 'x' to exit: ";
    std::cin >> term;

    if (term != "x") {
      size_t size = 0;
      // the following code may throw an exception, update to handle it
      int value = std::stoi(term, &size);
      std::cout << term << " times 2 is " << (value * 2) << std::endl;
    }
  } while (term != "x");

  return 0;
}
