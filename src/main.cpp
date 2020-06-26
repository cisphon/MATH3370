#define using_rcpp false

#if using_rcpp
#include <Rcpp.h>
#endif

#include "homework.hpp"

#if using_rcpp
using namespace Rcpp;
#endif

// [[Rcpp::export]]
void run()
{
  hw::web::seven::sec3::run();
}

int main()
{
  run();
}