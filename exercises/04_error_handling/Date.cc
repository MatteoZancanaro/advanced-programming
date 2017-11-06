#include <iostream>
#include <string>

struct Month_exceeding{};
struct Day_exceeding{};

enum class m { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

bool leap(unsigned int yy);

class Date {
    unsigned int _day;
    unsigned int _month;
    unsigned int _year;

    public:
        Date(unsigned int Day, unsigned int Month, unsigned int Year) : _day{Day}, _month{Month}, _year{Year} {
        
        if (Month>11) {
        throw Month_exceeding{};
        }
        else if (Month==0 || Month==2 || Month==4 || Month==6 || Month==7 || Month==9 || Month==11 && Day>31) {
        throw Day_exceeding{};
        }
        else if (Month==3 || Month==5 || Month==8 || Month==10 && Day>30) {
        throw Day_exceeding{};
        }
        else {
            bool leap_check = leap(Year);
            if (leap_check==true && Day>29) {
                throw Day_exceeding{};
            }
            else if (leap_check==false && Day>28){
                throw Day_exceeding{};
            }
        }
        
        } //I'm calling the constructor this way: Date(what has to be given to the constructor) : variables_to_be_used{dimension} {}

        ~Date() {} // In this case it does not make anything: no arrays to be delated.

        unsigned int day() { return _day; }
        unsigned int month() { return _month; }
        unsigned int year() { return _year; }

        void add_days(unsigned int n);

};

int main() {
    try{
        unsigned int DD = 30;
        m opt = m:: mar;
        int MM = int(opt);
        unsigned int YY = 1992;
        
        Date date(DD, MM, YY);

        std:: cout << date.day() << "\n";
        std:: cout << date.month() +1 << "\n";
        std:: cout << date.year() << "\n";
        
        date.add_days(125);

        return 0;
    }
    
    catch (Month_exceeding) {
            std::cerr << "Maximum number of months in the year exceeded.\n";
            return 1;}
    catch (Day_exceeding) {
            std::cerr << "Maximum number of days for this month exceeded.\n";
            return 1;}
}

void Date::add_days(unsigned int n) {
    
    unsigned int D = _day; // Perchè non posso scrivere date.day????
    unsigned int M = _month;
    unsigned int Y = _year;
    unsigned int gg;
    
    while (n>0) {
        if (M==0 || M==2 || M==4 || M==6 || M==7 || M==9 || M==11) {
        gg = 31;
        }
        else if (M==3 || M==5 || M==8 || M==10) {
        gg = 30;
        }
        else {
            bool leap_check = leap(Y);
            if (leap_check==true) {
                //std::cout << "leap";
                gg = 29;
            }
            else {
                gg = 28;
            }
        }
        
        if (n>gg-D && M==11) {
        Y = Y +1;
        M = 0;
        n = n - (gg-D);
        D = 0;
        }
        else if (n>gg-D && M!=11) {
        M = M +1;
        n = n - (gg-D);
        D = 0;
        }
        else {
        D = D + n;
        n = 0;
        }
    }
    
    std:: cout << D << "\n";
    std:: cout << M + 1 << "\n";
    std:: cout << Y << "\n";

}

bool leap(unsigned int yy) {

    bool flag;

    if (yy%4==0 && yy%100!=0) {
    flag = true;
    }
    else if (yy%400==0) {
    flag = true;
    }
    else {
    flag = false ;
    }
    
    return flag;

}














