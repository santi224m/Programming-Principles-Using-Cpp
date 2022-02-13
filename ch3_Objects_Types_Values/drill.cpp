// Santiago Mondragon
// Last modified: Feb 12, 2022
// Summary: This drill is to write a program that produces a simple form letter based on user input.
#include <iostream>
#include <string>

int main(void) {
  std::string firstName;
  std::string friendName;
  char friendGender;
  int age;
  std::string signature;

  std::cout << "Enter the name of the person you want to write to: ";
  std::cin >> firstName;
  std::cout << "Please enter the persons age: ";
  std::cin >> age;
  std::cout << "Please enter the name of a mutual friend: ";
  std::cin >> friendName;
  std::cout << "Is this mutual friend male or female? (Enter 'm' or 'f'): ";
  std::cin >> friendGender;
  std::cout << "Enter your name: ";
  std::cin >> signature;

  std::cout << "\nDear " << firstName << ",\n";
  std::cout << "\tHow have you been? It's been a while since we talked. ";
  std::cout << "Have you seen " << friendName << " lately? ";
  if (friendGender == 'm')
    std::cout << "If you see " << friendName << " can you ask him to call me? ";
  if (friendGender == 'f')
    std::cout << "If you see " << friendName << " can you ask her to call me? ";
  std::cout << "I hear you just had a birthday and you are " << age << " years old. ";

  if (age < 12)
    std::cout << "Next year you will be " << age + 1 << " years old. ";
  if (age == 17) {
    std::cout << "Next year you will be able to vote. ";
  }
  if (age > 70)
    std::cout << "I hope you are enjoying retirement. ";

  std::cout << "\nYours sincerely,\n\n" << signature << std::endl;
  return 0;
}