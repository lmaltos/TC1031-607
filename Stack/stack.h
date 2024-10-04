#pragma once

#define MAX 10

class stack {
  private:
    int datos[MAX];
    int tope;
  public:
    stack();
    void push(int);
    void pop();
    int top();
    bool isFull();
    bool isEmpty();
};

stack::stack(){
    tope = 0;
}

void stack::push(int a){
    if (isFull())
        return; // la pila esta llena
    datos[tope] = a;
    tope++;
}

void stack::pop(){
    if (isEmpty())
        return;
    tope--;
}

int stack::top(){
    return datos[tope-1];
}

bool stack::isFull(){
    if (tope == MAX)
        return true;
    return false;
}

bool stack::isEmpty(){
    return (tope == 0);
}