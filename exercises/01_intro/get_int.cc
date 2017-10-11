#include <iostream>
#include <string>
#include <math.h> 

int main() {
  std::cout << "Insert an integer\n";
  double integer;
  std::cin >> integer;
  
  while(floor(integer)!=integer)
  {
  std::cout << "Error: the number is not an integer\n";
  std::cout << "Please, insert an integer\n";
  std::cin.clear();
  std::cin.ignore();
  std::cin >> integer;
  }
  
  std::cout << "Fine," << " [" << integer << "] is a good choice\n";
  
  return 0;
}
