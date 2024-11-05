#include <iostream>
#include "Hash.h"

using namespace std;

int mod11(int n,int a) {
    return a % 11;
}

int main() {
    Hash<int> H(11,mod11);
    H.add(7);
    H.add(17);
    H.add(6);
    H.add(33);
    H.add(28);
    H.add(52);
    for (int i = 1; i < 55; i++) {
        if (H.isIn(i))
            cout << i << " esta en la tabla" << endl;
    }
    return 0;
}