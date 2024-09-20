#ifndef VECTOR_H
#define VECTOR_H

class vector {
  private:
    int *p; // referencia a arreglo
    int n; // tamaño actual de nuestro arreglo
  public:
    vector(); // constructor default
    ~vector(); // destructor
    void add(int); // agregar elemento al final
    void remove(int); // eliminar elemento en una posicion
    int get(int); // obtener elemento en una posicion
    void setsize(int); // cambiar el tamaño
    int getsize(); // regresa el tamaño
};

#endif