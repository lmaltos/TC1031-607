#include <iostream>
#include <fstream>
#include "Registro.h"
#include <vector>

using namespace std;
void leerArchivo(string, vector<Registro>&);

int main(int argc, char* argv[]) {
    string nombreArchivo = "bitacora.txt";
    vector<Registro> registros;
    if (argc > 1) {
        nombreArchivo = argv[1];
    }

    leerArchivo(nombreArchivo, registros);
    cout << "Total de lineas: " << registros.size() << endl;
    cout << "Cual registro quieres ver? : ";
    int n;
    cin >> n;
    registros[n].print();
    return 0;
}

void leerArchivo(string nombreArchivo, vector<Registro>& registros) {
    ifstream s;
    s.open(nombreArchivo);

    string mes;
    int dia;
    string hora;
    string ip;
    string mensaje;
    while (!s.eof()) {
        s >> mes >> dia >> hora >> ip;
        getline(s,mensaje); // lee el resto de lina (que contiene el mensaje completo)
        Registro r(mes,dia,hora,ip,mensaje);
        registros.push_back(r);
    }
    s.close(); // hay que cerrar nuestro archivo al terminar la lectura
    cout << "Ultima linea del archivo: ";
    cout << mes << " " << dia << " " << hora << " " << ip << " " << mensaje << endl;
}