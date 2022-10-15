#include <iostream>
#include <stdexcept>
#include <vector>

#include "token.h"
#include "grammar.h"

int main()
{
  std::vector<Token> tok;    // we'll put tokens here

  std::cout << "Please enter expression (we can handle +, -, *, and /)\n";
  std::cout << "add an x to end expression (e.g. 1+2*3x): ";
  int lval = 0;
  int rval;
  std::cin >> lval;    // read leftmost operand
  if (!std::cin) throw std::runtime_error("no first operand");

  for (char op; std::cin >> op;) {   // read operator and right-hand operator
    if (op != 'x') std::cin >> rval;
    if (!std::cin) throw std::runtime_error("no second operand");
    switch(op) {
      case '+':
        lval += rval;
        break;
      case '-':
        lval -= rval;
        break;
      case '*':
        lval *= rval;
        break;
      case '/':
        lval /= rval;
        break;
      default:    // not another operator, print result
        std::cout << "Result: " << lval << '\n';
        return 0;
    }
  }
  throw std::runtime_error("bad expression");
}