#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Reading {
  Reading(int hour, double temperature) : hour_(hour), 
                                          temperature_(temperature) {};
  int hour_;
  double temperature_;
};

int main() {
  std::ifstream ist {"temps.txt"};
  if (!ist) throw std::runtime_error("Can't open temps.txt file");
  std::ofstream ost {"temps_formatted.txt"};
  if (!ost) throw std::runtime_error("Can't open temps_formatted.txt");
  std::vector<Reading> temps;
  int hour;
  double temperature;
  while (ist >> hour >> temperature) {
    if (hour < 0 || hour > 23) 
      throw std::runtime_error("hour out of range: " + std::to_string(hour));
    temps.push_back(Reading(hour, temperature));
  }

  std::cout << "Total Temperature Readings: " << temps.size() << std::endl;

  for(Reading r : temps) {
    ost << '(' << r.hour_ << ',' << r.temperature_ << ')' << std::endl;
  }

  std::cout << "Done!" << std::endl;

  return 0;
}