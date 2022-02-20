// Santiago Mondragon
// Last modified: feb 19, 2022
// Summary: This program determines whether an integer is odd or even
#include <iostream>

int main(void) {
  int val;

  std::cout << "Enter an integer: ";
  std::cin >> val;

  if (val % 2 == 0) {
    std::cout << "The value " << val << " is an even number\n";
  } else {
    std::cout << "The value " << val << " is an odd number\n";
  }

  return 0;
}