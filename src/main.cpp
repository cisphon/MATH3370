#include <Rcpp.h>
#include "homework.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
void run()
{
  hw::web::three::sec4::a();
  hw::web::three::sec4::b();
  hw::web::three::sec4::c();
}