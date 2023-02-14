// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: Showcase the different math operators in C++
#include <iostream>
#include <cmath>

int main(void) {
  std::cout << "Please enter a floating-point value: ";
  double n;
  std::cin >> n;
  std::cout << "n == " << n
             << "\nn+1 == " << n + 1
             << "\nthree times n == " << n * 3
             << "\ntwice n == " << n + n
             << "\nn squared == " << n * n
             << "\nhalf of n == " << n / 2
             << "\nsquare root of n == " << std::sqrt(n)
             << "\n";
  return 0;
}