// main.cpp
#include "A.hpp"
#include "B.hpp"

int main() {
  B b; /** ANDA HARUS MENGGUNAKAN DEFAULT CONSTRUCTOR */
  A* a;
  a = &b;
  a->setValue(888);
  b.setValue(10888);

  // Your code goes here :)
  // ...
  // ...
  
  b.print(); // OUTPUT: (888, 10888)
  return 0;
}