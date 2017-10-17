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
    prime_printer<double>(primes);
}

template <typename elements>
elements* prime_calc(const int n){
    elements* arr {new elements[n]};
    for (int i = 0; i < n; ++i) {
      std::cin >> vector[i] ;
    }
    return arr;
}
template <typename elements>
void print_reverse(elements* element, const int n){
    for (int i = n-1; i>= 0; --i) {
    
    std::cout << element[i] << std::endl;
    
    }
}
