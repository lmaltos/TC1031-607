#include "Fecha.h"
#include <iostream>
#include <sstream>
using namespace std;

int mestoi(string mes) {
    string meses[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for (int i = 0; i < 12; i++) {
        if (mes == meses[i])
            return i + 1;
    }
    return -1;
}

Fecha::Fecha(string mes, int dia, string hhmmss) 
: mes(mes), dia(dia), hhmmss(hhmmss) { // en esta region no existen problemas de enmascaramiento de variables
    m = mestoi(mes);
    stringstream iss(hhmmss);
    string s;
    getline(iss, s, ':'); // hh
    hh = stoi(s);
    getline(iss, s, ':'); // mm
    mm = stoi(s);
    getline(iss, s, ':'); // ss
    ss = stoi(s);
}

void Fecha::print() {
    cout << mes << " " << dia << " " << hhmmss;
}