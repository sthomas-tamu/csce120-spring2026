#ifndef GAS_SIGN_H_
#define GAS_SIGN_H_

#include <iostream>

// sign is 7 bulbs tall and 24 bulbs wide
// prices are displayed as follows:
// (d = dollars, t = tenths, h = hundreds, x = fractional 9/10 cent, coords shown)
//  012345678901234567890123
// 0 dddd   tttt  hhhh  xxx 0
// 1 dddd   tttt  hhhh  x x 1
// 2 dddd   tttt  hhhh  xxx 2
// 3 dddd   tttt  hhhh    x 3
// 4 dddd   tttt  hhhh    x 4
// 5 dddd   tttt  hhhh      5
// 6 dddd . tttt  hhhh      6
//  012345678901234567890123

class GasSign {
  static const unsigned int height = 7;
  static const unsigned int width = 24;

  char bulbs[height][width];

 public:
  GasSign() { clear(); }

  void display(std::ostream& os) const;

  // turn all bulbs off
  void clear();

  // turn all bulbs on to prepare for a maintanence check
  void bulb_check();

  // turn bulbs on/off for the new gas price
  void set_price(double price);

 private:
  // helper function to turn bulbs on for a signle digit
  void place_digit(unsigned int start_row, unsigned int start_col,
                   unsigned int digit);

  // helper function to turn bulbs on for the 9/10 cent
  void place_remainder(unsigned int start_row, unsigned int start_col);
};

#endif  // GAS_SIGN_H
