// Santiago Mondragon
// Last modified: Feb 20, 2022
// Summary: Compute mean and median temperatures
// Lesson: Shows how to use vectors
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
  std::vector<double> temps;          //temperatures
  for (double temp;std::cin>>temp;)        //read into temp
    temps.push_back(temp);            //put temp into temps vector

  //compute mean temperature:
  double sum = 0;
  for (double x : temps) sum += x;    //for every doube x in the temps vecotr, add x to sum
  std::cout << "Mean temperature: " << sum/temps.size() << "\n";

  //compute median temperature:
  std::sort(temps.begin(), temps.end());                   //sort temperatures
  if (temps.size() % 2 == 1)
    std::cout << "Median temperature: " << temps[temps.size()/2] << "\n";
  else
    std::cout << "Median temperature: " << (temps[(temps.size() - 1)/2] + temps[(temps.size() + 1)/2])/2 << "\n";

  return 0;
}