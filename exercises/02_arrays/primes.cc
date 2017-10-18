#include <iostream>
#include <typeinfo>


template <typename elements>
elements* prime_calc(const int last);
template <typename elements>
void prime_printer (elements* primevec);

int main() {
int last;
std::cout << "Insert the last number you want to check \n";
std::cin >> last;
    int* primes {prime_calc<int>(last)};
    prime_printer<int>(primes);
}

template <typename elements>
elements* prime_calc(const int n){
    elements* arr {new elements[1]};
    arr[0] = 2;
    std::cout << "2 is prime \n";
    int k = 1;
    for (int i = 3; i < n; ++i) {
        int check ;
        int jj;
        for (int j = 0; j < k; ++j) {
            check = i%arr[j];
        
            if (check != 0 && j != k-1) {
                continue;
            }
            else if (check != 0 && j == k-1) {
                //arr.push_back(i); // how can I add in a different way??
                k++;
                elements* newarr {new elements[k]};
                for (int h = 0; h < k-1; ++h) {
                newarr[h] = arr[h];
                }
                std::cout << i << " is prime \n";
                newarr[k-1] = i;
                delete[] arr;
                arr = newarr;
            }
            else {
                break;
            }
        }    
    }
    return arr;
}

template <typename elements>
void prime_printer(elements* prarr){ // how can I print an array avoiding the for cycle??
    std::cout << prarr << std::endl;
}














