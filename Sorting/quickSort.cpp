#include "quickSort.h"

int particion(int arr[],int ini,int fin);

void quickSort(int arr[], int ini, int fin) {
    if (ini < fin) {
        int pivote = particion(arr,ini,fin);
        quickSort(arr,ini,pivote - 1);
        quickSort(arr,pivote + 1,fin);
    }
}

int particion(int arr[],int ini,int fin) {
    int pivote = arr[ini];
    int i = ini;
    for (int j = ini + 1; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[ini] = arr[i];
    arr[i] = pivote;
    return i;
}