#pragma once
#include "Nodo.h"

template <class T>
class Grafo {
  private:
    Nodo<T> *first;
    bool dirigido;
  public:
    Grafo(bool);
    ~Grafo();
    bool isDirigido();
    void addNodo(T);
    void addAdyacencia(T,T);
    void removeNodo(T);
    void removeAdyacencia(T,T);
    Nodo<T>* getNodo(T);
    bool getAdyacencia(T,T);
};

template <class T>
Grafo<T>::Grafo(bool d) {
  first = nullptr;
  dirigido = d;
}

template <class T>
bool Grafo<T>::isDirigido() {
  return dirigido;
}

template <class T>
Grafo<T>::~Grafo(){
  Nodo<T> *a = first, *b = nullptr;
  while (a != nullptr) {
    b = a->getNext();
    delete a;
    a = b;
  }
}

template <class T>
void Grafo<T>::addNodo(T tag) {
  Nodo<T> *a = getNodo(tag);
  if (a != nullptr) {
    return; // ya existe un nodo con esa etiqueta
  }
  a = new Nodo<T>(tag);
  if (first == nullptr) {
    // no tengo elementos, por lo que 'a' sera el primero
    first = a;
  }
  else {
    // se agrega al final de la lista
    Nodo<T> *b = first;
    while (b->getNext() != nullptr) {
      b = b->getNext();
    }
    b->setNext(a);
  }
}

template <class T>
void Grafo<T>::addAdyacencia(T tag1,T tag2) {
  Nodo<T> *a = getNodo(tag1);
  Nodo<T> *b = getNodo(tag2);
  if (a != nullptr && b != nullptr) {
    a->addAdyacencia(b);
    if (!dirigido){
      b->addAdyacencia(a);
    }
  }
}

template <class T>
void Grafo<T>::removeNodo(T tag) {
  Nodo<T> *a = getNodo(tag);
  if (a == nullptr) {
    return; // no existe el nodo en el grafo
  }
  // Borrar adyacencias
  Nodo<T> *b = first;
  while (b != nullptr) {
    if (b->isAdyacente(a)) {
      b->removeAdyacencia(a);
    }
    b = b->getNext();
  }
  // Borrar nodo
  if (first == a) {
    first = a->getNext();
  }
  else {
    b = first;
    while (b->getNext() != a) {
      b = b->getNext();
    }
    b->setNext(a->getNext()); // se remueve 'a' de la lista de nodos
    delete a;
  }
}

template <class T>
void Grafo<T>::removeAdyacencia(T tag1,T tag2) {
  Nodo<T> *a = getNodo(tag1);
  Nodo<T> *b = getNodo(tag2);
  if (a != nullptr && b != nullptr) {
    a->removeAdyacencia(b);
    if (!dirigido) {
      b->removeAdyacencia(a);
    }
  }
}

template <class T>
Nodo<T>* Grafo<T>::getNodo(T tag) {
  Nodo<T> *b = first;
  while (b != nullptr) {
    if (b->getEtiqueta() == tag) {
      return b;
    }
    b = b->getNext();
  }
  return nullptr; // no se encontró el nodo
}

template <class T>
bool Grafo<T>::getAdyacencia(T tag1,T tag2) {
  Nodo<T> *a = getNodo(tag1);
  Nodo<T> *b = getNodo(tag2);
  if (a != nullptr && b != nullptr) {
    return a->isAdyacente(b);
  }
  return false;
}