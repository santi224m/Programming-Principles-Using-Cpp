// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program takes in an operation followed by two operands and outputs the value.
#include <iostream>
#include <string>

int main(void) {
  std::string operation;
  double val1;
  double val2;

  std::cout << "Enter an opeation and two numbers: ";
  std::cin >> operation >> val1 >> val2;

  if (operation == "+" || operation == "plus") {
    std::cout << val1 << " + " << val2 << " = " << val1 + val2 << std::endl;
  } else if (operation == "-" || operation == "minus") {
    std::cout << val1 << " - " << val2 << " = " << val1 - val2 << std::endl;
  } else if (operation == "*" || operation == "mul") {
    std::cout << val1 << " * " << val2 << " = " << val1 * val2 << std::endl;
  } else if (operation == "/" || operation == "div") {
    std::cout << val1 << " / " << val2 << " = " << val1 / val2 << std::endl;
  } else {
    std::cout << "Invalid input\n";
  }

  return 0;
}