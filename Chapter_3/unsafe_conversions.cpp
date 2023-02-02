// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program demonstrates some unsafe converions
#include <iostream>

int main(void) {
  int a = 20000;
  char c = a;
  int b = c;

  std::cout << "a: " << a << std::endl;  //output: 200000
  std::cout << "c: " << c << std::endl;  //output:
  std::cout << "b: " << b << std::endl;  //output: 32
  // char cannot hold a value of 200000 because it is too big

  return 0;
}