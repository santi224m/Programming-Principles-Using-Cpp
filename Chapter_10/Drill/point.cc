#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

class Point {
  public:
    Point() : x_(0), y_(0) {}
    Point(int x, int y) : x_(x), y_(y) {}
    void SetX(int x) { x_ = x; }
    void SetY(int y) { y_ = y; }
    int GetX() { return x_; }
    int GetY() { return y_; }

  private:
    int x_;
    int y_;
};

std::istream& operator>>(std::istream& is, Point& p) {
  char ch1, char2, char3;
  int px, py;
  // Check if there is another point to process
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }
  is >> px >> char2 >> py >> char3;
  p.SetX(px);
  p.SetY(py);
  return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
  return os << '(' << p.GetX() << ',' << p.GetY() << ')';
}