// Santiago Mondragon
// Last modified: Feb 20, 2022
// Summary: This code is for the drill in Chapter 4.
#include <iostream>
#include <vector>
#include <string>

int main(void) {
  double smallest;
  double largest;
  std::string unit;       //cm, m, n, and ft
  double temp;        //stores value while it is compared to smallest and largest
  std::cout << "Enter a number: ";
  std::cin >> temp >> unit;           //initial value is automatically set to smallest and largest
  largest= temp;
  smallest = temp;
  std::cout << "Smallest and largest values so far\n";
  while (std::cin>>temp>>unit) {
    std::cout << "You entered: " << temp << unit << '\n';
    if (temp < smallest) {
      smallest = temp;
      std::cout << "Smallest value so far\n"; 
    }
    if (temp > largest) {
      largest = temp;
      std::cout << "Largest value so far\n";
    }
  }
}