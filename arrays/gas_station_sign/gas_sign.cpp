#include "gas_sign.h"
#include "digits.h"


void GasSign::display(std::ostream& os) const {
  // print top border
  os << " ";
  for (unsigned int col = 0; col < width; ++col)
    os << "_";
  os << "\n";

  // print each row with border
  for (unsigned int row = 0; row < height; ++row) {
    os << "|";
    for (unsigned int col = 0; col < width; ++col)
      os << bulbs[row][col];
    os << "|\n";
  }

  // print bottom border
  os << " ";
  for (unsigned int col = 0; col < width; ++col)
    os << "-";
  os << "\n";
}


// turn all bulbs off
void GasSign::clear() {
  // TODO(@Student): digits.h defines char ON and OFF to use
}


// turn all bulbs on to prepare for a maintanence check
void GasSign::bulb_check() {
  // TODO(@Student): digits.h defines char ON and OFF to use
}


// turn bulbs pn/off for the new gas price
void GasSign::set_price(double price) {
  // extract digits from price
  int64_t amount = std::round(price * 100.0);
  int64_t hundredths = amount % 10;
  amount /= 10;
  int64_t tenths = amount % 10;
  amount /= 10;
  int64_t dollars = amount % 10;

  // clear sign
  clear();

  // place price digits and decimal
  place_digit(0, 1, dollars);
  bulbs[height - 1][6] = ON;  // set decimal
  place_digit(0, 8, tenths);
  place_digit(0, 14, hundredths);
  place_remainder(0, 20);  // set 9/10 cent
}


// helper function to turn bulbs on for a single digit
void GasSign::place_digit(unsigned int start_row, unsigned int start_col,
                          unsigned int digit) {
  // top left corner of digit is start_row, start_col

  // TODO(@Student):
  //   digits.h provides the on/off patterns for you in bulb_digit_patterns
  //   bulb_digit_patterns is an array of 2d arrays (really a 3d array)
  //   so the 2d on/off pattern for '2' is found at bulb_digit_patterns[2]
  //   each digit pattern is DIGIT_HEIGHT tall and DIGIT_WIDTH wide
}


// helper function to turn bulbs on for the 9/10 cent
void GasSign::place_remainder(unsigned int start_row, unsigned int start_col) {
  // top left corner is start_row, start_col

  // TODO(@Student):
  //   digits.h provides the on/off pattern for the 9/10 of a cent in bulb_remainder_pattern
  //   bulb_remainder_pattern is a 2d array that is DIGIT_HEIGHT tall and 3 wide
}
