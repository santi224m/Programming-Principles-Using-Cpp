// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program converts spelled out numbers into digits.
// The only values it knows are from 0 - 4.
#include <iostream>
#include <string>

int main(void) {
  std::string val;

  std::cout << "Spell out a number: ";
  std::cin >> val;

  if (val == "zero") {
    std::cout << 0 << "\n";
  } else if (val == "one") {
    std::cout << 1 << "\n";
  } else if (val == "two") {
    std::cout << 2 << "\n";
  } else if (val == "three") {
    std::cout << 3 << "\n";
  } else if (val == "four") {
    std::cout << 4 << "\n";
  } else {
    std::cout << "Not a number I know\n";
  }

  return 0;
}