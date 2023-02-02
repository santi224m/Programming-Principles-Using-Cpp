class Token {
  public:
    char kind;
    double value;
};

Token get_token();    // read characters and compose tokens