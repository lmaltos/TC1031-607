#pragma once
#include "nodo.h"

class lista {
  private:
    nodo *head;
    int size;
  public:
    lista();
    ~lista();
    int getSize();
    void addFirst(int);
    void addLast(int);
    void print();
    int get(int);
};

#include <iostream>
using namespace std;

lista::lista() {
    head = nullptr;
    size = 0;
}

lista::~lista() {
    nodo *p, *q;
    p = head;
    while (p != nullptr) {
        q = p->getNext();
        cout << "~lista(): delete " << p << endl;
        delete p;
        p = q;
    }
}

int lista::getSize(){
    return size;
}

void lista::addFirst(int a) {
    nodo *nuevo = new nodo(a);
    cout << "addFirst(" << a << "): " << nuevo << endl;
    nuevo->setNext(head);
    head = nuevo;
    size++;
}

void lista::addLast(int a) {
    nodo *nuevo = new nodo(a);
    cout << "addLast(" << a << "): " << nuevo << endl;
    nodo *ultimo_nodo = head;
    while (ultimo_nodo->getNext() != nullptr) {
        ultimo_nodo = ultimo_nodo->getNext();
    }
    ultimo_nodo->setNext(nuevo);
    size++;
}

void lista::print() {
    nodo *p;
    p = head;
    while (p != nullptr) {
        cout << p->getData() << " ";
        p = p->getNext();
    }
    cout << endl;
}

int lista::get(int position) {
    if (position < 0 || position >= size)
        return -1; // valor default indice fuera de rango
    nodo *p = head;
    for(int i = 0; i < position; i++) {
        p = p->getNext();
    }
    return p->getData();
}