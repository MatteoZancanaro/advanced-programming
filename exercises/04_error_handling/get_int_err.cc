#include <iostream>
#include <string>
#include <math.h> 

struct Negative_number {};

struct Not_integer {};

int main() {
    try{
        std::cout << "Insert an integer\n";
        double integer;
        std::cin >> integer;
        
        if (integer < 0){
            throw Negative_number{}; // It throws an exception.
            }
        if (floor(integer) != integer){
            throw Not_integer{};
            }
        else{
        std::cout << "Fine," << " [" << integer << "] is a good choice\n";
        }

        return 0;
        }
        
        catch (Negative_number) {
            std::cerr << "This is a negative number. Please, insert an integer number.\n";
            return 1;}
        catch (Not_integer) {
            std::cerr << "This is a not an integer. Please, insert an integer number.\n";
            return 2;}
        catch (...) {
            std::cerr << "Unknown exception. Aborting.\n";
            return 3;}
}































