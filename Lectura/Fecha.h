#pragma once
#include <string>

class Fecha {
  private:
    std::string mes; // Jan, ... Oct, Nov, Dec
    std::string hhmmss; // 12:45:26
    int m;
    int dia;
    int hh;
    int mm;
    int ss;
  public:
    Fecha(std::string, int, std::string);
    void print();
    bool operator<(Fecha&);
};