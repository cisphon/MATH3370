#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
vector<double> run()
{
  //homework::run_homework();
  
  return homework::one::section2::c();
}