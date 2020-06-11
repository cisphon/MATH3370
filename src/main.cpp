#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
auto test()
{
  vector<double> nums;
  tools::put_nums_in_vector(nums, "blood2.txt");

  replace(nums.begin(), nums.end(), 127.4, 127.6);
  
  vector<int> fives(nums.size());
  for (int i = 0; i < nums.size(); ++i)
    fives[i] = tools::round_nearest_x(nums[i], 5);
  
  sort(fives.begin(), fives.end());
  
  return fives;
}

// [[Rcpp::export]]
void run()
{
  homework::webassign::run();
}