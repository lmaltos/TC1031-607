#pragma once
#include "BST.h"
#include <iostream>

template <class T>
class AVL : public BST<T> {
  private:
    bool isBalanced(T);
    int altura(nodeT<T>*);
    bool isBalanced(nodeT<T>*);
    void cambiarPadre(nodeT<T>*,nodeT<T>*);
  public:
    void add(T);
    void erase(T);
};

template <class T>
void AVL<T>::add(T data) {
    BST<T>::add(data);
    if (isBalanced(data)) {
        return;
    }
    // no esta balanceado, hay que hacer una rotacion
    // Se busca el pivote, ancesto desbalanceado mas cercano al nodo que se agrego
    nodeT<T> *p = BST<T>::root, *B, *A;
    while (p != nullptr){
        if (!isBalanced(p)) {
            B = p;
        }
        p = p->getData() > data ? p->getLeft() : p->getRight();
    }
    if (B->getData() > data) {
        // ToDo
        A = B->getLeft();
        if (A->getData() > data) {
            // Caso: RSD
            cout << "RSD B: " << B->getData() << " A: " << A->getData() << endl;
            B->setLeft(A->getRight());
            A->setRight(B);
            cambiarPadre(B,A);
        }
        else {
            // Caso: RDD
            nodeT<T> *C = A->getRight();
            cout << "RDD B: " << B->getData() << " A: " << A->getData() << " C: " << C->getData() << endl;
            A->setRight(C->getLeft());
            B->setLeft(C->getRight());
            C->setLeft(A);
            C->setRight(B);
            cambiarPadre(B,C);
        }
    }
    else {
        A = B->getRight();
        if (A->getData() > data) {
            // caso RDI
            nodeT<T> *C = A->getLeft();
            cout << "RDI B: " << B->getData() << " A: " << A->getData() << " C: " << C->getData() << endl;
            B->setRight(C->getLeft());
            A->setLeft(C->getRight());
            C->setLeft(B);
            C->setRight(A);
            cambiarPadre(B,C);
        }
        else {
            // caso RSI: Rotacion Simple a la Izquierda
            cout << "RSI B: " << B->getData() << " A: " << A->getData() << endl;
            B->setRight(A->getLeft());
            A->setLeft(B);
            cambiarPadre(B,A);
        }
    }
}

template <class T>
bool AVL<T>::isBalanced(T data) {
    nodeT<T> *p = BST<T>::root;
    while (p != nullptr){
        if (!isBalanced(p)) {
            return false;
        }
        p = p->getData() > data ? p->getLeft() : p->getRight();
    }
    return true;
}

template <class T>
bool AVL<T>::isBalanced(nodeT<T> *p) {
    int alturaIzq = altura(p->getLeft());
    int alturaDer = altura(p->getRight());
    if (alturaIzq > alturaDer + 1 || alturaDer > alturaIzq + 1) {
        return false;
    }
    return true;
}

template <class T>
int AVL<T>::altura(nodeT<T> *p) {
    if (p == nullptr) return 0;
    int alturaIzq = altura(p->getLeft());
    int alturaDer = altura(p->getRight());
    if (alturaIzq > alturaDer) {
        return alturaIzq + 1;
    }
    else {
        return alturaDer + 1;
    }
}

template <class T>
void AVL<T>::cambiarPadre(nodeT<T>* B,nodeT<T>* A){
    nodeT<T> *p = BST<T>::root, *padre = nullptr;
    while (p != B) {
        padre = p;
        p = p->getData() > B->getData() ? p->getLeft() : p->getRight();
    }
    if (padre == nullptr) {
        // el nodo pivote B es la raiz del arbol
        BST<T>::root = A;
    }
    else if (padre->getData() > B->getData()) {
        padre->setLeft(A);
    }
    else {
        padre->setRight(A);
    }
}

template <class T>
void AVL<T>::erase(T data) {
    BST<T>::erase(data);
    if (isBalanced(data)) {
        return;
    }
    nodeT<T> *p, *B;
    do {
        p = BST<T>::root;
        B = nullptr;
        cout << "Busca rebalancear" << endl;
        while (p != nullptr) {
            if (!isBalanced(p)) {
                B = p; // ancestro no balanceado
            }
            p = p->getData() > data ? p->getLeft() : p->getRight();
        }
        int i = altura(B->getLeft());
        int d = altura(B->getRight());
        nodeT<T> *A;
        if (i < d) {
            A = B->getRight();
            B->setRight(A->getLeft());
            A->setLeft(B);
            cambiarPadre(B,A);
        }
        else {
            A = B->getLeft();
            B->setLeft(A->getRight());
            A->setRight(B);
            cambiarPadre(B,A);
        }
    } while (!isBalanced(data));
}