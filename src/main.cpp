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
  hw::web::eight::sec2::a();
  hw::web::eight::sec2::b();
  hw::web::eight::sec2::c();
  hw::web::eight::sec2::d();
  hw::web::eight::sec2::e();
}

int main()
{
  run();
}