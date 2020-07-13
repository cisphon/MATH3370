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
  hw::web::eight::sec1::a();
  hw::web::eight::sec1::b();
}

// [[Rcpp::export]]
int main()
{
  run();
}