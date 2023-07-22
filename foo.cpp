#include <iostream>
#include <stdexcept>

extern "C" {
  void throw_cxx_exception() {
    std::cout << "Throwing C++ exception" << std::endl;
    throw std::runtime_error("C++ Runtime error");
  }

  void rust_middle_func(void (*callback)());

  void test_cxx_exception() {
    try {
      rust_middle_func(throw_cxx_exception);
      std::cout << "End of C++ try block" << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Catched: " << e.what() << std::endl;
      return;
    }
  }
}
