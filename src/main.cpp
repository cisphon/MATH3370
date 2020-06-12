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
  char ass[] = {'C', 'D', 'P'};
  
  do {
    cout << ass[0] << ' ' << ass[1] << ' ' << ass[2] << endl;
  } while (next_permutation(ass, ass+3));
}

// [[Rcpp::export]]
void run()
{
  vector<int> nums = {3124,3142,4123,4132,2314,2341,
                      3214,3241,2413,2431,4213,4231};
  sort(nums.begin(), nums.end());
  tools::print_vector(nums);
  //homework::discussions::one::section4::q48();
}