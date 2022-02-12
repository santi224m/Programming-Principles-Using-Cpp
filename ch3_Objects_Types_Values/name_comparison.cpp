// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: Demonstrates how you can use operators on strings
#include <iostream>
#include <string>

int main(void) {
  std::cout << "Please enter two names: ";
  std::string first;
  std::string second;
  std::cin >> first >> second;
  if (first == second) std::cout << "Thats the same name twice\n";
  if (first < second)
    std::cout << first << " is alphabetically before " << second << std::endl;
  if (first > second)
    std::cout << first << " is alphabetically after " << second << std::endl;
  
  return 0;
}