// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: Converts from miles to kilometers
#include <iostream>

int main(void) {
  double miles;
  std::cout << "Enter the number of miles: ";
  std::cin >> miles;
  std::cout << miles << " miles = " << miles * 1.60934 << " kilomters\n";

  return 0;
}