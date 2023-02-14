#include <fstream>
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

std::vector<std::string> month_input_tbl = {
  "jan", "feb", "mar", "apr", "may", "jun", "jul",
  "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(std::string s) {
  for (int i = 0; i < 12; ++i) {
    if (month_input_tbl.at(i) == s) return i;
  }
  return -1;
}

std::vector<std::string> month_print_tbl = {
  "January", "Febuary", "March", "April", "May", "June", "July",
  "August", "September", "October", "November", "December"
}

std::string int_to_month(int i) {
  if (i < 0 || i > 12) throw std::runtime_error("bad month index");
  return month_print_tbl.at(i);
}

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
    std::cout << "returning to stream: " << ch << std::endl;
    int ansi = ch;
    std::cout << "ansi: " << ansi << std::endl;
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }

  std::string month_marker;
  std::string mm;
  is >> month_marker >> mm;
  std::cout << mm << std::endl;
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
    std::cout << "read a reading\n";
  }
  end_of_loop(is, '}', "bad end of month");
  return is;
}

std::istream& operator>>(std::istream& is, Year& y) {
  // read a year from is into y
  // format: { year 1972 ... }
  char ch;
  is >> ch;
  if (ch != '{') {
    is.unget();
    is.clear(std::ios_base::failbit);
    return is;
  }

  std::string year_marker;
  int yy;
  is >> year_marker >> yy;
  std::cout << "year: " << yy << std::endl;
  if (!is || year_marker != "year") throw std::runtime_error("bad start of year");
  y.year = yy;

  while (true) {
    Month m;  // get a clean m each time around
    std::cout << "created new month object m...\n";
    if (!(is >> m)) {
      std::cout << "breaking...\n";
      break;
    }
    y.month[m.month] = m;
    std::cout << "set value to m: " << m.month << std::endl;
  }
  end_of_loop(is, '}', "bad end of year");
  return is;
}

int main() {
  // Open input file
  std::cout << "Please enter input file name\n";
  std::string iname;
  std::cin >> iname;
  std::fstream ifs {iname};
  if (!ifs) throw std::runtime_error("Can't open input file");
  ifs.exceptions(ifs.exceptions()|std::ios_base::badbit); // throw for bad()

  // Open output file
  std::cout << "Please enter output file name\n";
  std::string oname;
  std::cin >> oname;
  std::ofstream ofs {oname};
  if (!ofs) throw std::runtime_error("Can't open output file");

  // read an arbitrary number of years
  std::vector<Year> ys;
  while (true) {
    Year y; // get a freshly initialized Year each time around
    if (!(ifs >> y)) break;
    ys.push_back(y);
  }
  std::cout << "read " << ys.size() << " years of reading\n";

  // for(Year& y : ys) {
  //   // print_year(ofs, y);  // function not yet written
  // }


  return 0;
}