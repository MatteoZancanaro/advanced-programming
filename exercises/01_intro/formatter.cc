#include <iostream>
#include <string>
#include <string.h>
#include <algorithm> 

int main() {
  std::cout << "Insert the text:\n";
  std::string text;
  int max_length = 15;
  char long_row[max_length];
  getline(std::cin,text);
  int tot_len;
  tot_len = text.length();
  unsigned int j = 0;
  
  while(j<tot_len)
  {
  j = max_length; // It starts from zero so if the long_row[max_length] is a space it means we already have 15 characters before it.
  
  while(text.substr(0, max_length+1).at(j)!=' ') // It takes max_length+1 characters.
  {
  j = j - 1;
  }
  
  std::cout << text.substr(0, j ) << "\n";
  text = text.substr(j + 1,text.length());
  tot_len = text.length();
  }
  
  std::cout << text << "\n";
  
  return 0;
}
