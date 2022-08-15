#include "../../std_lib_facilities.h"

// Log error message and terminate program
// void error(string s) {
//   throw runtime_error(s);
// }

int main(void) {
  try {
    double d = 0;
    cin >> d;

    if (!cin) {
      throw runtime_error("Could not load a double in a function");
    }

    return 0;        // 0 indicates success
  } catch (runtime_error& e) {
    cerr << "runtime error: " << e.what() << '\n';        // e.what() extracts error message from runtime_error
    keep_window_open();                                       //cerr is like cout but for errors
    return 1;       // 1 indicates failure
  }
}