#include <iostream>
#include <string>
#include <string.h>

int main() {
  std::cout << "Insert the text:\n";
  std::string text;
  int max_length[15];
  char long_row[max_length];
  char row[];
  std::cin >> text;
  int tot_len;
  tot_len = strlen(text);
  unsigned int j[];
  
  while(j<tot_len)
  {
  long_row = text.substr(0, max_length);
  j = max_length; // It starts from zero so if the long_row[max_length] is a space it means we already have 15 characters before it.
  
  while(long_row[j]!='')
  {
  j = j - 1;
  }
  
  row = text.substr(0, j - 1);
  text = text.substr(j++,strlen(text));
  std::cout << row << "\n";
  }
  return 0;
}
