/**
 * @file scope_tests.cpp
 * @author gpollice
 * @brief Scope unit tests
 * @version 0.1
 * @date 2022-07-17
 */
#include <catch2/catch_test_macros.hpp>
#include "Scope.h"
#include <iostream>

TEST_CASE("Check symbol return from add", "[symbol]") {
  Scope* scope = new Scope();
  Symbol* s = scope->addSymbol("a", SymType::BOOL);
  CHECK(s->identifier == "a");
  Symbol* s2 = scope->addSymbol("b", SymType::INT);
  // Check same values
  CHECK("b" == s2->identifier);
  CHECK(SymType::INT == s2->type);
  // Uncomment the next in order to see what a scope string looks like.
  // CHECK(scope->toString() == "foo");
}

TEST_CASE("Find existing element", "[symbol") {
  Scope* scope = new Scope();
  Symbol* s = scope->addSymbol("a", SymType::BOOL);
  Symbol& s1 = *(scope->findSymbol("a"));
  CHECK(&s1 == s);
}

TEST_CASE("Look for non-existent element", "[symbol]") {
  Scope* scope = new Scope();
  Symbol* s = scope->addSymbol("a", SymType::BOOL);
  CHECK(s != nullptr);
  Symbol* s1 = scope->findSymbol("b");
  CHECK(s1 == nullptr);
}

TEST_CASE("Duplicate symbol", "[symbol]") {
  Scope* scope = new Scope();
  Symbol* s = scope->addSymbol("a", SymType::BOOL);
  CHECK(s != nullptr);
  Symbol* s2 = scope->addSymbol("a", SymType::INT);

  CHECK(s2 == nullptr);
}