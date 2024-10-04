#pragma once
#include "nodeT.h"
#include <iostream>

using namespace std;

template <class T>
class BST {
  private:
    nodeT<T> *root;
    void borrar(nodeT<T>*);
  public:
    BST();
    ~BST();
    bool search(T);
    void add(T);
};

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::~BST() {
    borrar(root);
}

template <class T>
void BST<T>::borrar(nodeT<T> *p) {
    if (p == nullptr)
        return;
    borrar(p->getLeft());
    borrar(p->getRight());
    cout << "delete " << p << " " << p->getData() << endl;
    delete p;
}

template <class T>
bool BST<T>::search(T valor) {
    nodeT<T> *p = root;
    while (p != nullptr) {
        if (p->getData() == valor)
            return true; // encontramos el valor
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    return false;
}

template <class T>
void BST<T>::add(T valor) {
    if (search(valor))
        return; // el valor ya existe en el BST
    nodeT<T> *p, *q = nullptr;
    p = root;
    while (p != nullptr) {
        q = p; // guarda ultima referencia valida de p
        p = p->getData() > valor ? p->getLeft() : p->getRight();
    }
    nodeT<T> *nuevo = new nodeT<T>(valor);
    cout << "new " << nuevo << " " << valor << endl;
    if (q == nullptr) {
        root = nuevo; // es el primer elemento en el BST
    }
    else {
        if (q->getData() > valor) {
            q->setLeft(nuevo);
        }
        else {
            q->setRight(nuevo);
        }
    }
}