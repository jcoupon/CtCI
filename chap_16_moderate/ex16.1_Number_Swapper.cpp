#include <iostream>

using namespace std;

void swapNumber(int &a, int &b){

    a = a - b;
    b = a + b;
    a = b - a;

    return;
}

void swapNumberBit(int &a, int &b){

    a = a^b;
    b = a^b;
    a = a^b;

    return;
}



int main(){

    int a = 5;
    int b = 14;

    cout << a << ' ' << b << endl;
    swapNumber(a, b);
    cout << a << ' ' << b << endl;
    swapNumberBit(a, b);
    cout << a << ' ' << b << endl;

    return 0;
}