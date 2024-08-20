#ifndef QUICKSORT_H
#define QUICKSORT_H

template <typename T>
void quickSort(T arr[], int inicio, int fin);

template <typename T>
int particion(T arr[],int ini,int fin);

template <typename T>
void quickSort(T arr[], int ini, int fin) {
    if (ini < fin) {
        int pivote = particion(arr,ini,fin);
        quickSort(arr,ini,pivote);
        quickSort(arr,pivote + 1,fin);
    }
}

template <typename T>
int particion(T arr[],int ini,int fin) {
    T pivote = arr[ini];
    int i = ini;
    for (int j = ini + 1; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            T tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    arr[ini] = arr[i];
    arr[i] = pivote;
    return i;
}
#endif