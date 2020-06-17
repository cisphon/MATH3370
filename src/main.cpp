#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  hw::web::three::sec1::a();
  hw::web::three::sec1::b();
  hw::web::three::sec1::c();
  hw::web::three::sec1::d();
  hw::web::three::sec1::e();
}