// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program demonstrates how you can convert from a char to an int
#include <iostream>

int main(void) {
  char c = 'x';
  int i1 = c;
  int i2 = 'x';

  std::cout << "c: " << c << std::endl;   //output: 'x'
  std::cout << "i1: " << i1 << std::endl; //output: 120
  std::cout << "i2: " << i2 << std::endl; //output: 120

  double d1 = 2.3;
  double d2 = d1 + 2;   //2 is converted to a double (2.0)
  std::cout << "d2: " << d2 << std::endl;

  return 0;
}