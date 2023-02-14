// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program prints out a table of square from 0 - 99.
// It calulates square by addition instead of using multiplication
// Lesson: Shows how to create functions
#include <iostream>

int square(int x) {
  int total = 0;
  for (int i = 0; i < x; ++i) {
    total += x;
  }

  return total;
}

int main(void) {
  for (int i = 0; i < 100; ++i) {
    std::cout << i << "\t" << square(i) << "\n";
  }

  return 0;
}