#ifndef NODO_H
#define NODO_H

class nodo {
  private:
    int data;
    nodo *next;
  public:
    nodo(int);
    nodo(int,nodo*);
    int getData();
    nodo* getNext();
    void setData(int);
    void setNext(nodo*);
};

nodo::nodo(int x) {
    data = x;
    next = nullptr;
}

nodo::nodo(int x,nodo* p) {
    data = x;
    next = p;
}

int nodo::getData() {
    return data;
}

nodo* nodo::getNext() {
    return next;
}

void nodo::setData(int x) {
    data = x;
}

void nodo::setNext(nodo* p) {
    next = p;
}

#endif