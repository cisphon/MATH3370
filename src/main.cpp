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
<<<<<<< HEAD
  hw::web::eight::sec1::a();
  hw::web::eight::sec1::b();
=======
  hw::web::eight::sec2::a();
  hw::web::eight::sec2::b();
  hw::web::eight::sec2::c();
  hw::web::eight::sec2::d();
  hw::web::eight::sec2::e();
>>>>>>> f739e83844d77987b731adc58013a23e86612bc0
}

// [[Rcpp::export]]
int main()
{
  run();
}