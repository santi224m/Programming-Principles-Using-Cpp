#include <ios>
#include <iostream>
#include <istream>
#include <ostream>

enum Month {
  jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
 public: 
  Date(int y, Month m, int d) : y_(y), m_(m), d_(d) {}
  Date() {};
  int Year() const  { return y_; }
  enum Month Month() const { return m_; }
  int Day() const { return d_; }

 private:
  int y_;
  enum Month m_;
  int d_;
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << '(' << d.Year() << ',' << d.Month() << ',' << d.Day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
  int y, m, d;
  char ch1, ch2, ch3, ch4;
  is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
  if (!is) return is;
  if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {  // format error
    is.clear(std::ios_base::failbit);
    return is;
  }
  dd = Date(y, Month(m), d);  // update date object
  return is;
}

int main() {
  Date today = Date(2022, Month::nov, 1);
  Date birthdate = Date(2000, Month::sep, 13);
  std::cout << today << birthdate << std::endl;

  Date new_date;
  std::cout << "Enter a date: ";
  std::cin >> new_date;
  std::cout << "The date you entered is: " << new_date << std::endl;
  std::cout << "The month is: " << new_date.Month() << std::endl;
  

  return 0;
}