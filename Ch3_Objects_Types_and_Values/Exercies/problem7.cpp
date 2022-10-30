// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program takes in three words and ouputs them in alphabetical order
#include <iostream>
#include <string>

int main(void) {
  std::string word1;
  std::string word2;
  std::string word3;
  std::string largest;
  std::string middle;
  std::string smallest;

  std::cout << "Enter the first word: ";
  std::cin >> word1;
  std::cout << "Enter the second word: ";
  std::cin >> word2;
  std::cout << "Enter the third word: ";
  std::cin >> word3;

  if (word1 >= word2 && word1 >= word3) {
    largest = word1;

    if (word2 >= word3) {
      middle = word2;
      smallest = word3;
    } else {
      middle = word3;
      smallest = word2;
    }
  } else if (word2 >= word1 && word2 >= word3) {
    largest = word2;

    if (word1 >= word3) {
      middle = word1;
      smallest = word3;
    } else {
      middle = word3;
      smallest = word1;
    }
  } else {
    largest = word3;

    if (word1 >= word2) {
      middle = word1;
      smallest = word2;
    } else {
      middle = word2;
      smallest = word1;
    }
  }

  std::cout << smallest << " " << middle << " " << largest << std::endl;

  return 0;
}