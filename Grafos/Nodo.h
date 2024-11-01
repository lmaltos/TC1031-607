#pragma once
#include "Adyacencia.h"

template <class T>
class Nodo {
  private:
    T etiqueta;
    Nodo *next;
    Adyacencia<T> *first;
  public:
    Nodo(T);
    ~Nodo();
    Nodo<T>* getNext();
    void setNext(Nodo<T>*);
    T getEtiqueta();
    void addAdyacencia(Nodo<T>*);
    void removeAdyacencia(Nodo<T>*);
    bool isAdyacente(Nodo<T>*);
};

template <class T>
Nodo<T>::Nodo(T tag) {
    etiqueta = tag;
    next = nullptr;
    first = nullptr;
}

template <class T>
Nodo<T>::~Nodo() {
    Adyacencia<T> *p = first, *q = nullptr;
    while (p != nullptr) {
        q = p->getNext();
        delete p;
        p = q;
    }
}

template <class T>
Nodo<T>* Nodo<T>::getNext() {
    return next;
}

template <class T>
void Nodo<T>::setNext(Nodo<T>* n) {
    next = n;
}

template <class T>
T Nodo<T>::getEtiqueta() {
    return etiqueta;
}

template <class T>
bool Nodo<T>::isAdyacente(Nodo<T>* n) {
    Adyacencia<T> *p = first;
    while (p != nullptr) {
        if (p->getEtiqueta() == n->getEtiqueta())
            return true;
        p = p->getNext();
    }
    return false;
}

template <class T>
void Nodo<T>::addAdyacencia(Nodo<T>* n) {
    if (isAdyacente(n))
        return; // el nodo ya esta en la lista de adyacencia
    Adyacencia<T> *p = new Adyacencia<T>(n->getEtiqueta(),first);
    first = p;
}

template <class T>
void Nodo<T>::removeAdyacencia(Nodo<T>* n) {
    Adyacencia<T> *p = first, *q = nullptr;
    if (isAdyacente(n)) {
        while (p->getEtiqueta() != n->getEtiqueta()) {
            q = p;
            p = p->getNext();            
        }
        if (q != nullptr) {
            q->setNext(p->getNext());
        }
        else {
            first = p->getNext();
        }
        delete p;
    }
}