#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  deque<double> nums;
  tools::put_nums_in_deque(nums, "urban.txt");
  cout << (100.0 / nums.size()) << endl;
  
  nums.clear();
  tools::put_nums_in_deque(nums, "farm2.txt");
  cout << (100.0 / nums.size()) << endl;
}

// [[Rcpp::export]] 
vector<double> charity()
{
  vector<double> nums;
  tools::put_nums_in_vector(nums, "charity.txt");
  return nums;
}

// [[Rcpp::export]] 
void test()
{

}