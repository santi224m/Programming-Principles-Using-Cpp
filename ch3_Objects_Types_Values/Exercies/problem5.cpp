// Santiago Mondragon
// Last modified: Feb 19, 2022
// Summary: The user enters 2 numbers (Floats). The program will then show the largest number,
// smallest number, sum, difference, product, and ratio
#include <iostream>

int main(void) {
  float val1;
  float val2;

  std::cout << "Enter 2 float numbers: ";
  std::cin >> val1 >> val2;

  if (val1 > val2) {
    std::cout << "Larger: " << val1 << "\nSmaller: " << val2 << std::endl;
  } else {
    std::cout << "Larger: " << val2 << "\nSmaller: " << val1 << std::endl;
  }

  std::cout << "Sum: " << val1 + val2 << std::endl;
  std::cout << "Difference: ";

  if (val1 - val2 < 0) {
    std::cout << (val1 - val2) * -1 << std::endl;
  } else {
    std::cout << val1 - val2 << std::endl;
  }
  
  std::cout << "Product: " << val1 * val2 << std::endl;
  std::cout << "Ratio: " << val1 << ":" << val2;
  std::cout << "\n";


  return 0; 
}