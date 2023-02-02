// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program loops through the characters a-z and prints out their integer value
// Lesson: Shows how while loops and for loops work
#include <iostream>

int main(void) {
  int i = 'a';        // start at 'a'

  while (i < char('z' + 1)) {
    std::cout << char(i) << " " << i << "\n";
    ++i;                                            // increase i value after every iteration
  }

  for (i = char('A'); i < char('Z' + 1); ++i) {
    std::cout << char(i) << " " << i << "\n";
  }

  return 0;
}