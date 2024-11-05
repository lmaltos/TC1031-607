#pragma once

enum estado {
    ocupado,
    vacio,
    borrado,
};

template <class T>
class celda {
  private:
    estado e;
    T dato;
  public:
    celda();
    T getDato();
    void setDato(T);
    void delDato();
    bool isVacia();
    bool isBorrada();
    bool isOcupada();
};

template <class T>
celda<T>::celda() {
    e = vacio;
}

template <class T>
T celda<T>::getDato() {
    return dato;
}

template <class T>
void celda<T>::setDato(T d) {
    dato = d;
    e = ocupado;
}

template <class T>
void celda<T>::delDato() {
    if (e == ocupado) {
        e = borrado;
    }
}

template <class T>
bool celda<T>::isVacia() {
    return e == vacio;
}

template <class T>
bool celda<T>::isBorrada() {
    return e == borrado;
}

template <class T>
bool celda<T>::isOcupada() {
    return e == ocupado;
}