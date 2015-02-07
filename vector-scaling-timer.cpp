#include <iostream>
#include <ctime>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <cblas.h>

void initialize(int n, double * x) {
  // initialize array
  for (int k = 0; k < n; k++)
    x[k] = 1.0;
}

int main() {

  const int n = 1000000;
  double x[n];
  const double alpha = 3.1415;
  double elapsed_secs;
  std::clock_t begin, end;

  // regular
  initialize(n, x);
  begin = clock();
  for (int k = 0; k < n; k++)
    x[k] *= alpha;
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "Regular scaling: " << elapsed_secs << " s" << std::endl;

  // cblas
  initialize(n, x);
  begin = clock();
  cblas_dscal(n, alpha, x, 1);
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "cblas scaling: " << elapsed_secs << " s" << std::endl;

  // ublas
  boost::numeric::ublas::vector<double> v(n);
  for (unsigned i = 0; i < v.size(); ++ i)
    v(i) = 1.0;
  begin = clock();
  v *= alpha;
  end = clock();
  elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
  std::cout << "uBLAS scaling: " << elapsed_secs << " s" << std::endl;

  return 0;
}
