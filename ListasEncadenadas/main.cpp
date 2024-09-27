#include <iostream>
#include "lista.h"

int main() {
    lista l,m;
    l.addFirst(1);
    l.addFirst(2);
    l.addFirst(3);
    l.addFirst(4);
    l.addFirst(5);
    l.addFirst(6);
    m.addFirst(11);
    m.addFirst(12);
    m.addFirst(13);
    m.addFirst(14);
    m.addFirst(15);
    m.addFirst(16);
    l.addLast(7);
    l.addLast(8);
    l.addLast(9);
    l.addLast(10);
    l.print();
    m.print();
    int n;
    cout << "Indique posicion: ";
    cin >> n;
    cout << l.get(n) << endl;
    return 0;
}