#pragma once

template <class T>
class Adyacencia {
  private:
    T etiqueta;
    Adyacencia  *next;
  public:
    Adyacencia(T);
    Adyacencia(T,Adyacencia<T>*);
    Adyacencia<T>* getNext();
    void setNext(Adyacencia<T>*);
    T getEtiqueta();
};

template <class T>
Adyacencia<T>::Adyacencia(T tag) {
    etiqueta = tag;
    next = nullptr;
}

template <class T>
Adyacencia<T>::Adyacencia(T tag,Adyacencia<T>* n) {
    etiqueta = tag;
    next = n;
}

template <class T>
Adyacencia<T>* Adyacencia<T>::getNext(){
    return next;
}

template <class T>
void Adyacencia<T>::setNext(Adyacencia<T>* n) {
    next = n;
}

template <class T>
T Adyacencia<T>::getEtiqueta() {
    return etiqueta;
}