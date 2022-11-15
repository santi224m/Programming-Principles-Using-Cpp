#include <iostream>
#include <fstream>
#include <vector>
#include <exception>

#include "point.cc"

int main() {
  const int user_inputs_qty = 7;
  std::ofstream ofs {"mydata.txt"};
  if (!ofs) throw std::runtime_error("Cannot open output file 'mydata.txt'");

  std::vector<Point> original_points;
  for (int i = 0; i < user_inputs_qty; ++i) {
    std::cout << "Enter Point " << i + 1 << ": ";
    Point p;
    std::cin >> p;
    original_points.push_back(p);
  }

  std::cout << "Printing user input...\n";
  for (Point p : original_points) {
    std::cout << p << std::endl;
    ofs << p << std::endl;
  }
  ofs.close();
  std::ifstream ifs {"mydata.txt"};
  if (!ifs) throw std::runtime_error("Cannot open input file 'mydata.txt'");

  std::vector<Point> processed_points;
  Point point_temp;
  std::cout << "Input file stream: " << std::endl;
  while (ifs >> point_temp) {
    processed_points.push_back(point_temp);
  }

  for (Point p : processed_points) {
    std::cout << p << std::endl;  
  }

  if (original_points.size() != processed_points.size()) {
    throw new std::runtime_error("Not all points were processed...");
  }

  return 0;
}