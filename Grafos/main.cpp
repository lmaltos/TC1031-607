#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
    Grafo<char> g(false);
    // Agregar los nodos
    g.addNodo('A');
    g.addNodo('B');
    g.addNodo('C');
    g.addNodo('D');
    g.addNodo('E');
    // Agregar las adyacencias
    g.addAdyacencia('A','B');
    g.addAdyacencia('A','C');
    g.addAdyacencia('A','E');
    g.addAdyacencia('B','D');
    g.addAdyacencia('C','D');
    g.addAdyacencia('D','E');
    
    for (char i = 'A'; i <= 'E'; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            if (g.getAdyacencia(i,j))
             cout << "1 ";
            else
             cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}