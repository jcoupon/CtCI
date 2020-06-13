#include <iostream>
#include <string>
#include <math.h>

using namespace std;


void print_binary(int n){

    bool res;
    for(int k=6; k>=0;k--){
        res = (n & (1<<k)) >= 1;
        std::cout << res;
    }
    std::cout << endl;

}

void print_binary_double(double d){

    int count = 0;
    for (int i = 0; i<32; i++){
        d = d * 2.0;
        std::cout << floor(d); 
        count += floor(d);
        d -= floor(d);
    }
    std::cout << endl;

    if (count == 0) std::cout << "ERROR" << endl;

}

void print_binary_double_2(double d){


    double r;
    string binary = "1.";
    int count = 0;

    while(d > 0.0){

        if (count > 32){
            std::cout << "ERROR" << endl;
            return;
        }
        count++;

        r = 2.0*d;
        if(r < 1.0){
            d = r;   
            binary += "0";
        }
        else{
            d = r-1.;
            binary += "1";
        }

    }

    std::cout << binary << endl;

    return;

}


int main(){

    // 000111
    // print_binary(7);

    // print_binary_double(0.72);
    // print_binary_double(0.000000000000000000000000000000005);

    // 1.001
    print_binary_double_2(0.125);

    // ERROR
    print_binary_double_2(0.72);

    return 0;

}