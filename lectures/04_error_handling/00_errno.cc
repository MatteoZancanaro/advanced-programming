#include <cmath>
#include <iostream>

int main() {
  double d = sqrt(-9);
  std::cout << d << std::endl;
  std::cout << errno << " " << d << std::endl; //errno is a variable that c changes when something wrong happens.
  return 0;
}
