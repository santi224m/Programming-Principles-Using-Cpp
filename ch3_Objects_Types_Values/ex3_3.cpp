// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This program demonstrated that you can enter two values to variables at once
#include <iostream>
#include <string>

int main(void) {
  std::cout << "Please enter your first name and age\n";
  std::string firstName;
  int age;
  std::cin >> firstName;
  std::cin >> age;
  std::cout << "Hello, " << firstName << " (age " << age << ")\n";

  return 0;
}