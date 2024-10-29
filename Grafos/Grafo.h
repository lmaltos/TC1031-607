#pragma once
#include "Nodo.h"

template <class T>
class Grafo {
  private:
    Nodo<T> *first;

  public:
    Grafo();
    ~Grafo();
    void addNodo(T);
    void removeNodo(T);
    Nodo<T>* getNodo(T);
    void addAdyacencia(T,T);
    void removeAdyacencia(T,T);
    bool getAdyacencia(T,T);
}