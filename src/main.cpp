#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  
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