#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  const double pi_4 = 0.25 * 3.141592653589793;
  double h = 0.0;

  // sanity check of argc
  if(argc>1){
    std::cout << "Only one h value needed" << std::endl;
    return -1;
  }
  else{
    std::cout << "Need to enter one h value" << std::endl;
  }


  // get h from command line
  const double f = std::atof()

  // compute forward difference
  double yfd = (sin(pi_4+h)-sin(pi_4))/h;
  // compute center difference
  double ycd = (sin(pi_4+h)-sin(pi_4-h))/(2h);

  // compare the errors
  double e_ydf = cos(pi_4)-ydf;
  double e_ycf = cos(pi_4)-ycf;

  // print results
  std::cout << "Error of using forward difference formula is: " << e_ydf << std::endl;
  std::cout << "Error of using center difference formula is: " << e_ycf << std::endl;

  return 0;
}
