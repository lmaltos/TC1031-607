#include <iostream>
#include "stack.h"

using namespace std;
int main() {
    int a;
    stack s;
    for(int i = 0; i < 15; i++) {
        a = rand()%10;
        cout << "push(" << a << ")" << endl;
        s.push(a);
    }
    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}