// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program prompts the user for some number of coins and ouputs
// a summary of what they entered
#include <iostream>
#include <iomanip>

int main(void) {
  float pennies;
  float nickels;
  float dimes;
  float quarters;
  float halfDollars;
  float oneDollar;
  float total;

  std::cout << "How many pennies do you have?\n";
  std::cin >> pennies;
  std::cout << "How many nickels do you have?\n";
  std::cin >> nickels;
  std::cout << "How many dimes do you have?\n";
  std::cin >> dimes;
  std::cout << "How many quarters do you have?\n";
  std::cin >> quarters;
  std::cout << "How many half-dollar coins do you have?\n";
  std::cin >> halfDollars;
  std::cout << "How many one-dollar coins do you have?\n";
  std::cin >> oneDollar;

  total = pennies + (nickels * 5) + (dimes * 10) + (quarters * 25) + (halfDollars * 50) + (oneDollar * 100);
  total /= 100;

  std::cout << "You have " << pennies << " penn";
  if (pennies != 1) {
    std::cout << "ies";
  } else {
    std::cout << "y";
  }
  std::cout << "\nYou have " << nickels << " nickel";
  if (nickels != 1) std::cout << "s";
  std::cout << "\nYou have " << dimes << " dime";
  if (dimes != 1) std::cout << "s";
  std::cout << "\nYou have " << quarters << " quarter";
  if (quarters != 1) std::cout << "s";
  std::cout << "\nYou have " << halfDollars << " half-dollar coin";
  if (halfDollars != 1) std::cout << "s";
  std::cout << "\nYou have " << oneDollar << " one-dollar coin";
  if (oneDollar != 1) std::cout << "s";
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "\nThe value of all your coins is $" << total << std::endl;

  return 0;
}