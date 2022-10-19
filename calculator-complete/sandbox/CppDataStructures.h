/**
 * @file CppDataStructures.h
 * @author your name (you@domain.com)
 * @brief For use in creating examples for memory management and C++ objects
 *  There may be many classes in this file.
 * @version 0.1
 * @date 2022-07-27
 */
#pragma once
namespace cppds
{
  class ValueBox
  {
  private:
    int value;

  public:
    ValueBox(/* args */){
      std::cout << "Default constructor" << std::endl;
    };

    ValueBox(int v) {
      std::cout << "Constructor with value" << std::endl;
      value = v;
    }

    ValueBox(const ValueBox& vb) {
      std::cout<< "Copy constructor" << std::endl;
      value = vb.value;
    }
    
    ~ValueBox(){
      std::cout << "Destructor" << std::endl;
    };

    // Assignment operator this just print out, but is the
    // same as the copy assignment operator
    ValueBox& operator=(const ValueBox& vb) {
      std::cout << "Assignment =" << std::endl;
      value = vb.value;
      return *this;
    };

    void setValue(int v) { value = v; }
    int getValue() { return value; }
  };
}