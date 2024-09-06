#include "Registro.h"
#include <iostream>

Registro::Registro()
: fecha("Jul",1,"00:00:01") {
    ip = "256.256.256.256:0001";
    mensaje = "";
}

Registro::Registro(std::string mes, int dia, std::string hhmmss, std::string ip, std::string mensaje)
: fecha(mes,dia,hhmmss) {
    Registro::ip = ip;
    this->mensaje = mensaje;
}

Registro::Registro(Fecha fecha, std::string ip, std::string mensaje)
: fecha(fecha) {
    this->ip = ip;
    Registro::mensaje = mensaje;
}

void Registro::print() {
    fecha.print();
    std::cout << " " << ip << " " << mensaje;
}