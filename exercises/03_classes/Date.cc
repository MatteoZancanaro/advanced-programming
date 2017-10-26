#include <iostream>
#include <string>

enum class m { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

class Date {
  unsigned int _day;
  unsigned int _month;
  unsigned int _year;

 public:
  Date(const unsigned int day, const unsigned int month, const unsigned int year) : _day{day}, _month{month}, _year{year} {}

  ~Date() {}

  unsigned int day() const { return _day; }
  unsigned int month() const { return _month; }
  unsigned int year() const { return _year; }
  
  void add_days();

};

int main() {
    const int D = 20;
    m opt = m:: mar;
    int M = int(opt);
    const int Y = 1990;
    
    Date date(D, M, Y);

    std:: cout << date.day() << "\n";
    std:: cout << date.month() +1 << "\n";
    std:: cout << date.year() << "\n";

  return 0;
}

void Date::add_days(int n) {
    
    while (n>0) {
        if (M==0 || M==2 || M==4 || M==6 || M==7 || M==9 || M==11) {
        unsigned int gg = 31;
        }
        else if (M==3 || M==5 || M==8 || M==10) {
        unsigned int gg = 30;
        }
        else {
            if (leap(Y)==1) {
                unsigned int gg = 29;
            }
            else {
                unsigned int gg = 28;
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
        D = n;
        n = 0;
        }
    }
    
    std:: cout << D << "\n";
    std:: cout << M << "\n";
    std:: cout << Y << "\n";

}

bool leap(unsigned int yy) {

    bool flag;

    if (yy%4==0 && yy%100!=0) {
    flag = 1;
    }
    else if (yy%400==0) {
    flag = 1;
    }
    else {
    flag = 0 ;
    }
    
    return flag;

}














