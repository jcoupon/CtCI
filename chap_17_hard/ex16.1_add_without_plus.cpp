#include <iostream>


using namespace std;

int addNum(int a, int b){

    while(b != 0){
        a = a^b;
        b = ((unsigned int)(a^b)&b)<<1;
    }
    return a;
}

int main(){

    cout << addNum(3, 34) << endl;
    cout << addNum(1, 5) << endl;
    cout << addNum(14, 0) << endl;
    cout << addNum(-10, 1) << endl;
    cout << addNum(-10, -2) << endl;
    cout << addNum(-10, 1230) << endl;

    return EXIT_SUCCESS;
}