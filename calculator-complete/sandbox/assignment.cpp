/**
 * @file assignment.cpp
 * @author gpollice
 * @brief How assignment goes.
 * @version 0.1
 * @date 2022-07-27
 */

#include <iostream>
#include "CppDataStructures.h"

void newExample(std::string eName) {
  std::cout << "\n\n---------------------------\n\nExample: " << eName << std::endl;
}

void assignmentExample() {
  newExample("Normal assignment (same object)");
  cppds::ValueBox& h1 = *(new cppds::ValueBox(42));
  cppds::ValueBox& h2 = h1;
  std::cout << "h1 address: " << &h1 << std::endl;
  std::cout << "h2 address: " << &h2 << std::endl;

  newExample("Copy constructor (two objects)");
  cppds::ValueBox& h3 = *(new cppds::ValueBox(24));
  cppds::ValueBox& h4 = *(new cppds::ValueBox(h3));
  std::cout << "h3 address: " << &h3 << std::endl;
  std::cout << "h4 address: " << &h4 << std::endl;
  h4 = h3;  // Default copy constructor
  std::cout << "h3 address: " << &h3 << " value: " << h3.getValue() <<std::endl;
  std::cout << "h4 address: " << &h4 << " value: " << h4.getValue() <<std::endl;

  newExample("Copy assignment, (two objects)");
  h1.setValue(43);
  h4 = h1;
  std::cout << "h1 address: " << &h1 << " value: " << h1.getValue() << std::endl;
  std::cout << "h2 address: " << &h2 << " value: " << h2.getValue() <<std::endl;
  std::cout << "h3 address: " << &h3 << " value: " << h3.getValue() <<std::endl;
  std::cout << "h4 address: " << &h4 << " value: " << h4.getValue() <<std::endl;
}
/**
 * @brief Stack (local) works down in memory, heap (global) works up.
 * 
 */
// void memoryExample() {
//   newExample("Memory address");

//   cppds::ValueBox &r = *makeBox(); // This is the only way
//   r.setValue(24);
//   std::cout << "Heap ValueBox new value: " << r.getValue() << std::endl;

//   cppds::ValueBox& r1 = makeBoxRef();
//   cppds::ValueBox& r2 = stack;
//   std::cout << "Local ValueBox address by ref: " << &r2 << std::endl;
// }


int main() {
  assignmentExample();

  return 0;
}
