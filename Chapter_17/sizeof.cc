// Demonstrate how the sizeof() function works
#include <iostream>

void sizes(char ch, int i, int* p) {
  std::cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
  std::cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
  std::cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
}

int main() {
  char ch = 'c';
  int num = 7;
  int* ptr = &num;

  sizes(ch, num, ptr);
  return 0;
}

// Output:
// the size of char is 1 1
// the size of int is 4 4
// the size of int* is 8 8