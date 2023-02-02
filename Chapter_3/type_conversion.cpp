// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program shows how types are converted in c++ by allowing
// the user to input a number and see what it is as a different type
#include <iostream>

int main(void) {
  double d = 0;
  while (std::cin >> d) {
    int i = d;            //squeeze double into an integer
    char c = i;           //squeeze integer into a character
    int i2 = c;           //get integer value of a character

    std::cout << "d==" << d
                << " i==" << i
                << " i2==" << i2
                << " char(" << c << ")\n";
  }

  return 0;
}