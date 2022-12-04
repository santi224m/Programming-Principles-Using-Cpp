#include <chrono>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

int main() {
  std::ofstream ofs {"log.txt", std::ios_base::app};
  if (!ofs) throw std::runtime_error("Unable to open log.txt");

  std::string log_text;
  std::cout << "Enter text you would like to add to log: ";
  std::getline(std::cin, log_text);

  ofs << log_text << '\n';

  std::cout << "Added to log...\n";
  return 0;
}