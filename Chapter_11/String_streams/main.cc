#include <exception>
#include <iostream>
#include <string>
#include <sstream>

double str_to_double(std::string s) {
  std::istringstream is {s};
  double d;
  is >> d;
  if (!is) throw std::runtime_error("double format error: " + s);
  return d;
}

int main() {
  double d1 = str_to_double("12.4");
  std::cout << d1 << std::endl;
  double d2 = str_to_double("1.34e-3");
  std::cout << d2 << std::endl;
  double d3 = str_to_double("twelve point three");
  std::cout << d3 << std::endl;
}