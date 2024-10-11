#pragma once
#include "nodeT.h"
#include <iostream>

using namespace std;

template <class T>
class BST {
  protected:
    nodeT<T> *root;
    void borrar(nodeT<T>*);
    void preorden(nodeT<T>*);
    void inorden(nodeT<T>*);
    void postorden(nodeT<T>*);
  public:
    BST();
    ~BST();
    bool search(T);
    virtual void add(T);
    void erase(T);
    void preorden();
    void inorden();
    void postorden();
    void pornivel();
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

template <class T>
void BST<T>::erase(T data) {
    if (!search(data))
        return; // el valor no existe en el BST
    nodeT<T> *p, *q = nullptr;
    p = root;
    while (p != nullptr) {
        if (p->getData() == data) {
            break;
        }
        q = p; // padre del siguiente p
        p = p->getData() > data ? p->getLeft() : p->getRight();
    }
    if (p->getLeft() == nullptr && p->getRight() == nullptr) {
        // caso p es un nodo hoja
        cout << "erase " << p << " " << p->getData() << endl;
        delete p;
        // remover referencia del padre
        if (q == nullptr) {
            // el BST se quedó vacío
            root = nullptr;
        }
        else if (q->getData() > data) {
            q->setLeft(nullptr);
        }
        else {
            q->setRight(nullptr);
        }
    }
    else if (p->getLeft() == nullptr || p->getRight() == nullptr) {
        // caso p tiene solo un hijo
        nodeT<T> *hijo;
        hijo = p->getRight() == nullptr ? p->getLeft() : p->getRight();
        cout << "erase " << p << " " << p->getData() << endl;
        delete p;
        if (q == nullptr) {
            root = hijo;
        }
        else if (q->getData() > data) {
            q->setLeft(hijo);
        }
        else {
            q->setRight(hijo);
        }
    }
    else {
        // caso p tiene hijoz izquierdo y derecho
        nodeT<T> *s = p->getRight();
        while (s->getLeft() != nullptr) {
            s = s->getLeft();
        }
        T valor = s->getData();
        erase(valor);
        p->setData(valor);
    }
}

template <class T>
void BST<T>::preorden() {
    preorden(root);
    cout << endl;
}

template <class T>
void BST<T>::inorden() {
    inorden(root);
    cout << endl;
}

template <class T>
void BST<T>::postorden() {
    postorden(root);
    cout << endl;
}
template <class T>
void BST<T>::preorden(nodeT<T> *p) {
    if (p == nullptr)
        return;
    cout << p->getData() << " ";
    preorden(p->getLeft());
    preorden(p->getRight());
}

template <class T>
void BST<T>::inorden(nodeT<T> *p) {
    if (p == nullptr)
        return;
    inorden(p->getLeft());
    cout << p->getData() << " ";
    inorden(p->getRight());
}

template <class T>
void BST<T>::postorden(nodeT<T> *p) {
    if (p == nullptr)
        return;
    postorden(p->getLeft());
    postorden(p->getRight());
    cout << p->getData() << " ";
}

#include <queue>
template <class T>
void BST<T>::pornivel() {
    queue<nodeT<T>*> q;
    nodeT<T>* p;
    if (root != nullptr) {
        q.push(root);
    }
    while (!q.empty()) {
        p = q.front();
        q.pop();
        cout << p->getData() << " ";
        if (p->getLeft() != nullptr) q.push(p->getLeft());
        if (p->getRight() != nullptr) q.push(p->getRight());
    }
    cout << endl;
}