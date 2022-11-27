#include <string>

class Person {
  public:
    Person(std::string first_name, std::string last_name, long int phone_number, std::string email)
        : first_name_(first_name),
          last_name_(last_name),
          phone_number_(phone_number),
          email_(email) {}
    std::string GetFirstName() {
      return first_name_;
    }
    void SetFirstName(std::string name) {
      first_name_ = name;
    }
    std::string GetLastName() {
      return last_name_;
    }
    void SetLastName(std::string name) {
      last_name_ = name;
    }
    long int GetPhoneNumber() {
      return phone_number_;
    }
    void SetPhoneNumber(long int number) {
      phone_number_ = number;
    }
    std::string GetEmail() {
      return email_;
    }
    void SetEmail(std::string email) {
      email_ = email;
    }

  private:
    std::string first_name_;
    std::string last_name_;
    long int phone_number_;
    std::string email_;
};