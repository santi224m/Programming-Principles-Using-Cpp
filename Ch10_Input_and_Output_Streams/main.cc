#include <cctype>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void skip_to_int() {
  if (std::cin.fail()) {  // we found a non integer
    std::cin.clear();  // set cin state back to good()
    for (char ch; std::cin >> ch;) {  // throw away non digits
      if (std::isdigit(ch) || ch == '-') {
        std::cin.unget();  // put the digit back into the stream
        return;
      }
    }
  }
  throw std::runtime_error("no input");
}

int get_int() {
  int n = 0;
  while (true) {
    if (std::cin >> n) return n;
    std::cout << "Sorry, that was not a number; please try again\n";
    skip_to_int();
  }
}

int get_int(int low, int high) {
  std::cout << "Please enter an integer in the range " << low << " to " << high
            << " (inclusive):\n";
  while (true) {
    int n = get_int();
    if (n >= low && n <= high) return n;
    std::cout << "Sorry, " << n << " is not in the [" << low << ":" << high
              << "] range; please try again\n";
  }
}

int main() {
  int n = get_int(1,10);
  std::cout << "Double of " << n << " is: " << n * 2 << std::endl;

  int m = get_int(0,100);
  std::cout << "Half of " << m << " is: " << m / 2 << std::endl;

  return 0;
} 