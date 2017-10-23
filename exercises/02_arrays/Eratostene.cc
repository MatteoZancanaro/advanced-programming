#include <iostream>
#include <string>
#include <math.h> 

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "I need exactly one argument\n";
        return 7;
    }
  
    const int max = atoi(argv[1]);
    bool arr[max-1];
    
    for (int k = 0; k < max-1; ++k) {
        arr[k] = true;
    }
    
    for (int i = 2; i<=sqrt(max); ++i) {
        //std::cout << i << "\n";
        if (arr[i-2] != false) {
            //std::cout << i << "\n";
            for (int j = 0; pow(i,2) + j*i <= max; ++j) {
                arr[static_cast<int>(pow(i,2) + j*i - 2)] = false;
            }
        }
        else {
            continue;
        }
    }
    
    std::cout << "Questi sono i numeri primi: \n";
    
    for (int k = 0; k < max-1; ++k) {
        if (arr[k] == true) {
        std::cout << k+2 << "\n";
        }
    }
    
    return 0;
}
