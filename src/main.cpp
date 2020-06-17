#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  hw::web::three::sec2::a();
  hw::web::three::sec2::b();
  hw::web::three::sec2::c();
  hw::web::three::sec2::d();
  hw::web::three::sec2::e();
}