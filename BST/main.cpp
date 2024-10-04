#include <iostream>
#include "BST.h"

using namespace std;
int main() {
    BST<int> arbol;
    for (int i = 0; i < 20; i++) {
        int x = rand() % 50;
        cout << x << " ";
        arbol.add(x);
    }
    int n;
    do {
        cout << "Ingrese un valor: ";
        cin >> n;
        if (arbol.search(n)) {
            cout << "El valor " << n << " esta en el BST" << endl;
            break;
        }
        else {
            cout << "El valor " << n << " NO esta en el BST" << endl;
        }

    } while (true);
    return 0;
}