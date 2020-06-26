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
  cout << "Section 1~~~~~~~~~~~ " << endl;
  exam::sec1::a();
  exam::sec1::b();
  cout << "Section 2~~~~~~~~~~~" << endl;
  exam::sec2::a();
  exam::sec2::b();

  cout << "Section 4~~~~~~~~~~~" << endl;
  exam::sec4::a();

  cout << "Section 5~~~~~~~~~~~" << endl;
  exam::sec5::a();
  exam::sec5::b();
  exam::sec5::c();
  exam::sec5::d();
  exam::sec5::e();

  cout << "Section 9~~~~~~~~~~~" << endl;
  exam::sec9::a();
  exam::sec9::b();
  exam::sec9::c();

  cout << "Section 10~~~~~~~~~~" << endl;
  exam::sec10::F();
  exam::sec10::a();
  exam::sec10::b();
  exam::sec10::c();
  exam::sec10::d();

}

int main()
{
  run();
}