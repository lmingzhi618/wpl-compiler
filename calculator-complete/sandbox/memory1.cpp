/**
 * @file memory1.cpp
 * @author gpollice
 * @brief How memory is managed.
 * @version 0.1
 * @date 2022-07-27
 */

#include <iostream>
#include "CppDataStructures.h"

void newExample(std::string eName) {
  std::cout << "\n\n---------------------------\n\nExample: " << eName << std::endl;
}

cppds::ValueBox* makeBox() {
  cppds::ValueBox* vb = new cppds::ValueBox();
  return vb;
}

cppds::ValueBox& makeBoxRef() {
  return *(new cppds::ValueBox());
}

/**
 * @brief Stack (local) works down in memory, heap (global) works up.
 * 
 */
void memoryExample() {
  newExample("Memory address");
  cppds::ValueBox stack;
  cppds::ValueBox* heap = new cppds::ValueBox();
  std::cout << "Local ValueBox address: " << &stack << std::endl;
  std::cout << "Heap ValueBox address: " << heap << std::endl;

  cppds::ValueBox *p = &stack;
  p->setValue(42);
  std::cout << "Local ValueBox new value: " << p->getValue() << std::endl;

  cppds::ValueBox &r = *makeBox(); // This is the only way
  r.setValue(24);
  std::cout << "Heap ValueBox new value: " << r.getValue() << std::endl;

  cppds::ValueBox& r1 = makeBoxRef();
  cppds::ValueBox& r2 = stack;
  std::cout << "Local ValueBox address by ref: " << &r2 << std::endl;
}


int main() {
  memoryExample();

  return 0;
}
