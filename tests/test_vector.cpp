#include <boost/test/unit_test.hpp>
#include "vector.h"
#include "algorithm.h"
BOOST_AUTO_TEST_SUITE(TestVector)
BOOST_AUTO_TEST_CASE(TestVector) {
  nstl::vector<int> vector{};
  vector.push_back(1);
  vector.push_back(2);
  BOOST_REQUIRE_EQUAL(vector.front(), 1);
  BOOST_REQUIRE_EQUAL(vector.back(), 2);
}
BOOST_AUTO_TEST_SUITE_END()