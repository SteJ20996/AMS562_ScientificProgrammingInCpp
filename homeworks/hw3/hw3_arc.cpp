#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);
static std::string floatToString(float x, float y, float z);

int main(int argc, char *argv[]) {
  // parse input argc/argv
  if(argc!=2){
    std::cout << "Need only one argument" << std::endl;
    return -1;
  }

  int N = 0;
  // get the size of N

  double ub = 0; // upper bound, need to as small as possible
  double lb = std::numeric_limits<double>::infinity(); // lower bound, need to as large as possible
  N = std::atof(argv[1]); // get N
  if(N <= 1){
    std::cout << "N need to be at least 2, to consider the max and min" << std::endl;
    return -1;
  }

  float *x = nullptr, *y = nullptr, *z = nullptr;

  // allocate memory for x, y, z
  x = new float [N];
  y = new float [N];
  z = new float [N];

  std::string ma, mi; // to storage points corresponding to max and min length

  // determine the extreme arc lengths
  for(int i = 0; i < N; i++){ // exact N iterations
    genPointsOnUnitSphere(N, x, y, z);
    if(i >= 1){
        double arc = acos(x[i] * x[0] + y[i] * y[0] + z[i] * z[0]);
        if(ub < arc){
          ma = floatToString(x[i], y[i], z[i]);
          ub = arc;
        }
        if(lb > arc){
          mi = floatToString(x[i], y[i], z[i]);
          lb = arc;
        }
    }
  }

  std::cout << "When iteration count is: " << N << std::endl;
  std::cout << "The first point is: " << floatToString(x[0], y[0], z[0]) << std::endl;
  std::cout << "The max-arc point is: " << ma << std::endl;
  std::cout << "The min-arc point is: " << mi << std::endl;
  std::cout << "Max arc is: " << ub << std::endl;
  std::cout << "Min arc is: " << lb << std::endl;

  // relax memory
  delete [] x;
  delete [] y;
  delete [] z;

  return 0;
}

// a flost-to-string function to convert 3-D coordinate to string
std::string floatToString(float x, float y, float z) {
  std::stringstream stream;
  stream << "(";
  stream << std::fixed << std::setprecision(6) << x;
  stream << ", ";
  stream << std::fixed << std::setprecision(6) << y;
  stream << ", ";
  stream << std::fixed << std::setprecision(6) << z;
  stream << ")";
  std::string s = stream.str();
  return s;
}

// black-box function to generate a collection of random points
void genPointsOnUnitSphere(const int N, float *x, float *y, float *z) {
  if (x == nullptr || y == nullptr || z == nullptr || N <= 0) {
    std::cerr << "invalid pointers or size, aborting...\n";
    std::exit(1);
  }
  std::srand(std::time(0));  // trigger the seed
  const int BD = 10000000, BD2 = 2 * BD;
  const float inv_bd = 1.0f / BD;  // not integer division
  for (int i = 0; i < N; ++i) {
    x[i] = (std::rand() % BD2 - BD) * inv_bd;
    y[i] = (std::rand() % BD2 - BD) * inv_bd;
    z[i] = (std::rand() % BD2 - BD) * inv_bd;
    const float len = std::sqrt(x[i] * x[i] + y[i] * y[i] + z[i] * z[i]);
    if (len > 1e-5f) {
      // project on to unit sphere
      x[i] /= len;
      y[i] /= len;
      z[i] /= len;
    } else {
      // too close to zero
      // directly set the point to be (1,0,0)
      x[i] = 1.0f;
      y[i] = z[i] = 0.0f;
    }
  }
}