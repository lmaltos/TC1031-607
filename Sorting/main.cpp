#include <iostream>
#include "quickSort.h"
void insertionSort(int arr[], int n);
template <typename S>
void print(S[],int);

using namespace std;
int main_old() {
    char char_arr[10] = {'q','w','e','r','t','y','a','s','d','f'};
    int my_arreglo_int[8] = {15,22,13,27,12,10,20,25};
    string my_arreglo[8] = {"hola", "mundo", "quick", "sort", "merge", "bubble", "intercambio", "insercion"};
    double arreglo_Double[50];

    for (int i = 0; i < 50; i++)
        arreglo_Double[i] = (rand() % 100) / double(1.5 + rand() % 5);
    cout << "arreglo_Double [ ";
    print(arreglo_Double,20);
    cout << "]" << endl;

    cout << "my_arreglo [ ";
    print(my_arreglo,8);
    cout << "]" << endl;

    cout << "char_arr [ ";
    print(char_arr,10);
    cout << "]" << endl;

    cout << "Llamada a quickSort" << endl;
    //insertionSort(my_arreglo,10);
    quickSort(arreglo_Double,0,50);
    quickSort(my_arreglo,0,8);
    quickSort(my_arreglo_int,0,8);
    quickSort(char_arr,0,10);

    cout << "arreglo_Double [ ";
    print(arreglo_Double,20);
    cout << "]" << endl;

    cout << "my_arreglo_int [ ";
    print(my_arreglo_int,8);
    cout << "]" << endl;

    cout << "my_arreglo [ ";
    print(arreglo_Double,20);
    cout << "]" << endl;

    cout << "char_arr [ ";
    print(char_arr,10);
    cout << "]" << endl;
}

template <typename T>
void print(T arr[],int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        int key = arr[i];
        while (j > 0 && arr[j-1] > key) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
    }    
}

#include "Fecha.h"

int main() {
    Date Fechas[20];
    for(int i = 0; i < 20; i++) {
        Fechas[i].setYear(2000 + rand() % 10);
        Fechas[i].setMonth(1 + rand() % 12);
        Fechas[i].setDay(1 + rand() % 31);
    }
    print(Fechas,20);
    cout << endl;
    cout << "Llama quickSort" << endl;
    quickSort(Fechas,0,20);
    print(Fechas,20);
    cout << endl;
}