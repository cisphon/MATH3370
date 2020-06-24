#define rcpp false

#if rcpp
#include <Rcpp.h>
#endif

#include "homework.hpp"

#if rcpp
using namespace Rcpp;
#endif

// [[Rcpp::export]]
void run()
{
  hw::web::seven::sec3::a();
  hw::web::seven::sec3::b();
  hw::web::seven::sec3::c();
  hw::web::seven::sec3::d();
}

int main()
{
  run();
}