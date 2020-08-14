#include <iostream>
#include <string>
#include <limits>

using namespace std;

bool getBit(int num, int i){

    int res;

    res = num & (1 << i);

    return res != 0;
}

int flipBit(int num){
    int n_seq_max = 1;
    int n_seq_curr = 0;
    int n_seq_prev = 0;
    int flipped = 0;

    for(int i=0; i<32; i++){
        if(getBit(num, i) == 0 && i>0){
            n_seq_prev = n_seq_curr - flipped;
            n_seq_curr = 0;
        }
        if(getBit(num, i) == 0) flipped  = 1;
        n_seq_curr++;
        n_seq_max = n_seq_curr+n_seq_prev > n_seq_max ? n_seq_curr+n_seq_prev: n_seq_max;
    
        // cout << i << ' ' << n_seq_prev << ' ' << n_seq_curr << ' ' << n_seq_max << endl;
    } 


    return n_seq_max;
}


int main(){

    int num;

    // 8
    num = 1775;
    cout << flipBit(num) << endl;
    
    // 1
    num = 0;
    cout << flipBit(num) << endl;

    // 2
    num = 2;
    cout << flipBit(num) << endl;

    // 6
    num = 1+2+4+16+32+128+256+1024;
    cout << flipBit(num) << endl;

    return 0;
}