if(EXISTS "/home/lmz/cs544/calculator-starter/build/test/tests_tests-b12d07c.cmake")
  include("/home/lmz/cs544/calculator-starter/build/test/tests_tests-b12d07c.cmake")
else()
  add_test(tests_NOT_BUILT-b12d07c tests_NOT_BUILT-b12d07c)
endif()
