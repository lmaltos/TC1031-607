#pragma once
#include "celda.h"

template <class T>
class Hash {
  private:
    int max_size;
    celda<T> *p;
    int (*funcion_hash)(int,T);
  public:
    Hash(int,int (*)(int,T));
    ~Hash();
    void add(T);
    void del(T);
    bool isIn(T);
};


template <class T>
Hash<T>::Hash(int n,int (*f)(int,T)) {
    max_size = n;
    funcion_hash = f;
    p = new celda<T>[n];
}

template <class T>
Hash<T>::~Hash() {
    delete[] p;
}

template <class T>
void Hash<T>::add(T dato) {
    if (isIn(dato)) {
        return; // el elemento ya está en la tabla hash
    }
    int idx = funcion_hash(max_size, dato);
    if (!p[idx].isOcupada()) {
        p[idx].setDato(dato);
    }
    else {
        int idx2 = idx;
        do {
            idx2 = (idx2 + 1) % max_size;
            if (!p[idx2].isOcupada()) {
                p[idx2].setDato(dato);
                break;
            }
        } while (idx2 != idx);
    }
}

template <class T>
void Hash<T>::del(T dato) {
    if (!isIn(dato)) {
        return; // el elemento no esta en la tabla hash<
    }
    int idx = funcion_hash(max_size, dato);
    if (p[idx].getDato() == dato) {
        p[idx].delDato();
    }
    else {
        do {
            idx = (idx + 1) % max_size;
        } while (!p[idx].isOcupada() || p[idx].getDato() != dato);
        p[idx].delDato();
    }
    
}

template <class T>
bool Hash<T>::isIn(T dato) {
    int idx,idx_base = funcion_hash(max_size, dato);
    idx = idx_base;
    while (!p[idx].isVacia()) {
        if (p[idx].getDato() == dato) {
            return true;
        }
        idx = (idx + 1) % max_size;
        if (idx == idx_base) {
            break;
        }
    }
    return false;
}