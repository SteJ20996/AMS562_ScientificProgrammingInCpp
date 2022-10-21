#include <cmath>
#include <cstdlib>
#include <ctime>  // for trigger the seed of random number generator
#include <iostream>

static void genPointsOnUnitSphere(const int N, float *x, float *y, float *z);

int main(int argc, char *argv[]) {
  // parse input argc/argv
  if(argc>2){
    std::cout << "Only one h value needed" << std::endl;
    return -1;
  }
  else if(argc<2){
    std::cout << "Need to enter one h value" << std::endl;
    return -1;
  }

  int N = 0;
  // get the size of N

  float *x = nullptr, *y = nullptr, *z = nullptr;

  // allocate memory for x, y, z
  x = new float [N]
  y = new float [N]
  z = new float [N]

  genPointsOnUnitSphere(N, x, y, z);

  // determine the extreme arc lengths


  // relax memory
  free(x);
  free(y);
  free(z);

  return 0;
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