/**
 * @file st_manager_tests.cpp
 * @author gpollice
 * @brief Tests for the STManager
 * @version 0.1
 * @date 2022-07-18
 */
#include <catch2/catch_test_macros.hpp>
#include "STManager.h"

TEST_CASE("add a scope", "[symbol]") {
  STManager mgr;
  CHECK(mgr.scopeCount() == 0);
  Scope& s = mgr.enterScope();
  CHECK(mgr.scopeCount() == 1);
  Scope& s1 = mgr.getCurrentScope();
  CHECK(&s == &s1);
  CHECK(0 == s1.getId());
}

TEST_CASE("multiple scopes", "[symbol]") {
  STManager mgr;
  Scope &s1 = mgr.enterScope();
  CHECK(0 == s1.getId());
  Scope &s2 = mgr.enterScope();
  CHECK(1 == s2.getId());
  CHECK(0 == s2.getParent()->getId());
  Scope &s3 = mgr.enterScope();
  CHECK(1 == s3.getParent()->getId());
  Scope &temp = mgr.exitScope();
  CHECK(s3.getId() == temp.getId());
  Scope &s4 = mgr.enterScope();
  CHECK(1 == s4.getParent()->getId());
  CHECK(3 == s4.getId());
}

TEST_CASE("multiple scopes with symbols", "[symbol]") {
  STManager mgr;
  Scope &s1 = mgr.enterScope();
  CHECK(0 == s1.getId());
  mgr.addSymbol("a", BOOL);
  mgr.addSymbol("b", INT);
  CHECK(mgr.findSymbol("a")->type == BOOL);
  CHECK(mgr.findSymbol("x") == nullptr);
  Scope &s2 = mgr.enterScope();
  mgr.addSymbol("a", INT);
  mgr.addSymbol("c", INT);
  CHECK(mgr.findSymbol("a")->type == INT);
  Scope &s3 = mgr.enterScope();
  CHECK(2 == s3.getId());
  mgr.addSymbol("c", BOOL);
  mgr.addSymbol("d", INT);
  CHECK(mgr.findSymbol("b")->type == INT);
  CHECK(mgr.findSymbol("c")->type == BOOL);
  mgr.exitScope();
  Scope &s4 = mgr.enterScope();
  CHECK(s4.getParent() == &s2);
  mgr.addSymbol("a", INT);
  mgr.addSymbol("avar", BOOL);
  CHECK(mgr.findSymbol("c")->type == INT);
  CHECK(mgr.findSymbol("d") == nullptr);
  // Uncomment the following to see the symbol table string
  // CHECK(mgr.toString() == "foo");
}