#include <iostream>
#include <limits>

int main() {
  unsigned int no_lines = 0;

  // read in number of "stairs"
  std::cout << "Please provide a number of lines to print the stair-case pattern: ";
  std::cin >> no_lines;
  std::cout << "read: " << no_lines << std::endl;

  // TODO(@Student) Check the state of cin to see if read was successful
  //   If not successful, reset cin and prompt again
  //   Otherwise, check that no_lines is valid (not 0 and not bigger than 80)
  //   If not valid, prompt again
  //   Continue to prompt user until no_lines

  // print "stairs"
  for (unsigned int i = 1; i <= no_lines ; ++i) {
    for (unsigned int j = 1 ; j <= i ; ++j) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }

  return 0;
}
