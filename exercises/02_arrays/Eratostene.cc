#include <iostream>
#include <string>
#include <math.h> 

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "I need exactly one argument\n";
        return 7;
    }
  
    const int max = atoi(argv[1]);
    bool arr[max-1] = {true};
    
    for (int i = 2; i<=sqrt(max); ++i) {
        if (arr[i] != false) {
            for (int j = 2; pow(i,j) < max; ++j) {
                arr[static_cast<int>(pow(i,j)-2)] = false;
            }
        }
    }
    
    for (int k = 0; k < max-1; ++k) {
        if (arr[k]!=false) {
        std::cout << k+2 << "\n";
        }
    }
    return 0;
}
