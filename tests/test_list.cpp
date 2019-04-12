#include <boost/test/unit_test.hpp>
#include "list.h"
#include "algorithm.h"
BOOST_AUTO_TEST_SUITE(TestList)
BOOST_AUTO_TEST_CASE(TestList) {
  nstl::list<int> list{};
  list.push_back(1);
  list.push_back(2);
  BOOST_REQUIRE_EQUAL(list.front(), 1);
  BOOST_REQUIRE_EQUAL(list.back(), 2);

  auto iter = list.begin();

  BOOST_REQUIRE_EQUAL(*iter, 1);
  ++iter;
  BOOST_REQUIRE_EQUAL(*iter, 2);
}
BOOST_AUTO_TEST_SUITE_END()


