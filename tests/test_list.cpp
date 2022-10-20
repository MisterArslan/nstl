#include "list.hpp"
#include "algorithm.hpp"
#include <cassert>

int main() {
  nstl::list<int> list{};
  list.push_back(1);
  list.push_back(2);
  assert(list.front() == 1);
  assert(list.back() == 2);

  auto iter = list.begin();

  assert(*iter == 1);
  ++iter;
  assert(*iter == 2);

  return 0;
}
