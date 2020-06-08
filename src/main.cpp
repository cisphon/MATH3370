#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;


// [[Rcpp::export]] 
vector<int> x()
{
  int len = homework::one::section5::a().size();
 
  vector<int> nums(len);
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    nums[i] = sum;
    sum += 150;
  }
  
  return nums;
}

// [[Rcpp::export]] 
vector<double> y()
{
  vector<double> cum = homework::one::section5::a();
  
  vector<double> rel_freq;
  for (int i = 0; i < cum.size() - 1; ++i)
    rel_freq.push_back(cum[i + 1] - cum[i]);

  rel_freq.push_back(0); // there is no difference for the last one.
  
  return rel_freq;
}

/*
  hot()
  16 17 18 19 (x values)
  1  2  6  1 (y values)
 
  barplot(hot())
 */

// [[Rcpp::export]] 
map<int, double> hot()
{
  vector<int> x_values = x();
  vector<double> y_values = y();
  
  map<int, double> m;
  for (int i = 0; i < x_values.size(); ++i)
    m[x_values[i]] = y_values[i];
  
  return m;
}

// [[Rcpp::export]] 
void test()
{

}