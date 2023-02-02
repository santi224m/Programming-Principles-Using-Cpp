#include <iomanip>
#include <iostream>

int main() {
  std::cout << 123456 << '|' << std::setw(4) << 123456 << '|' << std::setw(8) << 123456 << '|' << 123456 << std::endl;
  
  return 0;
}