#include "binder/binder.h"
#include <iostream>

int fake();

int main(int argc, char *argv[]) {
  std::cout << "hello world" << std::endl;
  hello();
  return id(42) + fake();
}
