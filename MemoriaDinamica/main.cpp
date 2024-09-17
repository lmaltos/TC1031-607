#include <iostream>

using namespace std;

void Decalogo1();
void Decalogo2();
void Decalogo3();
void Decalogo4();
void Decalogo5();
void Decalogo6();
void Decalogo7();
void Decalogo9();
void Decalogo10();
void arreglo();

int main() {
    arreglo();
    return 0;
}

void Decalogo1() {
    int a = 0;
    int *p;
    p = &a;
    cout << "a: " << a << endl
        << "p: " << p << endl
        << "&p: " << &p << endl
        << "*p: " << *p << endl;
    p = new int;
    cout << "p = new int;" << endl;
    cout << "p: " << p << endl
        << "&p: " << &p << endl
        << "*p: " << *p << endl;
    *p = 5;
    cout << "*p: " << *p << endl;
    a += *p;
    *p *= a;
    cout << "*p: " << *p << endl;
    delete p;
    //delete p; // segundo delete free(): double free detected in tcache 2
}

void Decalogo2() {
    int * p, *q, *r;
    p = new int;
    q = r = p;
    *r = 10;
    *q = 42;
    cout << "&p: " << &p << endl
        << "&q: " << &q << endl
        << "&r: " << &r << endl
        << "p: " << p << endl
        << "q: " << q << endl
        << "r: " << r << endl
        << "*p: " << *p << endl
        << "*q: " << *q << endl
        << "*r: " << *r << endl;
    delete q;
    //delete p; doble delete
}

void* d3() {
    int *p;
    p = new int;
    *p = 32;
    cout << "p: " << p << endl
        << "&p: " << &p << endl
        << "*p: " << *p << endl;
    cout << "Termina d3()" << endl;
    return p;
}

void Decalogo3() {
    void *q = d3();
    int *r;
    r = (int*)q;
    cout << "q: " << q << endl
        << "&q: " << &q << endl
        << "*r: " << *r << endl;
    delete r;
}

void Decalogo4() {
    int *p, *q = nullptr; // NULL
    cout << "p: " << p << endl
        << "q: " << q << endl;
    delete q;
}

void Decalogo5() {
    int *p;
    int a;
    cout << "p: " << p << endl;
    //delete p; // munmap_chunk(): invalid pointer
    p = &a;
    //delete p;
}

void Decalogo6() {
    int *p = nullptr;
    cout << "p: " << p << endl;
    if (p != nullptr) {
        cout << "*p: " << *p << endl;
    }
}

void Decalogo7() {
    int *p, *q;
    p = new int;
    for (int i = 0; i < 10; i++) {
        cout << "p: " << p << endl;
        q = p;
        p = new int;
        cout << "p: " << p << endl;
        delete q;
        cout << "delete q;" << endl;
        cout << "q: " << q << endl;
    }
    cout << "delete p;" << endl;
    cout << "p: " << p << endl;
    delete p;
    
}

void Decalogo9() {
    int *p, *q;
    p = new int(5);
    q = new int(5);
    cout << "*p: " << *p << endl
        << "*q: " << *q << endl;
    if (p == q) {
        cout << "apuntan a donde mismo" << endl;
    }
    else {
        cout << p << "!=" << q << endl
            << "no apuntan a donde mismo" << endl;
    }
    if (*p == *q) {
        cout << "*p: " << *p << "=="
            << "*q: " << *q << endl
            << "tienen mismo valor" << endl;
    }
    else {
        cout << "*p: " << *p << "!="
            << "*q: " << *q << endl
            << "no tienen mismo valor" << endl;
    }
    delete p;
    delete q;
}

void Decalogo10() {
    int *p = new int;
    cout << "*p = 5;" << endl;
    *p = 5;
    cout << "*p: " << *p << endl;
    cout << "*p += 2;" << endl;
    *p += 2;
    cout << "*p: " << *p << endl;
    cout << "*p /= 3;" << endl;
    *p /= 3;
    cout << "*p: " << *p << endl;
    cout << "*p = *p * *p;" << endl;
    *p = *p * *p;
    cout << "*p: " << *p << endl;

    delete p;
}

void arreglo() {
    int a[100];
    int n;
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 32 + 1; // aleatorios entre 1 y 32
    }
    for (int i = 0; i < 100; i++) {
        cout << a[i] << " ";
        if ((i +1) % 10 == 0) cout << endl;
    }
    do {
        cout << "Posicion a consultar: ";
        cin >> n;
        if (n >= 0 && n < 100) {
            cout << "a[n]: " << (a + n) << "\t" << *(a + n) << endl;
        }
        else {
            break;
        }
    } while (true);
}