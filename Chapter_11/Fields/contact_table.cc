#include <iomanip>
#include <iostream>
#include <vector>

#include "person.h"

int main() {
  const int first_name_width = 10;
  const int last_name_width = 12;
  const int phone_number_width = 12;
  const int email_width = 19;

  Person person1 = Person("Kunal", "Barre", 7082385590, "Kunal@email.com");
  Person person2 = Person("Waldemar", "Kidder", 4065576826, "Waldemar@email.com");
  Person person3 = Person("Alexia", "Covarrubias", 2023564623, "Alexia@email.com");
  Person person4 = Person("Lyndon", "Barrios", 9737803834, "Lyndon@email.com");

  std::vector<Person> contact_list;
  contact_list.push_back(person1);
  contact_list.push_back(person2);
  contact_list.push_back(person3);
  contact_list.push_back(person4);

  std::cout << "====================== Contact List ======================\n";
  std::cout << '|' << std::setw(first_name_width) << "First Name";
  std::cout << '|' << std::setw(last_name_width) << "Last Name";
  std::cout << '|' << std::setw(phone_number_width) << "Phone Number";
  std::cout << '|' << std::setw(email_width) << "Email" << '|' << std::endl; 

  for(Person contact : contact_list) {
    std::cout << '|';
    std::cout << std::setw(first_name_width) << contact.GetFirstName() << '|';
    std::cout << std::setw(last_name_width) << contact.GetLastName() << '|';
    std::cout << std::setw(phone_number_width) << contact.GetPhoneNumber() << '|';
    std::cout << std::setw(email_width) << contact.GetEmail() << '|' << std::endl;
  }

  std::cout << "==========================================================\n";

  return 0;
}