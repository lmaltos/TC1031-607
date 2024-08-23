#pragma once
#include <ostream>

class Date {
  private:
    int day;
    int month;
    int year;
  public:
    Date();
    Date(int,int,int);
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    int getDay();
    int getMonth();
    int getYear();
    void print();
    bool operator<(Date&);
};

std::ostream& operator<<(std::ostream&, Date&);