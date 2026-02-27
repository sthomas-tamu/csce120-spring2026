#ifndef DICE_H_
#define DICE_H_

class Dice {
 private:
  unsigned int sides_;
  unsigned int value_;

 public:
  // Constructor
  Dice(unsigned int n) : sides_{n}, value_{0} {}

  // Getter methods
  unsigned int sides() const;
  unsigned int value() const;

  void roll();
};

#endif  // DICE_H_
