#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  const double pi_4 = 0.25 * 3.141592653589793;
  double h = 0.0;

  // sanity check of argc
  if(argc>1){
    std::cout << "Only one h value needed" << std::endl;
  }
  else{
    std::cout << "Need to enter one h value" << std::endl;
  }


  // get h from command line
  double h = std::atof(h);

  // compute forward difference
  double yfd = (sin(pi_4+h)-sin(pi_4))/h;
  // compute center difference
  double ycd = (sin(pi_4+h)-sin(pi_4-h))/(2*h);

  // compare the errors
  double e_yfd = cos(pi_4)-yfd;
  double e_ycd = cos(pi_4)-ycd;

  // print results
  std::cout << "Error of using forward difference formula is: " << e_yfd << std::endl;
  std::cout << "Error of using center difference formula is: " << e_ycd << std::endl;

  return 0;
}