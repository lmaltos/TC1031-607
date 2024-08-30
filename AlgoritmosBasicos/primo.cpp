#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

static const int M = 1000000;
int criba[M];

bool esPrimo(int);
void inicializarCriba();

int main1(int argc, char *argv[]) {
    int n;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }
    if (argc > 1) {
        n = atoi(argv[1]);
        if (esPrimo(n)) {
            cout << n << " es un numero primo" << endl;
        }
        else {
            cout << n << " no es un numero primo" << endl;
        }
    }
    return 0;
}

bool esPrimo(int n) {
    int limite = sqrt(n);
    for (int i = 2;i <= limite; i++) {
        if (n % i == 0) // n es divisible por i
            return false; // n no es primo
    }
    return true; // n es primo
}

void inicializarCriba() {
    for (int i = 0; i < M; i++) {
        criba[i] = 1;
    }
    for (int i = 2; i < M; i++) {
        if (criba[i]) {
            for(int j = 2 * i; j < M; j+= i) {
                criba[j] = 0;
            }
        }
    }
}

int main() {
    int count = 0;
    int t = time(0);
    inicializarCriba();
    for (int i = 2; i < M; i++) {
        if (criba[i]) {
            cout << i << ", ";
            count++;
            if (count % 10 == 0)
                cout << endl;
        }
    }
    cout << endl;
    cout << time(0) - t << endl;
    cout << "Termina proceso criba" << endl;
    t = time(0);
    count = 0;
    for (int i = 2; i < M; i++) {
        if (esPrimo(i)) {
            cout << i << ", ";
            count++;
            if (count % 10 == 0)
                cout << endl;
        }
    }
    cout << endl;
    cout << time(0) - t << endl;
    cout << "Termina proceso esPrimo" << endl;
    
}