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

int get_int(int low, int high, const std::string& greeting, const std::string& sorry) {
  std::cout << greeting << low << " : " << high << '\n';
  while (true) {
    int n = get_int();
    if (n >= low && n <= high) return n;
    std::cout << sorry << ": [" << low << ":" << high
              << "]\n";
  }
}

int main() {
  int n = get_int(1,10, "Please enter an integer in the range ", "Sorry, the value entered is out of range");
  std::cout << "Double of " << n << " is: " << n * 2 << std::endl;

  int m = get_int(0,100, "Please enter an integer in the range ", "Sorry, the value entered is out of range");
  std::cout << "Half of " << m << " is: " << m / 2 << std::endl;

  return 0;
} 