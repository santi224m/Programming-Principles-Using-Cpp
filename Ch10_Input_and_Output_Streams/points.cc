#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

class Point {
  public:
    Point() : point_(0) {};
    Point(int point) : point_(point) {};
    int GetPoint() { return point_; };
  private:
    int point_;
};


int main() {
  std::cout << "Please enter file name: ";
  std::string iname;
  std::cin >> iname;
  std::ifstream ist {iname};
  if (!ist) throw std::runtime_error("can't open input file");
  std::vector<Point> points;
  for (int p; ist >> p;) {
    points.push_back(Point(p));
  }

  std::cout << "Total Qty of Points: " << points.size() << std::endl;
  for (Point p: points) {
    std::cout << p.GetPoint() << std::endl;
  }

  std::cout << "Please enter a file name to fill: ";
  std::string oname;
  std::cin >> oname;
  std::ofstream ost {oname};
  if (!ost) throw std::runtime_error("Can't open output file");
  std::vector<Point> fill_vector;
  for (int i = 0; i < 100; ++i) {
    fill_vector.push_back(Point(i));
  }
  for (Point p : fill_vector) {
    ost << p.GetPoint() << std::endl;
  }

  std::cout << "Done!" << std::endl;
  
  return 0;
}