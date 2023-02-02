#include "../../std_lib_facilities.h"

class Bad_area {};    // a type specifically for reporting errors from area()

// calculate area of a rectangle
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
  if (length<=0 || width<=0) throw Bad_area{};
  return length*width;
}

int main(void)
try {
  int x = -1;
  int y = 2;
  int z = 4;

  int area1 = area(x, y);
  cout << area1 << endl;
}
catch (Bad_area) {
  cout << "Oops! Bad argument to area()\n";
}