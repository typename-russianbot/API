#include "../../includes/Master/PrototypeWrapper.h"

// TODO: Prototype
int prototype() {
  PrototypeWrapper driver("|  Checkers  |");
  driver.run();
  return 0;
}

//* @def: Main program
int main() { return prototype(); }