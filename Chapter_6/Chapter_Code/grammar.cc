#include "grammar.h"
#include "token.h"

double expression()
{
  double left = term();   // read and evaluate a term
  Token t = get_token();    // get the next token
  switch (t.kind) {   // see which kind of token it is
    case '+':
      return left + expression();    // read and evaluate an expression, then add
    case '-':
      return left - expression();    // read and evaluate an expression, then subtract
    default:
      return left;    // return value of the term
  }
}