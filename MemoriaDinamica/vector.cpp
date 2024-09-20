#include "vector.h"
#include <iostream>

using namespace std;

vector::vector() {
    p = nullptr;
    cout << "p = nullptr" << endl;
    n = 0;
}

vector::~vector() {
    cout << "~vector(): delete[] p " << p << endl;
    delete[] p;
}

void vector::add(int x) {
    int *q = new int [n+1];
    for (int i = 0; i < n; i++) {
        q[i] = p[i];
    }
    delete[] p; // borramos memoria anterior
    cout << "add: delete[] p " << p << endl;
    cout << "p = " << q << endl;
    p = q; // actualizamos referencia a memoria
    q[n] = x;
    n++;
}

void vector::remove(int i) {
    if (i < 0 || i >= n)
        return;
    int *q = new int [n-1];
    // copia elementos anteriores a i
    for(int j = 0; j < i; j++) { // 3 6 <-| 7 5 3
        q[j] = p[j];
    }
    // copia elementos posteriores a i
    for(int j = i+1; j < n; j++) { // 3 6 7 |-> 5 3
        q[j-1] = p[j];
    }
    cout << "remove: delete[] p " << p << endl;
    cout << "p = " << q << endl;
    delete[] p;
    p = q;
    n--;
}

int vector::get(int i) {
    if (i >= 0 && i < n)
        return p[i];
    return 0; // indice fuera de rango
}

void vector::setsize(int m) {
    if (m < 0)
        return;
    if (m < n) {
        int *q = new int [m];
        for(int i = 0; i < m; i++) {
            q[i] = p[i];
        }
        cout << "setzie: delete[] p " << p << endl;
        cout << "p = " << q << endl;
        delete[] p;
        p = q;
    }
    else if (m > n) {
        int *q = new int [m];
        for(int i = 0; i < n; i++) {
            q[i] = p[i];
        }
        for(int i = n; i < m; i++) {
            q[i] = 0; // nuevos elementos se inicializan con 0
        }
        cout << "setsize: delete[] p " << p << endl;
        cout << "p = " << q << endl;
        delete[] p;
        p = q;
    }
    n = m;
}

int vector::getsize() {
    return n;
}