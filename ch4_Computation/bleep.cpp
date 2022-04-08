// Santiago Mondragon
// Last modified: Feb 20, 2022
// Summary: This program takes in input from the user and if the user inputs
// certain words then the program will print out "BLEEP" instead of the word.
// Otherwise, it will print out the word the user entered
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::vector<std::string> disliked = {"Broccolli", "Kale", "Spinach", "Beets"};

  for (std::string word;std::cin >> word;) {
    for (int i = 0; i < disliked.size(); ++i) {
      if (word == disliked[i])
        word = "BLEEP";
    }

    std::cout << word << '\n';
  }

  return 0;
}