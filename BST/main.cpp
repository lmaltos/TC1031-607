#include <iostream>
#include "AVL.h"

using namespace std;
int main() {
    AVL<int> x;
    for (int i = 1; i < 32; i++) {
        x.add(rand()%100);
        if (i%5 == 0) x.preorden();
    }
    x.pornivel();
    for (int i = 1; i < 50; i++) {
        x.erase(rand()%100);
    }
    return 0;
}

int main_BST() {
    BST<int> arbol;
    for (int i = 0; i < 20; i++) {
        int x = rand() % 50;
        cout << x << " ";
        arbol.add(x);
    }
    cout << endl;
    arbol.preorden();
    arbol.inorden();
    arbol.postorden();
    arbol.pornivel();
    int n, k = 6;
    do {
        cout << "Ingrese un valor: ";
        cin >> n;
        if (arbol.search(n)) {
            cout << "El valor " << n << " esta en el BST" << endl;
            arbol.erase(n);
            arbol.pornivel();
        }
        else {
            cout << "El valor " << n << " NO esta en el BST" << endl;
        }

    } while (--k > 0);
    arbol.preorden();
    arbol.inorden();
    arbol.postorden();
    arbol.pornivel();
    return 0;
}