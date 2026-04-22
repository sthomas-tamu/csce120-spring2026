#include <iostream>
#include <string>

class Automobile {
 private:
  int model_year_;
  std::string make_;

 protected:
  double fuel_capacity_g;

 public:
  Automobile(int y, std::string s, double f)
    : model_year_(y), make_(s), fuel_capacity_g(f) {}

  virtual double get_range() const {
    // compute from gas
    return fuel_capacity_g;
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
    return fuel_capacity_g + battery_capacity_;
  }
};

int main() {
  Hybrid prius(2024, "Prius", 11.3, 13.6);
  Automobile a = prius;
  Automobile& b = prius;
  Automobile* c = &prius;

  // TODO(@Student): experiment with what get_range() outputs
  //                 for different data types:
  //                 Hybrid, Automobile, Automobile&, Automobile*

  return 0;
}
