#include <iostream>
#include <string>

int main() {
  std::cout << "Insert the measure followed by the unit of measure:\n";
  std::string uni;
  double measure;
  std::cin >> measure >> uni;
  
  if(uni=="in")
  {
  std::cout << " ["<< measure <<"] " << uni << " is equivalent to " << " ["<< measure * 0.0254 <<"] " << "m\n" ;
  }
  
  if(uni=="m")
  {
  std::cout << " ["<< measure <<"] " << uni << " is equivalent to " << " ["<< measure * (1/0.0254) <<"] " << "in\n" ;
  }
  
  return 0;
}
