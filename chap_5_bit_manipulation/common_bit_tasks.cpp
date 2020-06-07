/*

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

int main(){

    // 31
    // std::cout << std::numeric_limits<char>::dfigits << endl;

    for (int i=0; i<32; i++){
        std::cout << getBit(10, 32-1-i);
    }
    std::cout << endl;

    // 6
    std::cout << setBit(4, 1) << endl;

    // 4
    std::cout << clearBit(6, 1) << endl;

    // 0
    std::cout << updateBit(4, 2, 0) << endl;

    // 12
    std::cout << updateBit(4, 3, 1) << endl;

    return 0;
}

