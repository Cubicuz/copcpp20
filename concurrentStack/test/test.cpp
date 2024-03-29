#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../blockingStack.h"

TEST_CASE("basic compile test") { REQUIRE(1 == 1); }

TEST_CASE("memory correctness")
{
  BlockingStack<int> bs;

  const size_t entries = 10000;

  bs.pop();
  bs.pop();
  volatile auto a = bs.size();
  for (size_t i = 0; i < entries; i++)
  {
    bs.push(i);
  }
  a = bs.size();
  for (int i = entries - 1; i >= 0; i--)
  {
    REQUIRE(bs.pop() == i);
  }
  a = bs.size();
  bs.pop();
  bs.pop();
}

TEST_CASE("blocking performance")
{

  BlockingStack<int> bs;

  const size_t entries = 10000;

  BENCHMARK_ADVANCED("blocking stack")
  (Catch::Benchmark::Chronometer meter)
  {

    while (!bs.empty())
    {
      bs.pop();
    }

    meter.measure([&bs]
                  {
      for (size_t i = 0; i < entries; i++) {
        bs.push(i);
      } });
  };

  std::cout << "size " << bs.size();

  for (int i = entries - 1; i >= 0; i--)
  {
    REQUIRE(bs.pop() == i);
  }
}
