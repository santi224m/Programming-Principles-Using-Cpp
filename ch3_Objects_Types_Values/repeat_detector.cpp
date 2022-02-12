// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program detects when a word is repeated
#include <iostream>
#include <string>

int main(void) {
  std::string previous = " ";
  std::string current;
  while (std::cin >> current) {
    if (previous == current)
      std::cout << "Repeated word: " << current << std::endl;
    previous = current;
  }
  
  return 0;
}