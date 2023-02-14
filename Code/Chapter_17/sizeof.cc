// Demonstrate how the sizeof() function works
#include <iostream>
#include <string>

class Car {
  public:
    Car(std::string brand, std::string model, int year) : brand_(brand), model_(model), year_(year) {}

  private:
    std::string brand_;
    std::string model_;
    int year_;
};

void sizes(char ch, int i, int* p, bool b, double d, Car c) {
  std::cout << "the size of char is " << sizeof(char) << ' ' << sizeof(ch) << '\n';
  std::cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
  std::cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
  std::cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
  std::cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
  std::cout << "the size of Car is " << sizeof(Car) << ' ' << sizeof(c) << '\n';
}

int main() {
  char ch = 'c';
  int num = 7;
  int* ptr = &num;
  bool isWorking = true;
  double d = 17.23;
  Car mustang = Car("Ford", "Mustang", 2023);

  sizes(ch, num, ptr, isWorking, d, mustang);
  return 0;
}

// Output:
// the size of char is 1 1
// the size of int is 4 4
// the size of int* is 8 8
// the size of bool is 1 1
// the size of double is 8 8
// the size of Car is 72 72