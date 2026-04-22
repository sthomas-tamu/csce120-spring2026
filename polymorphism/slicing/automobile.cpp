#include <iostream>
#include <string>

class Automobile {
 private:
  int model_year_;
  std::string make_;

 protected:
  double fuel_capacity_;

 public:
  Automobile(int y, std::string s, double f)
    : model_year_(y), make_(s), fuel_capacity_(f) {}

  virtual double get_range() const {
    // compute from gas
    return fuel_capacity_;
  }
};

class Hybrid : public Automobile {
 private:
  double battery_capacity_;

 public:
  Hybrid(int y, std::string s, double f, double b)
    : Automobile(y, s, f), battery_capacity_(b) {}

  double get_range() const override {
    // compute from battery and gas
    return fuel_capacity_ + battery_capacity_;
  }
};

int main() {
  Hybrid prius(2024, "Prius", 11.3, 13.6);
  Automobile automobile = prius;
  Automobile& automobile_reference = prius;
  Automobile* automobile_pointer = &prius;

  // TODO(@Student): experiment with what get_range() outputs
  //                 for different ways objects are created
  //                 Hybrid, Automobile, Automobile&, Automobile*

  return 0;
}
