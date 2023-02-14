// Write a little program using base classes and members where you define the
// constructors and destructors to output a line of information when they are
// called. Then, create a few objects and see how their constructors and
// destructors are called.
#include <iostream>
#include <string>

class Car {
 public:
  Car(std::string name) : name_(name) {
    std::cout << "Constructed Car: " << name_ << std::endl;
  }
  ~Car() {
    std::cout << "Destructed Car: " << name_ << std::endl;
  }

 private:
  std::string name_;
};

class Person {
 public:
  Person(std::string name) : name_(name), car_(nullptr) {
    std::cout << "Constructed Person: " << name_ << std::endl;
  }
  ~Person() {
    DeleteCar();
    std::cout << "Destructed Person: " << name_ << std::endl;
  }
  void GetCar(std::string name) {
    car_ = new Car(name);
  }
  void DeleteCar() {
    if (car_) {
      delete car_;
      car_ = nullptr;
    }
    std::cout << "Car memory address: " << car_ << std::endl;
  }

 private:
  std::string name_;
  Car* car_;
};

int main () {
  Person* p1 = new Person("Adam");
  p1->GetCar("Mustang");
  p1->DeleteCar();
  p1->GetCar("Camaro");
  delete p1;
  std::cout << "p1 address before setting equal to nullptr: " << p1 << std::endl;
  p1 = nullptr;
  std::cout << "p1 address after setting equal to nullptr: " << p1 << std::endl;

  return 0;
}

// Output:
// Constructed Person: Adam
// Constructed Car: Mustang
// Destructed Car: Mustang
// Car memory address: 0
// Constructed Car: Camaro
// Destructed Car: Camaro
// Car memory address: 0
// Destructed Person: Adam
// p1 address before setting equal to nullptr: 0x55998b42aeb0
// p1 address after setting equal to nullptr: 0