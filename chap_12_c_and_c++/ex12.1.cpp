/*
Done well:
    - code works
To improve:
    - think about circular arrays with modulo indexing
*/

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int file_nlines(string filename){

    std::ifstream fileIn;
    
    fileIn.open(filename.c_str());

    int n = 0;
    std::string str;

    if ( ! fileIn ) {
        cout << "Error: Can't open the file named data.txt.\n";
        exit(1);
    }

    while(fileIn){
        getline(fileIn, str);
        n++;
    }

    fileIn.close();
    return n;
}


void print_K_last(string filename, int K){

    if (K==0) return;

    int n = file_nlines(filename);

    std::cout << n << endl;

    std::ifstream fileIn;
    fileIn.open(filename.c_str());

    string str;

    while(fileIn){
        std::getline(fileIn, str);
        if(n<=K){
            std::cout << str << endl;
        }
        n--;
    }

    fileIn.close();
    return;
}

int main(){

    print_K_last("chap_12_c_and_c++/data.txt", 1);


    return 0;
}