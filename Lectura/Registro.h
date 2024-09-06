#pragma once
#include <string>
#include "Fecha.h"
#include <fstream>

class Registro {
  protected:
    Fecha fecha;
    std::string ip;
    std::string mensaje;
  public:
    Registro();
    Registro(std::string, int, std::string, std::string, std::string);
    Registro(Fecha, std::string, std::string);
    void print();
    bool operator<(Registro&);
    friend std::ifstream& operator>>(std::ifstream&,Registro&);
};