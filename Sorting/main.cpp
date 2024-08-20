#include <iostream>
#include "quickSort.h"
void insertionSort(int arr[], int n);

using namespace std;
int main() {
    int my_arreglo_int[8] = {15,22,13,27,12,10,20,25};
    string my_arreglo[8] = {"hola", "mundo", "quick", "sort", "merge", "bubble", "intercambio", "insercion"};
    cout << "my_arreglo_int [ ";
    for (int i = 0; i < 8; i++) {
        cout << my_arreglo_int[i] << " ";
    }
    cout << "]" << endl;
    cout << "my_arreglo [ ";
    for (int i = 0; i < 8; i++) {
        cout << my_arreglo[i] << " ";
    }
    cout << "]" << endl;
    //insertionSort(my_arreglo,10);
    quickSort<int>(my_arreglo_int,0,8);
    quickSort<string>(my_arreglo,0,8);
    cout << "my_arreglo_int [ ";
    for (int i = 0; i < 8; i++) {
        cout << my_arreglo_int[i] << " ";
    }
    cout << "]" << endl;
    cout << "my_arreglo [ ";
    for (int i = 0; i < 8; i++) {
        cout << my_arreglo[i] << " ";
    }
    cout << "]" << endl;
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