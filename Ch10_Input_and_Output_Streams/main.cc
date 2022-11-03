#include <ios>
#include <istream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const int not_a_reading = -7777;  // less than absolute 0
const int not_a_month = -1;
const int days_in_a_month = 32;  // we use 32 so that the month doesn't start with 0
const int months_in_a_year = 12;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

struct Day {
  std::vector<double> hour {std::vector<double>(24, not_a_reading)};
};

struct Month {  // a month of temperature readings
  int month {not_a_month};  // [0:11] January is 0
  std::vector<Day> day {days_in_a_month};  // [1:31] one vector of readings per day
};

struct Year {  // a year of temperature readings organized by month
  int year;
  std::vector<Month> month {months_in_a_year};  // [0:11] January is 0
};

struct Reading {
  int day;
  int hour;
  double temperature;
};

void end_of_loop(std::istream& ist, char term, const std::string& message) {
  if (ist.fail()) { // use term as terminator
    ist.clear();
    char ch;
    if (ist >> ch && ch == term) return;  // all is fine
    throw std::runtime_error(message);
  }
}

bool is_valid(const Reading& r) {
  if (r.day < 1 || r.day > days_in_a_month - 1)
  if (r.hour < 0 || r.hour > 23)
  if (r.temperature < implausible_min || r.temperature > implausible_max)
    return false;
  return true;
}

std::istream& operator>>(std::istream& is, Reading& r) {
  // read a temperature reading from is into r
  // format: ( 3 4 9.7 )
  // check format, but don't bother with data validity
  char ch1;
  if (is >> ch1 && ch1 != '(') {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }

  char ch2;
  int d;
  int h;
  double t;
  is >> d >> h >> t >> ch2;
  if (!is || ch2 != ')') throw std::runtime_error("bad readding");
  r.day = d;
  r.hour = h;
  r.temperature = t;
  return is;
}

std::istream& operator>>(std::istream& is, Month& m) {
  // read a month from is into m
  // format { month feb ...}
  char ch;
  if (is >> ch && ch != '{') {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }

  std::string month_marker;
  std::string mm;
  is >> month_marker >> mm;
  if (!is || month_marker != "month") {
    throw std::runtime_error("bad start of month");
  }
  m.month = month_to_int(mm);
  int duplicates = 0;
  int invalids = 0;
  for (Reading r; is >> r;) {
    if (is_valid(r)) {
      if (m.day[r.day].hour[r.hour] != not_a_reading)  // before we set a value to the temperature, check if it already has a value
        ++duplicates;
      m.day[r.day].hour[r.hour] = r.temperature;
    } else {
      ++invalids;
    }
    if (invalids) throw std::runtime_error("invalid readings in a month");
    if (duplicates) throw std::runtime_error("duplicate readings in a month");
    end_of_loop(is, '}', "bad end of month");
    return is;
  }
}

int main() {
  Reading day1;
  day1.day = 1;
  day1.hour = 3;
  day1.temperature =  98.3;
  std::cout << day1.temperature << std::endl;

  return 0;
}