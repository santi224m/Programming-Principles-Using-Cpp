// Santiago Mondragon
// Last modified: Feb 20, 2022
// Summary: Prompts user to enter words and then sorts the words and outputs them
// Lesson: Shows how to use vectors with strings
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(void) {
  std::vector<std::string> words;
  for (std::string word;std::cin>>word;)     //read whitespace-seperated words
    words.push_back(word);               //push into words vector

  std::cout << "Number of words: " << words.size() << '\n';  
  std::sort(words.begin(), words.end());                      //sort the words

  for (int i = 0; i < words.size(); ++i) {
    if (i == 0 || words[i - 1] != words[i])            //new word
      std::cout << words[i] << '\n';
  }

  return 0;
}