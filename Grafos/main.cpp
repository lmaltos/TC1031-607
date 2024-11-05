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
    g.addNodo('F');
    g.addNodo('G');
    g.addNodo('H');
    g.addNodo('I');
    g.addNodo('J');
    // Agregar las adyacencias
    g.addAdyacencia('A','B');
    g.addAdyacencia('A','E');
    g.addAdyacencia('A','H');
    g.addAdyacencia('B','C');
    g.addAdyacencia('B','E');
    g.addAdyacencia('C','D');
    g.addAdyacencia('C','E');
    g.addAdyacencia('C','F');
    g.addAdyacencia('E','G');
    g.addAdyacencia('E','H');
    g.addAdyacencia('F','J');
    g.addAdyacencia('G','J');
    g.addAdyacencia('H','I');
    g.addAdyacencia('H','J');
    
    for (char i = 'A'; i <= 'E'; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            if (g.getAdyacencia(i,j))
             cout << "1 ";
            else
             cout << "0 ";
        }
        cout << endl;
    }
    g.deepfirst();
    return 0;
}