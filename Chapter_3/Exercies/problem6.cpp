// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: This program takes in three integers and ouputs them in numerical order
#include <iostream>

int main(void) {
  int num1;
  int num2;
  int num3;
  int largest;
  int middle;
  int smallest;

  std::cout << "Enter the first number: ";
  std::cin >> num1;
  std::cout << "Enter the second number: ";
  std::cin >> num2;
  std::cout << "Enter the third number: ";
  std::cin >> num3;

  if (num1 >= num2 && num1 >= num3) {
    largest = num1;

    if (num2 >= num3) {
      middle = num2;
      smallest = num3;
    } else {
      middle = num3;
      smallest = num2;
    }
  } else if (num2 >= num1 && num2 >= num3) {
    largest = num2;

    if (num1 >= num3) {
      middle = num1;
      smallest = num3;
    } else {
      middle = num3;
      smallest = num1;
    }
  } else {
    largest = num3;

    if (num1 >= num2) {
      middle = num1;
      smallest = num2;
    } else {
      middle = num2;
      smallest = num1;
    }
  }

  std::cout << smallest << " " << middle << " " << largest << std::endl;

  return 0;
}