#include <iostream>
#include <stdexcept>

extern "C" {
  void throw_cxx_exception() {
    std::cout << "Throwing C++ exception" << std::endl;
    throw std::runtime_error("C++ Runtime error");
  }
}
