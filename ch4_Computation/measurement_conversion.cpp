// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summay: This program converts from inches to centimeters or centimeters to inches
// Lesson: Shows how if statements work and how to test for bad input.
// Also shows how switch statements can be a better option than if statements
#include <iostream>

int main(void) {
  constexpr double cm_per_inch = 2.54;    // number of centimeters in an inch
  double length = 1;                      // length in inches or centimeters
  char unit = ' ';                         // a space is not a unit

  std::cout << "Please enter a length followed by a unit (c or i):\n";
  std::cin >> length >> unit;

  // if (unit == 'i')
  //   std::cout << length << "in == " << cm_per_inch*length << "cm\n";
  // else if (unit == 'c')
  //   std::cout << length << "cm == " << length/cm_per_inch << "in\n";\
  // else
  //   std::cout << "Sorry, I don't know a unit called " << unit << "\n";      //an else statement that runs if user enters bad input
  
  switch (unit) {
    case 'i':
      std::cout << length << "in == " << cm_per_inch*length << "cm\n";
      break;
    case 'c':
      std::cout << length << "cm == " << length/cm_per_inch << "in\n";\
      break;
    default:
      std::cout << "Sorry, I don't know a unit called " << unit << "\n";
      break;
  }

  return 0;
}