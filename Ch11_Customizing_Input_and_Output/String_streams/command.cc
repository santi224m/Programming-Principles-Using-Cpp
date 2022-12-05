#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::string command;
  std::getline(std::cin, command);

  std::stringstream ss {command};  // create a stream with the value of the command string
  std::vector<std::string> words;
  for(std::string s;ss >> s;) {  // extract each word from the stream
    words.push_back(s);
  }

  std::cout << words.size() << " commands entered\n";

  return 0;
}