/* EXPRESSION GRAMMAR */
/*
Expression:
  Term
  Expression "+" Term    // addition
  Expression "-" Term    // subtraction
Term:
  Primary
  Term "*" Primary    // multiplication
  Term "/" Primary    // division
  Term "%" Primary    // remainder (modulo)
Primary:
  Number
  "(" Expression ")"    // grouping
Number
  floating-point-literal
*/

// Grammar rules functions
double expression();    // deal with + and -
double term();    // deal with *, /, and %
double primary();    // deal with numbers and paranthesis