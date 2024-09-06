#pragma once
#include <string>
#include "Fecha.h"

class Registro {
  private:
    Fecha fecha;
    std::string ip;
    std::string mensaje;
  public:
    Registro();
    Registro(std::string, int, std::string, std::string, std::string);
    Registro(Fecha, std::string, std::string);
    void print();
};