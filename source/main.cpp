#include "../includes/Driver/PrototypeWrapper.h"

// TODO: Prototype
int prototype() {
  PrototypeWrapper driver("Prototype Program Title");
  driver.run();
  return 0;
}

//* @def: Main program
int main() { return prototype(); }