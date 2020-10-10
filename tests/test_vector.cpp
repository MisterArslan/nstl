#include "vector.h"
#include "algorithm.h"
#include <cassert>

int main() {
  nstl::vector<int> vector(1);
  vector.push_back(1);
  vector.push_back(2);
  assert(vector.front() == 1);
  assert(vector.back() == 2);

  return 0;
}
