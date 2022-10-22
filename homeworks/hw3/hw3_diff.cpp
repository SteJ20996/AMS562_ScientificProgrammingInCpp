#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  const double pi_4 = 0.25 * 3.141592653589793;
  double h = 0.0;

  // sanity check of argc
  if(argc!=2){
    std::cout << "Need only one h value" << std::endl;
    return -1;
  }


  // get h from command line and sanity check of argv
  char* string_h = argv[1]; // get the input h
  if (!(h=std::atof(string_h))){  // If the return value is 0, it means that h is invalid
    std::cout << "Invalid input h" << std::endl;
    return -1;
  }
  std::cout << "h value is: " << h << std::endl; // print the input number out


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
