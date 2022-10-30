// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program detects when a word is repeated
#include <iostream>
#include <string>

int main(void) {
  int numOfWords = 0;
  std::string previous = " ";
  std::string current;
  while (std::cin >> current) {
    ++numOfWords;
    if (previous == current)
      std::cout << "Word Number: " << numOfWords << "\nRepeated word: " << current << std::endl;
    previous = current;
  }
  
  return 0;
}