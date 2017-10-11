#include <iostream>
#include <string>

int main() {
  std::cout << "Insert a string\n";
  std::string lines;
  //std::cin >> lines;
  std::string old_line;
  std::string line;
  
  while(std::getline(std::cin,line))
  {
  if(line!=old_line)
  {
  std::cout << line;
  old_line = line;
  }
  }
  
  return 0;
}
