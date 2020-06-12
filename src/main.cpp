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
void perm()
{
  int ass[] = {1, 2, 3};
  
  do {
    cout << ass[0] << ' ' << ass[1] << ' ' << ass[2] << endl;
  } while (next_permutation(ass, ass+3));
}

// [[Rcpp::export]]
void something()
{
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= 3; ++j)
      for (int k = 1; k <= 3; ++k)
        cout << i << ' ' << j << ' ' << k << endl;
}

// [[Rcpp::export]]
auto run()
{
  return homework::discussions::one::section4::q48();
}