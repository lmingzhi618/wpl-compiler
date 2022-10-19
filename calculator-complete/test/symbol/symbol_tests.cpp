/**
 * @file symbol_tests.cpp
 * @author gpollice
 * @brief Tests for the Symbol structure
 * @version 0.1
 * @date 2022-07-17
 */
#include <catch2/catch_test_macros.hpp>
#include "Symbol.h"

TEST_CASE("Create a Symbol", "[symbol]") {
  Symbol s("a", SymType::BOOL);
  CHECK(s.identifier == "a");
  CHECK(s.type == BOOL);
  // CHECK("foo" == s.toString());
  CHECK("[a, BOOL]" == s.toString());
}