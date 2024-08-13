#include <iostream>
void insertionSort(int arr[], int n);

using namespace std;
int main() {
    int my_arreglo[10] = {9,8,7,6,5,4,3,2,1,0};
    cout << "my_arreglo [ ";
    for (int i = 0; i < 10; i++) {
        my_arreglo[i] = rand() % 100; // aleatorio entre 0 - 99
        cout << my_arreglo[i] << " ";
    }
    cout << "]" << endl;
    insertionSort(my_arreglo,10);
    cout << "my_arreglo [ ";
    for (int i = 0; i < 10; i++) {
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