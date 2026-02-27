#include <cstdlib>
#include "Dice.h"

unsigned int Dice::sides() const {
  return sides_;
}

unsigned int Dice::value() const {
  return value_;
}

void Dice::roll() {
  value_ = 1 +  (rand() % sides_);
}
