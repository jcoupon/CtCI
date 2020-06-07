/*
Done well:
    - done in 20 mn

To improve:
    - solution was correct but hand written solution was not
    - train on hand bit manipulation
    - book solution uses a single mask to clear the bit, remember it
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool getBit(int num, int i){

    int res;

    res = num & (1 << i);

    return res != 0;
}

int setBit(int num, int i){

    int res;
    res = num | (1 << i);

    return res;
}

int clearBit(int num, int i){

    int res;
    res = num & ~(1 << i);

    return res;
}

int updateBit(int num, int i, bool bit){

    int res;

    // clear bit;
    res = num & ~(1 << i);

    // update it
    res = res | (bit << i);

    return res;
}

int insert(int N, int M, int i, int j){

    // clear bits in N
    for (int n=i; n<=6; n++){
        N = clearBit(N, n);
    }
    // shift M
    M = M << i;

    // insert
    return N | M;
}

int main(){

    // 1100
    std::cout << insert(1024, 19, 2, 6) << endl;

    // 1101
    std::cout << insert(1029, 19, 2, 6) << endl;


    return 0;
}

