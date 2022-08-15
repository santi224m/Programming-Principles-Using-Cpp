#include <iostream>
using namespace std;

int area(int length, int width)   //calculate area of a rectangle
{
  return length * width;
}

int framed_area(int x, int y)   //calculate area within frame
{
  return area(x-2,y-2);
}

int main(void)
{
  int x = -1;
  int y = 2;
  int z = 4;
  //...
  if (x<=0) cerr << "non-positive x" << endl;
  if (y<=0) cerr << "non-positive y" << endl;
  //...
  int area1 = area(x,y);
  int area2 = framed_area(1,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1) / area3;
  //...
  cout << "area1: " << area1 << endl;
  cout << "area2: " << area2 << endl;
  cout << "area3: " << area3 << endl;
  cout << "ratio: " << ratio << endl;

  return 0;
}