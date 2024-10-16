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
    cout << endl;
    cout << "Contra cual quieres comparar? : ";
    int m;
    cin >> m;
    registros[m].print();
    cout << endl;
    cout << "El registro " << (registros[n] < registros[m] ? n : m) << " es menor" << endl;
    return 0;
}

void leerArchivo(string nombreArchivo, vector<Registro>& registros) {
    ifstream s;
    s.open(nombreArchivo);
    Registro r;
    while (!s.eof()) {
        s >> r;
        registros.push_back(r);
    }
    s.close(); // hay que cerrar nuestro archivo al terminar la lectura
}