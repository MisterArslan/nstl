#include "internal/list.h"
#include <iostream>
#include "algorithm.h"
#include "list.h"
int main() {
  nstl::list<int> list{};
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  for (auto &i: list) {
    std::cout << i << std::endl;
  }

  std::cout << std::endl;

  nstl::internal::reverse(list.begin(), list.end());
  nstl::internal::bubble_sort(list.begin(), list.end());

  for (auto &i: list) {
    std::cout << i << std::endl;
  }
}