#include "../../std_lib_facilities.h"

int main()
try {
  vector<int> v;    // a vector of ints
  for (int x; cin>>x;)
    v.push_back(x);   // set values
  for (int i = 0; i<=v.size(); ++i)   //print values (intentionally wrote i<=v.size() to create error)
    cout << "v[" << i << "] == " << v[i] << '\n';
} catch (out_of_range) {
  cerr << "Oops! Range error\n";
  return 1;
} catch (...) {
  cerr << "Exception: something went wrong\n";
  return 2;
}