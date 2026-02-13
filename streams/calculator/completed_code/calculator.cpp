#include <iostream>
#include <sstream>
#include <string>

double calculate(std::string line) {
  double first_number = 0, second_number = 0;
  char op = ' ';

  std::istringstream iss(line);
  // TODO(@Student): extract <first_number> <op> <second_number> from iss
  //                 any errors should throw an invalid_argument exception
  if(!(iss >> first_number)) {
    std::ostringstream os;
    os << "Unable to parse first number in '" << line << "'";
    throw std::invalid_argument(os.str());
  }

  if(!(iss >> op)) {
    std::ostringstream os;
    os << "Unable to parse operator in '" << line << "'";
    throw std::invalid_argument(os.str());
  }

  if(!(iss >> second_number)) {
    std::ostringstream os;
    os << "Unable to parse second number in '" << line << "'";
    throw std::invalid_argument(os.str());
  }

  double result = 0;
  // TODO(@Student): compute result based on op symbol,
  //                 allowed symbols are +, -, *, /
  //                 any errors should throw an invalid_argument exception
  switch (op) {
    case '+':
      result = first_number + second_number;
      break;
    case '-':
      result = first_number - second_number;
      break;
    case '*':
      result = first_number * second_number;
      break;
    case '/':
      result = first_number / second_number;
      break;
    default:
      std::ostringstream os;
      os << "Invalid operator '" << op << "', only +, -, *, / allowed";
      throw std::invalid_argument(os.str());
  }

  return result;
}

int main() {
  std::cout << "Enter the expression to calculate in one line: " << std::endl;
  std::string line;
  std::getline(std::cin, line);

  try {
    std::cout << "result: " << calculate(line) << std::endl;
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << std::endl;
  }

  return 0;
}
