class vector {
 public:
  vector(int s); // constructor: allocate s doubles
                 // let s point to those doubles
                 // store s in sz
  int size() const { return sz; } // return the current size

 private:
  int sz; // the size
  double* elem; // pointer to the first element
  };