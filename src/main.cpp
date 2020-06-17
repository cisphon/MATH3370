#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  hw::web::three::sec3::a();
  hw::web::three::sec3::b();
  hw::web::three::sec3::c();
}