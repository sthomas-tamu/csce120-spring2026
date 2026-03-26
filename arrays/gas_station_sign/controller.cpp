#include "gas_sign.h"


void display_choices(std::ostream& os) {
  os << "What would you like to do?\n";
  os << "\tD - display sign\n";
  os << "\tC - clear sign\n";
  os << "\tP - set prices\n";
  os << "\tB - bulb check\n";
  os << "\tQ - quit\n";
}


int main() {
  GasSign sign_regular;

  char choice = ' ';
  double price = 0;

  while (toupper(choice) != 'Q') {
    display_choices(std::cout);
    std::cin >> choice;

    switch (toupper(choice)) {
      case 'C':
        sign_regular.clear();
        std::cout << "sign cleared\n";
        break;

      case 'B':
        sign_regular.bulb_check();
        std::cout << "all bulbs should be on:\n";
        // no break because want it to display the sign after turning all bulbs on

      case 'D':
        std::cout << "Regular:\n";
        sign_regular.display(std::cout);
        std::cout << "\n";
        break;

      case 'P':
        try {
          // read in and set regular price
          std::cout << "What is the price for regular?\n";
          std::cin >> price;
          if (std::cin.fail() || price < 0 || price > 10)
            throw std::invalid_argument("Invalid regular price, must be less than 10.00.");
          sign_regular.set_price(price);
        }
        catch (std::invalid_argument& e) {
          std::cout << e.what() << " Price not updated.\n";
          // reset cin to be ready to read again
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        break;

      case 'Q':
        std::cout << "Goodbye!\n";
        break;

      default:
        std::cout << "Invalid choice, try again.\n";
        break;
    }
  }

  return 0;
}
