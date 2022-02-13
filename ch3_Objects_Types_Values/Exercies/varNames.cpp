//Santiago Mondragon
//Last modified: Feb 22, 2022
//Summary: Write a program that doesn’t do anything, but declares a number of
//variables with legal and illegal names (such as int double = 0;), so that you can see how the compiler reacts.
#include <string>

int main(void) {
  double 0plus2 = 2;            //error: expected unqualified-id before numeric constant
  float hello;
  int _my_passwd;
  int bankAccount$;
  double I_Start_With_Capital;
  int isItWorking?;             //error: expected initializer before ‘?’ token
  std::string !notTday;         //error: expected unqualified-id before ‘!’ token

  return 0;
}