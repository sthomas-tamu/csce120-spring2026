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
  for (unsigned int row = 0; row < height; ++row)
    for (unsigned int col = 0; col < width; ++col)
      bulbs[row][col] = OFF;
}


// turn all bulbs on to prepare for a maintanence check
void GasSign::bulb_check() {
  for (unsigned int row = 0; row < height; ++row)
    for (unsigned int col = 0; col < width; ++col)
       bulbs[row][col] = ON;
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
  for (unsigned int digit_row = 0; digit_row < DIGIT_HEIGHT; digit_row++)
    for (unsigned int digit_col = 0; digit_col < DIGIT_WIDTH; digit_col++) {
      unsigned int bulbs_row = start_row + digit_row;
      unsigned int bulbs_col = start_col + digit_col;
      bulbs[bulbs_row][bulbs_col] = bulb_digit_patterns[digit][digit_row][digit_col];
    }
}


// helper function to turn bulbs on for the 9/10 cent
void GasSign::place_remainder(unsigned int start_row, unsigned int start_col) {
  // top left corner is start_row, start_col
  for (unsigned int digit_row = 0; digit_row < DIGIT_HEIGHT; digit_row++)
    for (unsigned int digit_col = 0; digit_col < 3; digit_col++) {
      unsigned int bulbs_row = start_row + digit_row;
      unsigned int bulbs_col = start_col + digit_col;
      bulbs[bulbs_row][bulbs_col] = bulb_remainder_pattern[digit_row][digit_col];
    }
}
