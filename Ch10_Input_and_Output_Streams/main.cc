#include <iostream>
#include <vector>

int main() {
  const int not_a_reading = -7777;  // less than absolute 0
  const int not_a_month = -1;

  struct Day {
    std::vector<double> hour {std::vector<double>(24, not_a_reading)};
  };

  struct Month {
    int month {not_a_month};
    std::vector<Day> day {32};
  };

  Month nov;
  std::cout << nov.month << std::endl;
  std::cout << nov.day.size();

  return 0;
}